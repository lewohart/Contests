#include "sip_register_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * sip_register_list_get_json(const char *line) {
	int line_size = (int)strlen(line) + 1;
	char *json = (char *)malloc(line_size * sizeof(char));
	strncpy_s(json, line_size, line, line_size);
	return json;
}

sip_register_list * sip_register_list_create_node(const char *line) {
	sip_register_list *node = (sip_register_list *)malloc(sizeof(sip_register_list));
	node->json = sip_register_list_get_json(line);
	node->next = NULL;
	return node;
}

/* Don't free json content. Be careful for external use. */
void sip_register_list_free(sip_register_list *this_) {
	while (this_ != NULL) {
		sip_register_list *next = this_->next;
		free(this_);
		this_ = next;
	}
}

int sip_register_compare(const void * r, const void * l) {
	sip_register *right = (sip_register *)r, *left = (sip_register *)l;

	return right->aor_length != left->aor_length ?
		right->aor_length - left->aor_length :
		strncmp(right->addressOfRecord, left->addressOfRecord, right->aor_length);
}

sip_register * sip_registers_list_create_sip_register_ordered_array(sip_register_list *this_, int count) {
	sip_register *result = (sip_register *)malloc(count * sizeof(sip_register));
	sip_register_list *curr = this_;

	for (int i = 0; curr != NULL; ++i) {
		result[i].json = curr->json;
		result[i].addressOfRecord = result[i].json + SIP_ADDRESS_OF_RECORD_POSITION;
		result[i].aor_length = (int)(strchr(result[i].addressOfRecord, '\"') - result[i].addressOfRecord);
		curr = curr->next;
	}

	qsort(result, count, sizeof(sip_register), sip_register_compare);
	return result;
}

sip_register * sip_register_fread(FILE *file, int *count) {
	char buffer[1025];
	sip_register_list *head = NULL, *curr = NULL;
	*count = 0;

	while (!feof(file)) {
		char *line = fgets(buffer, 1024, file);

		if (line != NULL) {
			sip_register_list *next = sip_register_list_create_node(line);

			if (head == NULL)
				head = next;

			if (curr != NULL)
				curr->next = next;

			curr = next;
			++(*count);
		}
	}

	sip_register *result = sip_registers_list_create_sip_register_ordered_array(head, *count);
	sip_register_list_free(head);

	return result;
}
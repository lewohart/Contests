#include "string_buffer.h"

#include <stdlib.h>
#include <string.h>

const char string_buffer_empty[] = "";

struct string_buffer_node_t {
	char *chunk;
	int length;
	struct string_buffer_node_t *next;
};

typedef struct string_buffer_node_t string_buffer_node;

inline int string_is_empty_or_null(const char *str) {
	return str == NULL || str[0] == '\0';
}

string_buffer_node *string_buffer_create_node(const char *str) {
	string_buffer_node *result = (string_buffer_node *)malloc(sizeof(string_buffer_node));
	result->next = NULL;

	if (string_is_empty_or_null(str)) {
		result->length = 0;
		result->chunk = NULL;
	}
	else {
		result->length = (int)strlen(str);
		result->chunk = (char *)malloc(sizeof(char) * (result->length + 1));
		strncpy_s(result->chunk, result->length + 1, str, result->length);
	}

	return result;
}

string_buffer * string_buffer_create() {
	string_buffer *sb = (string_buffer *)malloc(sizeof(string_buffer));
	sb->length = 0;
	sb->head = string_buffer_create_node(NULL);
	sb->current = sb->head;
	return sb;
}

void string_buffer_free(string_buffer *self) {
	string_buffer_node *curr = self->head, *next;

	do {
		next = curr->next;
		free(curr->chunk);
		free(curr);
	} while ((curr = next) != NULL);

	free(self);
}

void string_buffer_append(string_buffer *self, const char *str) {
	if (string_is_empty_or_null(str))
		return;

	string_buffer_node *node = string_buffer_create_node(str);

	if (self->current != NULL)
		((string_buffer_node *)self->current)->next = node;

	((string_buffer_node *)self->current) = node;

	self->length += node->length;

}

inline char * string_buffer_concatenate_and_free(string_buffer *self) {
	string_buffer_node *curr = self->head, *next;
	char * str = (char *)malloc(self->length + 1);
	int pos = 0;

	do {
		memcpy(str + pos, curr->chunk, curr->length);
		pos += curr->length;
		next = curr->next;

		free(curr->chunk);
		free(curr);
	} while ((curr = next) != NULL);

	str[self->length] = '\0';
	return str;
}

const char * string_buffer_to_string(string_buffer *self) {
	if (self->length == 0)
		return (const char *)string_buffer_empty;
	
	int has_only_one_node = ((string_buffer_node *)self->head)->next == NULL;
	
	if (has_only_one_node)
		return ((string_buffer_node *)self->head)->chunk;

	string_buffer_node *head = (string_buffer_node *)malloc(sizeof(string_buffer_node));
	head->chunk = string_buffer_concatenate_and_free(self);
	head->length = self->length;
	head->next = NULL;

	/* Bring all content to head node. */
	self->head = head;
	self->current = self->head;

	return head->chunk;
}
#include "sip_register.h"
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <search.h>

int sip_register_compare_aor(void *l, const void * k, const void * r) {
	int key_length = *(int *)l;
	char *key = (char *)k;
	sip_register *reg = (sip_register *)r;

	return key_length != reg->aor_length ?
		key_length - reg->aor_length :
		strncmp(key, reg->addressOfRecord, key_length);
}

const char * sip_register_get_json(sip_register *this_, int count, const char *key) {
	int length = (int) strlen(key);
	sip_register * reg = (sip_register *)bsearch_s(key, this_, count, sizeof(sip_register), sip_register_compare_aor, &length);
	/*If an AOR cannot be found, the server returns an empty line.*/
	return reg != NULL ? reg->json : "\n";
}

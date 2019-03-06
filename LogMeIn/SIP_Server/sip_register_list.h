#ifndef __SIP_REGISTER_LIST_H_
#define __SIP_REGISTER_LIST_H_

#include "sip_register.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


struct sip_register_list_t {
	char *json;
	struct sip_register_list_t *next;
};

typedef struct sip_register_list_t sip_register_list;

sip_register * sip_register_fread(FILE *file, int *count);

const char * sip_register_get_json(sip_register *this_, int count, const char *key);

#ifdef __cplusplus
}
#endif

#endif /* __SIP_REGISTER_LIST_H_ */

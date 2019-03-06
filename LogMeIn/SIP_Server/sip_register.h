#ifndef __SIP_REGISTER_H_
#define __SIP_REGISTER_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SIP_ADDRESS_OF_RECORD_POSITION 20

struct sip_register_t {
	char *addressOfRecord;
	int aor_length;
	char *json;
};

typedef struct sip_register_t sip_register;

#ifdef __cplusplus
}
#endif

#endif /* __SIP_REGISTER_H_ */
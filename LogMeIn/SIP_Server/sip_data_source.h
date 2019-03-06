#ifndef __SIP_DATA_SOURCE_H_
#define __SIP_DATA_SOURCE_H_

#include "sip_register.h"

#ifdef __cplusplus
extern "C" {
#endif

struct sip_data_source_t {
	sip_register * registers;
	int length;
};

typedef struct sip_data_source_t sip_data_source;

sip_data_source * sip_data_source_open(char *filename);

void sip_data_source_close(sip_data_source *this_);

#ifdef __cplusplus
}
#endif

#endif /* __SIP_DATA_SOURCE_H_ */
#ifndef __SIP_SERVER_H_
#define __SIP_SERVER_H_

#include "sip_register.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
	The program will start listening on a TCP socket.
	When a client connects, it can make lookup requests. 
	It sends one AOR per line. The server responds with the corresponding JSON object.
*/
int server_start(sip_data_source * data_source);

#ifdef __cplusplus
}
#endif

#endif /* __SIP_SERVER_H_ */

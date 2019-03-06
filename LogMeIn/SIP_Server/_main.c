#include "sip_data_source.h"
#include "sip_server.h"

int main(int argc, char* argv[]) {
	sip_data_source *data_source = sip_data_source_open(argv[1]);
	server_start(data_source);
	sip_data_source_close(data_source);

	return 0;
}
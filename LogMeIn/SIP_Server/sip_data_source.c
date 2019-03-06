#include "sip_data_source.h"
#include "sip_register_list.h"

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0

void exit_on_error(int error, const char *msg) {
	if (error != FALSE) {
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

sip_data_source * sip_data_source_open(char *filename) {
	FILE *file = NULL;
	fopen_s(&file, filename, "r");
	exit_on_error(file == NULL, "File open error");

	sip_data_source *result = (sip_data_source *)malloc(sizeof(sip_data_source));
	result->registers = sip_register_fread(file, &result->length);
	fclose(file);

	exit_on_error(result->registers == NULL || result->length == 0, "Invalid input");

	return result;
}

void sip_data_source_close(sip_data_source *this_) {
	for (int i = 0; i < this_->length; ++i)
		free(this_->registers[i].json);

	free(this_->registers);
	free(this_);
}
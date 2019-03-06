#ifndef __STRING_BUFFER_H_
#define __STRING_BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

struct string_buffer_t {
	int length;
	void *head;
	void *current;
};

typedef struct string_buffer_t string_buffer;

string_buffer * string_buffer_create();
void string_buffer_free(string_buffer *);
void string_buffer_append(string_buffer *, const char *);
const char * string_buffer_to_string(string_buffer *);

#ifdef __cplusplus
}
#endif

#endif /* __STRING_BUFFER_H_ */


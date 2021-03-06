#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "string_buffer.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_BUFLEN 100
#define PORT "32032"

inline void exit_on_error(int error, const char *msg) {
	if (error == TRUE) {
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

inline void clean_exit_on_error(int error, const char *msg) {
	if (error == TRUE) {
		perror(msg);
		WSACleanup();
		exit(EXIT_FAILURE);
	}
}

string_buffer *request_sip(SOCKET sock, const char * key, string_buffer *output) {
	int len = (int)strlen(key);
	int result = send(sock, key, len + 1, 0);
	exit_on_error(result == SOCKET_ERROR, "send");

	int received;
	char buffer[DEFAULT_BUFLEN + 1];

	for(;;) {
		received = recv(sock, buffer, DEFAULT_BUFLEN, 0);

		if (received <= 0)
			break;

		buffer[received] = '\0';
		string_buffer_append(output, buffer);

		int is_last_chunck = buffer[received - 1] == '\0';

		if (is_last_chunck)
			break;
	}

	return output;
}

SOCKET get_socket_connection(struct addrinfo *info) {
	SOCKET sock = INVALID_SOCKET;

	for (struct addrinfo *pai = info; pai != NULL; pai = pai->ai_next) {
		sock = socket(pai->ai_family, pai->ai_socktype, pai->ai_protocol);
		exit_on_error(sock == INVALID_SOCKET, "socket");

		int result = connect(sock, pai->ai_addr, (int)pai->ai_addrlen);

		if (result != SOCKET_ERROR)
			break;

		closesocket(sock);
		sock = INVALID_SOCKET;
	}

	return sock;
}

SOCKET open_connection(const char *address, const char * port) {
	WSADATA wsa;
	int result = WSAStartup(MAKEWORD(2, 2), &wsa);
	exit_on_error(result != 0, "WSAStartup");

	struct addrinfo *info = NULL, hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	result = getaddrinfo(address, port, &hints, &info);
	clean_exit_on_error(result != 0, "getaddrinfo");

	SOCKET sock = get_socket_connection(info);
	freeaddrinfo(info);

	clean_exit_on_error(sock == INVALID_SOCKET, "Unable to connect");

	return sock;
}

void close_connection(SOCKET sock) {
	int unused = shutdown(sock, SD_SEND);
	closesocket(sock);
	WSACleanup();
}

int main(int argc, char *argv[]) {
	/* Wait server loading... */
	Sleep(2000);

	SOCKET sock = open_connection("127.0.0.1", PORT);

	extern char *address_of_register[];
	for (int i = 0; address_of_register[i] != NULL; ++i) {
		string_buffer *output = string_buffer_create();
		request_sip(sock, address_of_register[i], output);
		const char *json = string_buffer_to_string(output);		
		puts(json);		
		string_buffer_free(output);
	}

	Sleep(20000);

	close_connection(sock);
	
	return 0;
}


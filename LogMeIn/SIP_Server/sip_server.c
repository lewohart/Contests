#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ws2tcpip.h>
#include <process.h>

#include "sip_register.h"
#include "sip_register_list.h"
#include "sip_data_source.h"

#define PORT "32032"
#define BACKLOG 10 

struct sip_server_handle_client_arguments_t {
	SOCKET socket;
	sip_data_source *data_source;
};

typedef struct sip_server_handle_client_arguments_t sip_server_handle_client_arguments;

inline void sip_server_exit_on_error(int error, const char *msg) {
	if (error == TRUE) {
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

inline void sip_server_clean_exit_on_error(int error, const char *msg) {
	if (error == TRUE) {
		perror(msg);
		WSACleanup();
		exit(EXIT_FAILURE);
	}
}

void sip_server_handle_client(void *args_) {
	sip_server_handle_client_arguments * args = (sip_server_handle_client_arguments *)args_;

	for (;;) {
		fd_set in_set;
		struct timeval timeout;
		timeout.tv_sec = 10;
		timeout.tv_usec = 0;

		FD_ZERO(&in_set);
		FD_SET(args->socket, &in_set);

		int unused = select((int)args->socket + 1, &in_set, NULL, NULL, &timeout);
		int result = FD_ISSET((args->socket), &in_set);
		int connection_timeout = result == 0 ? TRUE : FALSE;

		/* If a TCP connection is inactive for more than 10 seconds, the server closes it. */
		if (connection_timeout == TRUE) {
			printf("Client timeout\n");
			break;
		}

		char key[256];
		int received = recv(args->socket, key, 255, 0);

		if (received == 0)
			continue;

		if (received < 0) {
			perror("recv");
			break;
		}

		const char *json = sip_register_get_json(args->data_source->registers, args->data_source->length, key);
		send(args->socket, json, (int)strlen(json) + 1, 0);
	}

	closesocket(args->socket);
	free(args);
}

void sip_server_create_client_connection(sip_server_handle_client_arguments * args) {
	uintptr_t client_handler = _beginthread(sip_server_handle_client, 0, args);

	if (client_handler == -1) {
		fprintf(stderr, "Create thread failure: %d\n", GetLastError());
		closesocket(args->socket);
		free(args);
	}
}

void sip_server_handle_connections(SOCKET sock, sip_data_source *data_source) {
	struct sockaddr_in their_addr;
	int sockaddr_size = sizeof(struct sockaddr);

	for (;;) {
		void * buffer = malloc(sizeof(sip_server_handle_client_arguments));
		sip_server_handle_client_arguments *args = (sip_server_handle_client_arguments *)buffer;

		do {
			memset(&their_addr, 0, sizeof(struct sockaddr));
			args->socket = accept(sock, (struct sockaddr *)&their_addr, &sockaddr_size);
		} while (args->socket == INVALID_SOCKET);

		char client[INET_ADDRSTRLEN + 1];
		inet_ntop(AF_INET, &(their_addr.sin_addr), client, INET_ADDRSTRLEN);
		printf("Connection (%d) %s:%d\n", (int)args->socket, client, ntohs(their_addr.sin_port));

		args->data_source = data_source;
		sip_server_create_client_connection(args);
	}
}

SOCKET create_socket(const char *port) {
	struct addrinfo hints, *info;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	int result = getaddrinfo(NULL, port, &hints, &info);
	sip_server_exit_on_error(result != 0, "getaddrinfo");

	SOCKET sock = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
	sip_server_clean_exit_on_error(sock == INVALID_SOCKET, "socket");

	int reuseaddr = 1;
	result = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuseaddr, sizeof(int));
	sip_server_clean_exit_on_error(result == SOCKET_ERROR, "setsockopt");

	result = bind(sock, info->ai_addr, (int)info->ai_addrlen);
	sip_server_clean_exit_on_error(result == SOCKET_ERROR, "bind");

	freeaddrinfo(info);

	result = listen(sock, BACKLOG);
	sip_server_clean_exit_on_error(result == SOCKET_ERROR, "listen");

	return sock;
}

int server_start(sip_data_source *data_source) {
	WORD version = MAKEWORD(2, 2);
	WSADATA wsa;
	int result = WSAStartup(version, &wsa);
	sip_server_exit_on_error(result != 0, "WSAStartup");

	SOCKET socket = create_socket(PORT);
	sip_server_handle_connections(socket, data_source);

	closesocket(socket);
	result = WSACleanup();

	return result;
}


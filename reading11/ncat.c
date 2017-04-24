/* echo_client.c: simple TCP echo client */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

const char *HOST = "localhost";
const char *PORT = "9422";

int main(int argc, char *argv[]) {
    /* Lookup server address information */
    const char *HOST = argv[1];
    const char *PORT = argv[2];
    struct addrinfo *results;
    struct addrinfo  hints = {
        .ai_family   = AF_UNSPEC,   /* Return IPv4 and IPv6 choices */
        .ai_socktype = SOCK_STREAM, /* Use TCP */
    };
    if (getaddrinfo(HOST, PORT, &hints, &results) < 0) {
	perror("getaddrinfo failed: ");
        return EXIT_FAILURE;
    }

    /* For each server entry, allocate socket and try to connect */
    int client_fd = -1;
    for (struct addrinfo *p = results; p != NULL && client_fd < 0; p = p->ai_next) {
	/* Allocate socket */
	if ((client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
	    perror("Unable to make socket : ");
            continue;
	}

	/* Connect to host */
	if (connect(client_fd, p->ai_addr, p->ai_addrlen) < 0) {
	    perror("Unable to connect");
	    close(client_fd);
	    client_fd = -1;
	    continue;
	}
    }

    /* Release allocate address information */
    freeaddrinfo(results);

    if (client_fd < 0) {
    	return EXIT_FAILURE;
    }

    /* Open file stream from socket file descriptor */
    FILE *client_file = fdopen(client_fd, "w+");
    if (client_file == NULL) {
        perror("Unable to fdopen: ");
        close(client_fd);
        return EXIT_FAILURE;
    }

    /* Read from stdin and send to server */
    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, stdin)) {
        fputs(buffer, client_file);
    }

    fflush(client_file);

    close(client_fd);

    return EXIT_SUCCESS;
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */

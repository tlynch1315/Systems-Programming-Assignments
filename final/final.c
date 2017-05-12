#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

const char *HOST = "xavier.h4x0r.space";
//char *  message = "PUT tlynch2";
//const char *PORT = "9422";

FILE *socket_dial(const char *host, const char *port) {
    /* Lookup server address information */
    struct addrinfo *results;
    struct addrinfo  hints = {
        .ai_family   = AF_UNSPEC,   /* Return IPv4 and IPv6 choices */
        .ai_socktype = SOCK_STREAM, /* Use TCP */
    };
    int status;
    if ((status = getaddrinfo(host, port, &hints, &results)) != 0) {
    	fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(status));
	return NULL;
    }

    /* For each server entry, allocate socket and try to connect */
    int client_fd = -1;
    for (struct addrinfo *p = results; p != NULL && client_fd < 0; p = p->ai_next) {
	/* Allocate socket */
	if ((client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
	    fprintf(stderr, "Unable to make socket: %s\n", strerror(errno));
	    continue;
	}


	/* Connect to host */
	if (connect(client_fd, p->ai_addr, p->ai_addrlen) < 0) {
	    fprintf(stderr, "Unable to connect to %s:%s: %s\n", host, port, strerror(errno));
	    close(client_fd);
	    client_fd = -1;
	    continue;
	}
        /*struct stat s;
        stat("final.c", s);


        char buffer[BUFSIZ];
        fgets(buffer, BUFSIZ, stdin);
        send(client_fd, buffer, strlen(buffer), 0);*/
    }

    /* Release allocate address information */
    freeaddrinfo(results);

    if (client_fd < 0) {
    	return NULL;
    }

    /* Open file stream from socket file descriptor */
    FILE *client_file = fdopen(client_fd, "w+");
    if (client_file == NULL) {
        fprintf(stderr, "Unable to fdopen: %s\n", strerror(errno));
        close(client_fd);
        return NULL;
    }

    return client_file;
}

int main(int argc, char *argv[]) {
    /* Connect to remote machine */
    //FILE *client_file = socket_dial(HOST, PORT);

    //if (client_file == NULL) {
        //return EXIT_FAILURE;
    //}
    //char * message = "PUT tlynch";
    // the port was found using the port scanner, then hard coded
    FILE * client_fd = socket_dial(HOST, "9776");
    if(client_fd != NULL){
        printf("9776 is open\n");
    }

   /* FILE *s;
    FILE *pf;
    unsigned long filesize;
    pf = fpoen("final.c", "rb");
    for (int port = 9700; port < 9800; port++) {
        char buffer[BUFSIZ];
        sprintf(buffer, "%d", port);
        //FILE *s;
        s =  socket_dial(HOST, buffer); // socket_dial takes a char*, not an int, for 2nd arg*/
    if (client_fd != NULL) {
        FILE *temp;
        unsigned long filesize;
        char buff[BUFSIZ];
        temp = fopen("final.c", "rb");
        if(temp == NULL){
            printf("File not found\n");
            return 1;
        }
        else{
            fseek(temp, 0, SEEK_END);
            filesize = ftell(temp);
            rewind(temp);
            char buffer[BUFSIZ];
            sprintf(buffer, "PUT tlynch2 %ld\n", filesize);
            fputs(buffer, client_fd);
        }
        while(!feof(temp)){
            fputs(buff, client_fd);
        }                
    
        fclose(temp);
        fclose(client_fd);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;

}


    /* Read from stdin and send to server */
    /*char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, stdin)) {
        fputs(buffer, client_fd);
        fgets(buffer, BUFSIZ, client_fd);
        fputs(buffer, stdout);
    }*/


/* OPTIONAL QUESTIONS */

/* If I were a unix util I would be sleep.exe because I need to sleep more
 *
 * My favorite part about this class was the guru points because it made my grade go up so much 
 *
 * My least favorite part about this class(only thing I did not like pretty much) was this final
 *
 */




/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */

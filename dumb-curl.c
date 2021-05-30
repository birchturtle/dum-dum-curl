#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAXRVCLEN 1024

int main (int argc, char *argv[]){
	if ( argc < 3) {
		printf("Error, missing URL and/or IP\n");
		exit(1);
	}
	char buffer[MAXRVCLEN];
	char *hostname;
	hostname = argv[1];
	printf("Requesting %s", hostname);
	
	char message[] = "GET / HTTP/1.1\r\nHost: ";
	strcat(message, hostname);        
	strcat(message, "\r\nAccept: */*\r\nUser-Agent: meFromC\r\nConnection: keep-alive\r\n\r\n");
	puts(message);
	
	struct sockaddr_in remote;
	int client_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (client_sock == -1)
    {
        printf("Failed to create socket, oooh....");
        exit(1);
    }
    bzero(&remote, sizeof(remote));
	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr = inet_addr(argv[2]);
	remote.sin_port = htons((uint16_t)80);

	 // connect the client socket to server socket 
    if (connect(client_sock, (struct sockaddr*)&remote, sizeof(remote)) != 0) {
        printf("connection with the server failed...\n"); 
        exit(0);
    } 
    else {
    	printf("connected to the server..\n");
    }

    // send data to server
    if (send(client_sock, message, strlen(message), 0) < 0) {
        printf("sending to the server failed...\n"); 
        exit(0); 
    } 
    else {
    	printf("data sent to the server..\n");
    }

    // receive from server
    bzero(buffer, sizeof(buffer));
    if (recv(client_sock, buffer, sizeof(buffer), 0) < 0) {
        printf("receiving from the server failed...\n"); 
        exit(0); 
    } 
    else {
    	printf("data sent to from server\n%s", buffer);
    }

    close(client_sock);
	return 0;
}

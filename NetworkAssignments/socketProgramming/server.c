#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(void) {
    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        printf("Failure to create socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(1111);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    int bindCode = bind(serverSocket, (struct sockaddr *) &sa, sizeof(sa));
    if (bindCode == -1) {
        printf("Failure to bind socket");
        exit(EXIT_FAILURE);
    }
    int listenCode = listen(serverSocket, 10);
    if (listenCode == -1) {
        printf("Failure to listen socket");
        exit(EXIT_FAILURE);
    }
    char buff[1024];
    for ( ; ; ) {
        int connectionSocket = accept(serverSocket, NULL, NULL);
        if (connectionSocket == -1) {
            printf("Failure to accept connection");
            exit(EXIT_FAILURE);
        }

        recv(connectionSocket, buff, 1024*sizeof(char), 0);
        printf("Received on server: %s\n", buff);
        char* msg = "SOme important message";
        send(connectionSocket, msg, strlen(msg), 0);

        int shutdownCode = shutdown(connectionSocket, SHUT_RDWR);
        if (shutdownCode == -1) {
            perror("shutdown failed");
            close(connectionSocket);
            close(serverSocket);
            exit(EXIT_FAILURE);
        }
        close(connectionSocket);
    }
}
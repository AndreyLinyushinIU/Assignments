#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <pthread.h>

char buffer[1024];
char msg[] = "A message";
char address[] = "192.168.31.54";
int portServer = 1111;
int portClient = 1112;

void *server(void *argv) {
    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        printf("Failure to create socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(portServer);
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
    int connectionSocket = accept(serverSocket, NULL, NULL);
    if (connectionSocket == -1) {
        printf("Failure to accept connection");
        exit(EXIT_FAILURE);
    }

    recv(connectionSocket, buffer, 1024*sizeof(char), 0);
    printf("Received on server: %s\n", buffer);

    int shutdownCode = shutdown(connectionSocket, SHUT_RDWR);
    if (shutdownCode == -1) {
        perror("shutdown failed");
        close(connectionSocket);
        close(serverSocket);
        exit(EXIT_FAILURE);
    }
    close(connectionSocket);
    pthread_exit(0);
}

void *client(void *argv) {
    int Socket = socket(PF_INET, SOCK_STREAM, 0);
    if (Socket == -1) {
        printf("socket creation error");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(portClient);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    int res = inet_pton(AF_INET, address, &sa.sin_addr);
    if (res <= 0) {
        printf("Address error");
        exit(EXIT_FAILURE);
    }
    int connectCode = connect(Socket, (struct sockaddr *)&sa, sizeof(sa));
    if (connectCode == -1) {
        printf("connection error");
        exit(EXIT_FAILURE);
    }
    send(Socket, msg, strlen(msg), 0);
    printf("Sent on client: %s\n", msg);

    close(Socket);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t server_pid, client_pid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&server_pid, &attr, server, *argv);
    sleep(2);
    pthread_create(&client_pid, &attr, client, *argv);

    pthread_join(server_pid, NULL);
    pthread_join(client_pid, NULL);
    return 0;
}
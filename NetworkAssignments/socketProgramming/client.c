#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(void) {

    char buff[1024];

    int Socket = socket(PF_INET, SOCK_STREAM, 0);
    if (Socket == -1) {
        printf("socket creation error");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(1111);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    //int res = inet_pton(AF_INET, "111.222.3.4", &sa.sin_addr);
    int connectCode = connect(Socket, (struct sockaddr *)&sa, sizeof(sa));
    if (connectCode == -1) {
        printf("connection error");
        exit(EXIT_FAILURE);
    }

    char* msg = "SOme important message";
    send(Socket, msg, strlen(msg), 0);
    recv(Socket, buff, 1024*sizeof(char), 0);
    printf("Received on server: %s\n", buff);

    close(Socket);
    return EXIT_SUCCESS;
}
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd = open("/dev/random", O_RDONLY);
    char *buff = malloc(20*sizeof(char));
    read(fd, buff, 20);
    printf("%s\n", buff);
    free(buff);
    return 0;
}

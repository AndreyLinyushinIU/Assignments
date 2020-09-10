#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char line[1024];
    do {
        printf(">>>:");
        fgets(line, 1024, stdin);
        if (strcmp(line, "close\n") == 0) return 0;
        system(line);
    } while(1);
}
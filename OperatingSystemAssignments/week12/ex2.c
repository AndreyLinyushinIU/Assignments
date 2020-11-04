#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int a = 0, ch;
    FILE **fd = (FILE**)malloc(argc * sizeof(FILE*));
    memset(fd, 0, argc * sizeof(FILE*));
    fd[0] = stdout;


    for (int i = 1; i < argc; i++)
        if (strcmp("-a", argv[i]) == 0) {
            a = 1;
            break;
        }


    for (int i = 1; i < argc; i++)
        if (strcmp("-a", argv[i]) != 0)
            fd[i] = fopen(argv[i], a ? "a" : "w");

    while((ch = getchar()) != EOF)
        for (int i = 0; i < argc; i++)
            if (fd[i]) putc(ch, fd[i]);

    for (int i = 1; i < argc; i++) if (fd[i]) fclose(fd[i]);
    return 0;
}

#include "unistd.h"
#include "fcntl.h"
#include "sys/mman.h"
#include "sys/stat.h"
#include "string.h"
#include "stdio.h"

struct stat buf;

int main() {
char *src = "This is a nice day";
int fl = open("ex1.txt", O_RDWR);
stat("ex1.txt", &buf);
lseek(fl, strlen(src)-1, SEEK_SET);
write(fl, "", 1);
char *str = mmap(0, strlen(src)-1, PROT_WRITE | PROT_READ, MAP_SHARED, fl, 0);
memcpy(str, src, strlen(src));
close(fl);
return 0;
}
#include "fcntl.h"
#include "sys/mman.h"
#include "sys/stat.h"
#include "unistd.h"
#include "string.h"

struct stat buf;

int main() {

int in = open("ex1.txt", O_RDONLY);
int out = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC);
stat("ex1.txt", &buf);
lseek(out, buf.st_size - 1, SEEK_SET);
write(out, "", 1);
char *dst = mmap(0, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, out, 0);
char *src = mmap(0, buf.st_size, PROT_READ, MAP_SHARED, in, 0);
memcpy(dst, src, buf.st_size);
return 0;
}
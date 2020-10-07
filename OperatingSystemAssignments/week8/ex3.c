#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
for (int i = 0; i < 10; i++) {
memset(malloc(1024*1024*10), 0, 1024*1024*10);
sleep(1);
}
return 0;
}
/*
after running "top -d 1" a line
"4889 andrey 20 0 43464 42016 1076 S 1,0 1,0 0:00.01 a.out"
was added into the total list with constantly increasing fields VIRT, RES, SHR and MEM
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
struct rusage *usage = malloc(sizeof(struct rusage));
for (int i = 0; i < 10; i++) {
memset(malloc(1024*1024*10), 0, 1024*1024*10);
getrusage(RUSAGE_SELF, usage);
printf("%ld\n", usage->ru_maxrss);
sleep(1);
}
return 0;
}
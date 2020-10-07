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
/* Before the start of the program on VM:
total used free shared buff/cache available
Mem: 3,8Gi 2,0Gi 293Mi 127Mi 1,6Gi 1,5Gi
Swap: 1,4Gi 14Mi 1,4Gi
Total: 5,2Gi 2,0Gi 1,6Gi
Then each second field "free" decreased by 10 Mi up to:
total used free shared buff/cache available
Mem: 3,8Gi 2,1Gi 193Mi 127Mi 1,6Gi 1,4Gi
Swap: 1,4Gi 14Mi 1,4Gi
Total: 5,2Gi 2,1Gi 1,5Gi
After all everything returned to initial stage
*/
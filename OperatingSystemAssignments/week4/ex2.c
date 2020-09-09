#include <unistd.h>
int main () {
for (int i = 0; i < 5; i++) fork();
sleep(5);
return 0;
}
/*
Using command pstree we can see 8 occurrences of this program:
a.out
|--------------|------|
a.out        a.out a.out
|-------|       |
a.out a.out  a.out
|
a.out
It happens so because child program continues execution from the next instruction
and after different calls of fork() the different number of lines of code left
When running "for" loop 5 times we'll see 32 processes
*/ 

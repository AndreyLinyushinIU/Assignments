#include <stdio.h>
#include <unistd.h>
int main () {
pid_t n = fork();
if (n > 0) printf("Hello from parent [PID - %d]\n", n);
else printf("Hello from child [PID - %d]\n", n);
return 0;
}
/*
Hello from parent [PID - 5261]
Hello from child [PID - 0]
Hello from parent [PID - 5263]
Hello from child [PID - 0]
Hello from parent [PID - 5265]
Hello from child [PID - 0]
Hello from parent [PID - 5267]
Hello from child [PID - 0]
Hello from parent [PID - 5269]
Hello from child [PID - 0]
Hello from parent [PID - 5271]
Hello from child [PID - 0]
Hello from parent [PID - 5273]
Hello from child [PID - 0]
Hello from parent [PID - 5275]
Hello from child [PID - 0]
Hello from parent [PID - 5277]
Hello from child [PID - 0]
Hello from parent [PID - 5279]
Hello from child [PID - 0]
This is result of executing this program 10 times, first the program prints come positive value - the id
of the child process, then it's child process prints 0 as it doesn't have its own child processes
*/

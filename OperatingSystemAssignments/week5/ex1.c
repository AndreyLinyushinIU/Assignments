#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* print() {
    printf("Thread number:%d\n", counter+1);
    counter++;
}

int main () {
    int n;
    printf("Enter the number of threads:");
    scanf("%d", &n);
    printf("\n");
    pthread_t thread;
    for (int i = 0; i < n; i++) {
        int prev_counter = counter;
        printf("Thread is created successfully\n");
        pthread_create(&thread, NULL, &print, NULL);
        while(counter == prev_counter) {}
    }
    pthread_join(thread, NULL);
    return 0;
}

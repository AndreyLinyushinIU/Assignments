#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *array;
    printf("Enter the length of the array: ");
    scanf("%d", &N);
    array = malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) array[i] = i;
    for (int i = 0; i < N; i++) printf("%d ", array[i]);
    free(array);
    return 0;
}

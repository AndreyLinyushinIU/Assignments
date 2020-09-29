#include <stdio.h>
#include <stdlib.h>

void *Realloc(void * ptr, int size) {
    if (ptr == NULL) return malloc(size);
    if (size < 1) {
        free(ptr);
        return NULL;
    }
    free(ptr);
    return malloc(size);
}

int main() {
    int n, *a;
    printf("Print the size of the array");
    scanf("%d", &n);
    a = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = i*2;
        printf("%d ",a[i]);
    }
    printf("\n");
    Realloc(a, n*2*sizeof(int));
    for (int i = 0; i < n*2; i++) {
        a[i] = i*3;
        printf("%d ", a[i]);
    }
    return 0;
}

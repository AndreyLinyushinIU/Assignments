#include <stdio.h>


void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int a, b;
    printf("Enter two integers ");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("Swapped: %d, %d\n", a, b);
    return 0;
}

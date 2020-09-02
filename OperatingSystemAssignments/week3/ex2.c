#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* bubble_sort(int* array_t, int size) {
    int *array = malloc(size*sizeof(int));
    memcpy(array, array_t, size*sizeof(int));
    char changed = 1;
    while(changed == 1) {
        changed = 0;
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                int t = array[i];
                array[i] = array[i + 1];
                array[i + 1] = t;
                changed = 1;
            }
        }
    }
    return array;
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = malloc(size*sizeof(int));
    printf("Enter the array:");
    for (int i = 0; i < size; i++) scanf("%d", &array[i]);
    array = bubble_sort(array, size);
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    free(array);
    return 0;
}
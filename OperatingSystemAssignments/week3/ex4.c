#include <stdio.h>
#include <stdlib.h>

int size, *array;

void swap(int index1, int index2) {
    int t = array[index1];
    array[index1] = array[index2];
    array[index2] = t;
}

void quickSort(int first, int last) {
    if (first < last) {
        int i = first, j = last, middle = array[(i + j) / 2];
        while (i <= j) {
            while (array[i] < middle) i++;
            while (array[j] > middle) j--;
            if (i <= j) {
                int tmp = array[i];
                array[i++] = array[j];
                array[j--] = tmp;
            }
        }
        quickSort(first, j);
        quickSort(i, last);
    }
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = malloc(size*sizeof(int));
    printf("Enter the array: ");
    for(int i = 0; i < size; i++) scanf("%d", &array[i]);
    quickSort(0, size - 1);
    printf("Resulting array: ");
    for (int i = 0; i < size; i++) printf("%d, ", array[i]);
    return 0;
}
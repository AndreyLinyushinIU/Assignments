#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* input = fopen("input_dl.txt", "r");
    FILE* output = fopen("output_dl.txt", "w");

    int processes, resources;
    fscanf(input, "%d %d", &resources, &processes);

    int *E = malloc(sizeof(int)*resources);
    int *A = malloc(sizeof(int)*resources);
    int *areFree = malloc(sizeof(int)*processes);
    int **C = malloc(sizeof(int)*processes*resources);
    int **R = malloc(sizeof(int)*processes*resources);

    for (int i = 0; i < resources; i++) fscanf(input, "%d", E + i);
    for (int i = 0; i < resources; i++) fscanf(input, "%d", A + i);
    for (int i = 0; i < processes; i++) areFree[i] = 0;

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            fscanf(input, "%d", (int*)(C + i*resources + j));

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            fscanf(input, "%d", (int*)(R + i*resources + j));

    int deadlock = 0, countFree;
    while(!deadlock) {
        deadlock = 1;
        for (int i = 0; i < processes; i++) {
            if (areFree[i] == 1) continue;
            int possible_to_remove = 1;
            for (int j = 0; j < resources; j++)
                if ((int)*(R + i*resources + j) > *(A + j)) possible_to_remove = 0;
            if (possible_to_remove) {
                *(areFree + i) = 1;
                deadlock = 0;
                for (int k = 0; k < resources; k++) {
                    *(A + k) += (int)*(C + i * resources + k);
                    *(R + i*resources + k) = 0;
                    *(C + i*resources + k) = 0;
                }
            }
        }
        countFree = processes;
        for (int i = 0; i < processes; i++)
            if (areFree[i] == 0) countFree--;
        if (countFree == processes) {
            deadlock = 0;
            break;
        }
    }

    if (processes != countFree) fprintf(output, "%d",  processes - countFree);
    else fprintf(output, "No deadlocks");

    fclose(input);
    fclose(output);
    return 0;
}
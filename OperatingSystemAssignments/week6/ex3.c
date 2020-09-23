#include <stdio.h>
#include <stdlib.h>

struct event { unsigned int arrive, duration, ID, burst; };
unsigned int nProcesses, currentTime = 0, quantum;
struct event *events;

int main () {
    printf("The number of processes: ");
    scanf("%d", &nProcesses);
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    events = malloc(nProcesses*sizeof(struct event));
    unsigned int nProcessesInitial = nProcesses;
    printf("Enter the arrival time and duration:\n");
    for (int i = 0; i < nProcesses; i++) {
        scanf("%d%d", &events[i].arrive, &events[i].duration);
        events[i].ID = i+1;
        events[i].burst = events[i].duration;
    }
    unsigned int totalTAT = 0, totalWT = 0;

    while (nProcesses > 0)
        for (int i = 0; i < nProcesses; i++)
            if (events[i].arrive <= currentTime)
                if (events[i].duration > quantum) {
                    events[i].duration -= quantum;
                    currentTime += quantum;
                } else {
                    currentTime += events[i].duration;
                    totalTAT += currentTime - events[i].arrive;
                    totalWT += currentTime - events[i].arrive - events[i].burst;
                    printf("ID: %d, CT: %d, TAT: %d, WT: %d\n", events[i].ID, currentTime,
                           currentTime - events[i].arrive, currentTime - events[i].arrive - events[i].burst);
                    for (unsigned int j = i; j < nProcesses-1; j++) events[j] = events[j+1];
                    nProcesses--;
                    i--;
                }

    printf("average TAT: %f, average WT: %f\n", (float)totalTAT/nProcessesInitial, (float)totalWT/nProcessesInitial);
    return 0;
}

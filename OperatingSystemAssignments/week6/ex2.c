#include <stdio.h>
#include <stdlib.h>

struct event { unsigned int arrive, duration, ID; };
unsigned int nProcesses, currentTime = 0;
struct event *events;

unsigned int getNextID() {
    int nextID = -1, minTime = -1, differenceTime = -1;
    for (int i = 0; i < nProcesses; i++)
        if (currentTime >= events[i].arrive && (minTime == -1 || minTime > events[i].duration)) {
                minTime = events[i].duration;
                nextID = i;
        } else if (nextID == -1 && (differenceTime == -1 || events[i].arrive - currentTime < differenceTime)) {
            differenceTime = events[i].arrive - currentTime;
            nextID = i;
        }
    if (minTime == -1) currentTime = events[nextID].arrive;
    return nextID;
}

int main () {
    printf("The number of processes: ");
    scanf("%d", &nProcesses);
    events = malloc(nProcesses*sizeof(struct event));
    unsigned int nProcessesInitial = nProcesses;
    printf("Enter the arrival time and duration:\n");
    for (int i = 0; i < nProcesses; i++) {
        scanf("%d%d", &events[i].arrive, &events[i].duration);
        events[i].ID = i+1;
    }
    unsigned int totalTAT = 0, totalWT = 0;

    while (nProcesses > 0) {
        unsigned int nextID = getNextID();
        currentTime += events[nextID].duration;
        printf("ID: %d, CT: %d, TAT: %d, WT: %d\n", events[nextID].ID, currentTime,
               currentTime - events[nextID].arrive, currentTime - events[nextID].arrive - events[nextID].duration);
        totalTAT += currentTime - events[nextID].arrive;
        totalWT += currentTime - events[nextID].arrive - events[nextID].duration;
        for (unsigned int i = nextID; i < nProcesses-1; i++) events[i] = events[i+1];
        nProcesses--;
    }

    printf("average TAT: %f, average WT: %f\n", (float)totalTAT/nProcessesInitial, (float)totalWT/nProcessesInitial);
    return 0;
}

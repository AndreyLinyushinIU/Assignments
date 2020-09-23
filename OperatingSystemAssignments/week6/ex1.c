#include <stdio.h>
#include <stdlib.h>

struct event { unsigned int arrive, duration, ID; };
unsigned int nProcesses, currentTime = 0;
struct event *events;

int comparator(const void *val1, const void *val2) {
    if (((struct event *)val1)->arrive > ((struct event *)val2)->arrive) return 1;
    else if (((struct event *)val1)->arrive < ((struct event *)val2)->arrive) return -1;
    return 0;
}

int main () {
    printf("The number of processes: ");
    scanf("%d", &nProcesses);
    events = malloc(nProcesses*sizeof(struct event));
    printf("Enter the arrival time and duration:\n");
    for (int i = 0; i < nProcesses; i++) {
        scanf("%d%d", &events[i].arrive, &events[i].duration);
        events[i].ID = i+1;
    }
    qsort(events, nProcesses, sizeof(struct event), comparator);

    unsigned int totalTAT = 0, totalWT = 0;

    for (int i = 0; i < nProcesses; i++) {
        if (currentTime < events[i].arrive) currentTime = events[i].arrive;
        currentTime = currentTime + events[i].duration;
        totalTAT += currentTime - events[i].arrive;
        totalWT += currentTime - events[i].arrive - events[i].duration;
        printf("ID: %d, CT: %d, TAT: %d, WT: %d\n", events[i].ID, currentTime,
               currentTime - events[i].arrive, currentTime - events[i].arrive - events[i].duration);
    }
    printf("average TAT: %f, average WT: %f\n", (float)totalTAT/nProcesses, (float)totalWT/nProcesses);

    return 0;
}
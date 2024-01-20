#include <stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5, 4, 7, 6, 4};
    int pageFaults = 0;
    int frames = 3;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 ");

    int temp[frames];
    int counter[3] = {0}; // Counter for tracking usage of each frame

    for (int i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    for (int i = 0; i < pages; i++) {
        int page = incomingStream[i];
        int pageFound = 0;

        printf("\n%d\t\t\t", page);

        for (int j = 0; j < frames; j++) {
            if (temp[j] == page) {
                pageFound = 1;
                counter[j] = 0; // Reset counter for the used frame
            } else {
                counter[j]++;
            }
        }

        if (!pageFound) {
            int lruIndex = 0;
            for (int j = 1; j < frames; j++) {
                if (counter[j] > counter[lruIndex]) {
                    lruIndex = j;
                }
            }
            temp[lruIndex] = page;
            counter[lruIndex] = 0; // Reset counter for the newly added frame
            pageFaults++;
        }

        for (int j = 0; j < frames; j++) {
            if (temp[j] != -1)
                printf(" %d\t\t\t", temp[j]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}

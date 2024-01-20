#include <stdio.h>

int findOptimal(int temp[], int incomingStream[], int n, int pages) {
    int res = -1, farthest = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = pages; j < pages; j++) {
            if (temp[i] == incomingStream[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pages)
            return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5, 4, 7, 6, 4};
    int pageFaults = 0;
    int frames = 3;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 ");

    int temp[frames];

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
            }
        }

        if (!pageFound) {
            int pos = findOptimal(temp, incomingStream, frames, i + 1);
            temp[pos] = page;
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

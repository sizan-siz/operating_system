#include<stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5, 4, 7, 6, 4};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 ");

    int temp[frames];

    // একটি খালি ফ্রেমের জন্য temp অ্যারেটি ইনিশিয়ালাইজ করা হচ্ছে
    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for (m = 0; m < pages; m++) {
        s = 0;

        for (n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++;
                pageFaults--;
            }
        }

        pageFaults++;

        // একটি নতুন পেজ যোগ করার জন্য এক্ষেত্রে
        if ((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        }
        // যদি পেজটি আগের ফ্রেমের মধ্যে না থাকে এবং সম্পূর্ণ ফ্রেমের পূর্ণতা না হয়
        else if (s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("\n");
        printf("%d\t\t\t", incomingStream[m]);

        for (n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}

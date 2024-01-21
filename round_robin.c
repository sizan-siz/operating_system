#include <stdio.h>

// Function to perform Round Robin scheduling
void roundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], remaining_time[n];
    
    // Initializing waiting time and remaining time
    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        remaining_time[i] = bt[i];
    }

    int time = 0; // Current time
    int done = 0; // Flag to check if all processes are done

    // Continue the loop until all processes are done
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                // Process i has remaining time
                if (remaining_time[i] > quantum) {
                    // Process i can be executed for a full quantum
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    // Process i will be completed
                    time += remaining_time[i];
                    wt[i] = time - bt[i];
                    remaining_time[i] = 0;
                    done++;
                }
            }
        }
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Display the results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and display average turnaround time and average waiting time
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    
    avg_wt /= n;
    avg_tat /= n;
    
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];

    // Input burst time for each process
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Perform Round Robin scheduling
    roundRobin(processes, n, burst_time, quantum);

    return 0;
}

#include <stdio.h>

int main() {
    int n, i, j, pos, temp;
    int bt[20], priority[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d (burst time and priority): ", i + 1);
        scanf("%d %d", &bt[i], &priority[i]);
    }

    // Sort processes by priority
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (priority[j] < priority[pos])
                pos = j;
        }
        // Swap burst time and priority
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        
        temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;
    }

    // Calculate waiting time
    wt[0] = 0;  // First process has no waiting time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Print results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], priority[i], wt[i], tat[i]);
    }

    // Calculate and print average times
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);

    return 0;
}

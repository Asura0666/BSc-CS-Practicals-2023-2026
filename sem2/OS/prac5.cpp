/*
    FCFS Scheduling
*/

#include <stdio.h>

int main() {
    char pn[10][10];
    int at[10], bt[10], start[10], finish[10], tat[10], wt[10];
    int i, n;
    int totwt = 0, tottat = 0;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter the process name, Arrival Time, Burst Time: ");
        scanf("%s %d %d", pn[i], &at[i], &bt[i]);
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            start[i] = at[i];
        } else {
            start[i] = finish[i - 1];
        }
        wt[i] = start[i] - at[i];
        finish[i] = start[i] + bt[i];
        tat[i] = finish[i] - at[i];
        totwt += wt[i];
        tottat += tat[i];
    }

    printf("\nPname ArrivalTime BurstTime Start TAT Finish");

    for (i = 0; i < n; i++) {
        printf("\n%s\t%6d\t%6d\t%6d\t%6d\t%6d", pn[i], at[i], bt[i], start[i], tat[i], finish[i]);
    }

    printf("\nAverage Waiting time: %.2f", (float) totwt / n);
    printf("\nAverage Turnaround time: %.2f", (float) tottat / n);

    return 0;
}


/*

Output:

Enter the number of processes: 3
Enter the process Name, Arrival Time & Burst Time: p1 0 24
Enter the process Name, Arrival Time & Burst Time: p2 0 3
Enter the process Name, Arrival Time & Burst Time: p3 0 3

PName	Arrtime	BurstTime	Start	TAT	Finish
p1	     0	    24	     0	    24	    24
p2	     0	     3	    24	    27	    27
p3	     0	     3	    27	    30	    30

Average Waiting time: 17.00
Average Turn Around time: 27.00

*/
//8.1

#include <stdio.h>

int main() {
    int alloc[10][10], max[10][10], avail[10], work[10], need[10][10];
    int i, j, k, n, m, count = 0;
    char finish[10];

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter the claim matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the resource vector:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int safe = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        safe = 0;
                        break;
                    }
                }
                if (safe) {
                    printf("Process %d can execute\n", i);
                    finish[i] = 1;
                    count++;
                    found = 1;
                    for (j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }
                    break;
                }
            }
        }
        if (!found) {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("System is in safe state\n");

    return 0;
}


//8.2

#include <stdio.h>

int main() {
    char job[10][10];
    int time[10], avail, temp[10];
    int safe[10], ind, i, j, t;

    printf("Enter no of jobs: ");
    scanf("%d", &ind);

    for(i = 0; i < ind; i++) {
        printf("Enter name and time: ");
        scanf("%s%d", job[i], &time[i]);
    }

    printf("Enter the available resources: ");
    scanf("%d", &avail);

    // Create a temporary copy of the execution times
    for(i = 0; i < ind; i++) {
        temp[i] = time[i];
    }

    // Sort the jobs based on their execution times
    for(i = 0; i < ind; i++) {
        for(j = i + 1; j < ind; j++) {
            if(temp[i] > temp[j]) {
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Initialize the safe sequence index
    int safe_count = 0;

    // Iterate through the sorted jobs
    for(i = 0; i < ind; i++) {
        // Check if the execution time of the job is less than the available resources
        if(temp[i] <= avail) {
            // Add the job to the safe sequence
            safe[safe_count++] = i;
            // Update the available resources
            avail -= temp[i];
        } else {
            // If the job cannot be executed due to insufficient resources, break the loop
            printf("No safe sequence\n");
            return 0;
        }
    }

    // If all jobs can be executed safely, print the safe sequence
    printf("Safe sequence is: ");
    for(i = 0; i < safe_count; i++) {
        printf("%s ", job[safe[i]]);
    }
    printf("\n");

    return 0;
}

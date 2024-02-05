//8.1

#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    int alloc[10][10], max[10][10], avail[10], work[10], total[10], need[10][10];
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
        scanf("%d", &total[i]);
    }

    for (i = 0; i < m; i++) {
        avail[i] = 0;
        for (j = 0; j < n; j++) {
            avail[i] += alloc[j][i];
        }
    }

    for (i = 0; i < n; i++) {
        work[i] = 0;
        for (j = 0; j < m; j++) {
            work[i] += alloc[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    A:
    for (i = 0; i < n; i++) {
        if (need[i][i] < 0 && finish[i] == 'n') {
            for (j = 0; j < m; j++) {
                if (avail[j] >= need[i][j]) {
                    avail[j] -= need[i][j];
                    work[i] += need[i][j];
                    need[i][j] = 0;
                    break;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (need[i][i] < 0 && finish[i] == 'n') {
            printf("\nAll the resources can be allocated to Process %d\n", i + 1);
            printf("Available resources are:\n");
            for (k = 0; k < m; k++) {
                printf("%4d", work[k] + alloc[i][k]);
            }
            printf("\n");
            finish[i] = 'y';
            printf("\nProcess %d executed?: %c\n", i + 1, finish[i]);
            count++;
            if (count != n) {
                goto A;
            } else {
                printf("\nSystem is in safe mode\n");
                printf("The given state is safe state\n");
            }
        }
    }

    getch();
}


//8.2

#include <stdio.h>
#include <conio.h>

void main() {
    char job[10][10];
    int time[10], avail, tem[10], temp[10];
    int safe[10], ind = 1, i, j, t;
    // clrscr();

    printf("Enter no of jobs: ");
    scanf("%d", &ind);

    for(i = 0; i < ind; i++) {
        printf("Enter name and time: ");
        scanf("%s%d", &job[i], &time[i]);
    }

    printf("Enter the available resources: ");
    scanf("%d", &avail);

    for(i = 0; i < ind; i++) {
        temp[i] = time[i];
        tem[i] = time[i];
    }

    for(i = 0; i < ind; i++) {
        for(j = i + 1; j < ind; j++) {
            if(tem[i] > tem[j]) {
                t = tem[i];
                tem[i] = tem[j];
                tem[j] = t;

                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    for(i = 0; i < ind; i++) {
        if(time[i] < avail) {
            safe[i] = i;
            avail -= tem[i];
        } else {
            for(j = 0; j < ind; j++) {
                if(temp[j] < tem[i])
                    break;
                if(temp[j] > tem[i] && temp[j] < avail) {
                    temp[j] = temp[j] - tem[i];
                    tem[i] = 0;
                    break;
                }
            }
            if(tem[i] != 0) {
                printf("No safe sequence\n");
                break;
            }
        }
    }

    if(tem[ind - 1] == 0) {
        printf("Safe sequence is: ");
        for(i = 0; i < ind; i++)
            printf(" %s %d\n", job[safe[i]], time[safe[i]]);
    } else {
        printf("No safe sequence\n");
    }

    getch();
}


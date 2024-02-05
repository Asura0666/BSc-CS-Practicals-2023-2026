
// 6.2

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pno;
    int pri;
    int btime;
    int wtime;
} process;

int main() {
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    process *p = (process *)malloc(sizeof(process) * n);

    printf("\n PRIORITY SCHEDULING.\n");
    printf("\n enter the number of process: ");
    scanf("%d", &n);

    p = (process *)malloc(sizeof(process) * n);
    printf("enter the burst time and priority: \n");
    for(i = 0; i < n; i++) {
        printf("process%d: ", i+1);
        scanf("%d%d", &p[i].btime, &p[i].pri);
        p[i].pno = i+1;
        p[i].wtime = 0;
    }

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i].pri > p[j].pri) {
                process t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    printf("\nprocess\tbursttime\twaiting time\tturnaround time\n");
    for(i = 0; i < n; i++) {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("\n%d\t\t%d",p[i].pno,p[i].btime);
        printf("\t\t%d\t\t%d",p[i].wtime, p[i].wtime + p[i].btime);
    }

    totttime = tbm + totwtime;
    printf("\n total waiting time:%d",totwtime);
    printf("\n average waiting time: %.2f", (float)totwtime/n);
    printf("\n total turnaround time:%d",totttime);
    printf("\n avg turnaround time: %.2f",(float)totttime/n);

    return 0;
}

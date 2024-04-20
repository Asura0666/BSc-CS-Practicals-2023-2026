/*
  Round Robin Scheduling
*/

#include <stdio.h>

struct process {
  int burst, wait, comp, f;
} p[20] = {0,0};

int main() {
  int n,j,i;
  int totalwait = 0, totalTurn = 0, quantum, flag = 1, time = 0;

  printf("\nEnter number of process: ");
  scanf("%d", &n);

  printf("\nEnter the quantum time(in ms): ");
  scanf("%d", &quantum);

  for(i=0; i<n; i++) {
    printf("\nEnter the burst time (in ms): ");
    scanf("%d", &p[i].burst);
    p[i].f = 1;
  }

  printf("\nOrder of execution");
  printf("\nProcess\t\tstaring\tending\tremaining");
  printf("\n\t\tTime\tTime\tTime");

  while(flag == 1) {
    flag = 0;
    for(i=0; i<n; i++) {
      if(p[i].f == 1) {
        flag = 1;
        j = quantum;
        if((p[i].burst - p[i].comp) > quantum) {
          p[i].comp += quantum;
        } else {
          p[i].wait = time - p[i].comp;
          j = p[i].burst - p[i].comp;
          p[i].f = 0;
        }
        printf("\nProcess #%d\t%d\t%d\t%d", i+1, time, time + j, p[i].burst - p[i].comp );
        time += j;
      }
    }
  }

  printf("\n\n -------------------");
  printf("\nProcess\t\twaitingTimme\tTurnAroundTime");
  for(i=0; i<n; i++) {
    printf("\nProcess#%d\t%d\t\t%d", i+1, p[i].wait, p[i].wait+p[i].burst);
    totalwait += p[i].wait;
    totalTurn += p[i].wait + p[i].burst;
  }

  printf("\n\n Average\n--------------");
  printf("\nWaiting Time: %fms",totalwait/(float)n);
  printf("\nTurnAround time: %fms",totalTurn/(float)n);
  return 0;
}
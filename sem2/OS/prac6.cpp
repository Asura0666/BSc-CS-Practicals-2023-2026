#include <stdio.h>
#include <string.h>

int main() {
  int bt[10], wt[10], tat[10], pn[10];
  int i,j,n,temp;
  float totwt= 0, tottat = 0;

  printf("\nEnter the number of process: ");
  scanf("%d", &n);

  for(i=0; i<n; i++) {
    printf("\nEnter the process number and burst time: ");
    scanf("%d %d", &pn[i], &bt[i]);
  }

  for(i=0; i<n-1; i++) {
    for(j=i+1; j<n; j++) {
      if(bt[i] > bt[j]) {
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = pn[i];
        pn[i] = pn[j];
        pn[j] = temp;
      }
    }
  }

  wt[0] = 0;
  for(i=1; i<n; i++) {
    wt[i] = bt[i-1] + wt[i-1];
    totwt += wt[i];
  }

  for(i=0; i<n; i++) {
    tat[i] = bt[i] + wt[i];
    tottat += tat[i];
  }

  printf("\nProcess no. burstTime waitingTime turnAroundTime");

  for(i=0; i<n; i++) {
    printf("\n%d\t%d\t%d\t%d", pn[i], bt[i], wt[i], tat[i]);
  }

  printf("\nAvg waiting Time: %f", totwt/n);
  printf("\nAvg turn Around Time: %f", tottat/n);

  return 0;
}


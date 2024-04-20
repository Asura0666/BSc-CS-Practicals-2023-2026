/*
  Priority Scheduling
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct
{
    int pno,pri,btime,wtime;
    
}
sp;
int main()
{
    int i,j,n;
    int tbm=0,totwtime=0,totttime=0;
    sp*p,t;
    printf("\nPriority scheduling \n");
    printf("\n enter the number of process \n");
    scanf("%d",&n);
    p=(sp*)malloc(sizeof(sp));
    printf("Enter the burst time and priority:\n");
    for (i=0;i<n;i++)
    {
        printf("Process %d:",i+1);
        scanf("%d%d",&p[i].btime,&p[i].pri);
        p[i].pno=i+1;
        p[i].wtime=0;
    }
    for (i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
        if(p[i].pri>p[j].pri)
        {
            t=p[i];
            p[i]=p[j];
            p[j]=t;
        }
    }
    printf("\n Process \t bursttime\twaiting time\t turnaround time \n");
    for(i=0;i<n;i++)
    {
        totwtime +=p[i].wtime=tbm;tbm+=p[i].btime;
        printf("\n%d\t\t%d",p[i].pno,p[i].btime);
        printf("\t\t%d\t\t%d",p[i].wtime,p[i].wtime+p[i].btime);
    }
        totttime =tbm + totwtime;
        printf("\n total waiting time:%d",totwtime);
        printf("\n average waiting time:%d",totwtime/n);
        printf("\n total turnaround time :%d",totttime);
        printf("\n average turnaround time:%f",(float)totttime/n);
}

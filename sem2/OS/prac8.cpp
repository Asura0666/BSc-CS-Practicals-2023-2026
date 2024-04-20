/*
  Banker's Algorithm
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    int alloc[10][10],max[10][10];
    int avail[10],work[10],total[10];
    int i,m,j,k,n,need[10][10];
    int count=0,c=0;
    char finish[10];
    printf("Enter the no. of processes and resources:");
    scanf("%d%d",&n,&m);
    for(i=0;i<=n;i++)
    finish[i]='n';
    printf("Enter the claim matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%d",&max[i][j]);
    printf("Enter the allocation matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%d",&alloc[i][j]);
    printf("resource vector:");
    for(i=0;i<m;i++)
    scanf("%d",&total[i]);
    for(i=0;i<m;i++)
    avail[i]=0;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    avail[j]+=alloc[i][j];
    for(i=0;i<m;i++)
    work[j]=total[j]-work[j];
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    need[i][j]=max[i][j]-alloc[i][j];
    A:
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=0;j<m;j++)
        if((need[i][j]<=work[j])&&(finish[i]=='n'))
        c++;
        if(c==m)
        {
            printf("All the resources can be allocated to process %d",i+1);
            printf("\n\nAvailable resourcesare:");
            for(k=0;k<m;k++)
            {
                work[k]+=alloc[i][k];
                printf("%4d",work[k]);
            }
            printf("\n");
            finish[i]='y';
            printf("\nProcess %d executed?:%c \n",i+1,finish[i]);
            count++;
        }
    }
    if(count!=n)
    goto A;
    else
    printf("\n System is in safe mode");
    printf("\n The given state is safe state");
    getch();
}


/*
Enter the no. of processes and resources:5 3
Enter the claim matrix:
0 1 0
2 0 0 
3 2 2
2 1 1
0 0 2
Enter the allocation matrix:
7 5 3
3 2 2
9 2 2
2 2 2 
4 3 3
resource vector:3 3 2
All the resources can be allocated to process 1

Available resourcesare:  16   5   3

Process 1 executed?:y 
All the resources can be allocated to process 2

Available resourcesare:  19   7   5

Process 2 executed?:y 
All the resources can be allocated to process 3

Available resourcesare:  28   7   7

Process 3 executed?:y 
All the resources can be allocated to process 4

Available resourcesare:  30   9   9

Process 4 executed?:y 
All the resources can be allocated to process 5

Available resourcesare:  34  12  12

Process 5 executed?:y 

 System is in safe mode
 The given state is safe state
*/
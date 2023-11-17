//4.a.Write a program to add all the entered numbers.

#include <stdio.h>
int main()
{
    int n;
    printf("\nEnter the numeber of element: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    
    printf("\nSum is: %d",sum);
    
    return 0;
}

//4.b.Write a program to form a matrix with the help of the enter numbers .

#include <stdio.h>
int main()
{
    int n;
    printf("\nEnter the numeber of element: ");
    scanf("%d",&n);
    
    int arr[n][n];
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&arr[i][j]);
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//4.c.Write a program to form two matrix and then make the sum of the two matrix

#include <stdio.h>
int main()
{
    int n;
    printf("\nEnter the numeber of element: ");
    scanf("%d",&n);
    
    int arr1[n][n];
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&arr1[i][j]);
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    
    int arr2[n][n];
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&arr2[i][j]);
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
    
    int sum[n][n];
    printf("\nSum of two matrix: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}



#include <stdio.h>

int main() {
    
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("\nEnter the 1st element: ");
    scanf("%d",&arr[0]);
    
    int max,min;
    max = min = arr[0];
    
    printf("\nEnter the rest of %d elements: ",n-1);
    for(int i=1; i<n; i++) {
        scanf("%d",&arr[i]);
        if(arr[i] > max) {
            max = arr[i];
        } else if(arr[i] < min) {
            min =  arr[i];
        }
    }
    
    printf("\nMaximum number: %d",max);
    printf("\nMinimum number: %d",min);
    
    return 0;
}

/*
Output: 

Enter the number of elements: 6

Enter the 1st element: 10 

Enter the rest of 5 elements: 5 12 7 2 9

Maximum number: 12
Minimum number: 2

*/


// Program to perform linear search and binary search on the given elements..

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int low, int high, int key) {
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main() {
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    
    bubbleSort(arr,n);
    printf("\nSorted Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    
    int key;
    printf("\nEnter the element to be searched: ");
    scanf("%d",&key);
    
    int linearIndex = linearSearch(arr,n,key);
    if(linearIndex != -1) {
        printf("\nLinear Search: element is found at %d index",linearIndex);
    } else {
        printf("\nLinear Search: element is not found");
    }
    
    int binaryIndex = binarySearch(arr,0,n-1,key);
    if(binaryIndex != -1) {
        printf("\nBinary Search: element is found at %d index",binaryIndex);
    } else {
        printf("\nBinary Search: element is not found");
    }
    
    return 0;
}

/*

Output:

Enter the number of elements: 6

Enter the elements: 10 5 12 7 9 2

Sorted Array: 2 5 7 9 10 12 
Enter the element to be searched: 10

Linear Search: element is found at 4 index
Binary Search: element is found at 4 index

*/


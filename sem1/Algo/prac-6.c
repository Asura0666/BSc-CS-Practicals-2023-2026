

#include <stdio.h>


void insertionSort(int arr[], int n) {
    int key;
    for(int i=1; i<n; i++) {
        key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
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

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    printf("\nEnter the Number of Elements: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("\nEnter The Number: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // insertionSort(arr,n);
    // bubbleSort(arr,n);
    selectionSort(arr,n);
    printf("\nSorted Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    
    return 0;
}

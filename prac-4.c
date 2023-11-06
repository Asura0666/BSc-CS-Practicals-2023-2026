#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int linearResult = linearSearch(arr, size, target);
    int binaryResult = binarySearch(arr, size, target);

    if (linearResult != -1) {
        printf("Linear Search: Element found at index %d\n", linearResult);
    } else {
        printf("Linear Search: Element not found\n");
    }

    if (binaryResult != -1) {
        printf("Binary Search: Element found at index %d\n", binaryResult);
    } else {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}

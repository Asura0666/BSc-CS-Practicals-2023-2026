#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        int min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n > 0 ) {
        selectionSort(arr, n);

        int nth_min = arr[n - 1];
        int nth_max = arr[n - n];

        printf("Nth Minimum Element: %d\n", nth_min);
        printf("Nth Maximum Element: %d\n", nth_max);
    } else {
        printf("something is wrong...");
    }

    return 0;
}

/* 
1.1 Accept N 
1.2 Accept N Array Numbers 
1.3 Print Reverse of the Array
*/
#include <stdio.h>

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    
    int arr[N];
    
    printf("Enter %d elements: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    printf("Reversed array: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

/*
2.1 Accept N 
2.2 Accept N Array Numbers 
2.3 Print Average of Array Numbers
*/
#include <stdio.h>

int main() {
    int N;
    float sum = 0.0;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d elements: ", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Average: %.2f\n", sum / N);
    return 0;
}

/*
3.1 Accept N 
3.2 Accept N Array Numbers 
3.3 Print Odd and Even Numbers Separately
*/
#include <stdio.h>

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d elements: ", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Even numbers: ");
    for(int i = 0; i < N; i++) {
        if(arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\nOdd numbers: ");
    for(int i = 0; i < N; i++) {
        if(arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}

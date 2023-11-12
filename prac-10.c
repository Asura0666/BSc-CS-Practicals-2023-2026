



#include <stdio.h>

int FibRecursive(int n) {
    if(n==1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return FibRecursive(n-1) + FibRecursive(n-2);
    }
}


int FibBottomUp(int n) {
    int FibTable[n+1];
    FibTable[0] = 0;
    FibTable[1] = 1;
    
    for(int i=2; i<=n; i++) {
        FibTable[i] = FibTable[i-1] + FibTable[i-2];
    }
    return FibTable[n];
}


int FibTopDown(int n) {
    int a=0,b=1;
    for(int i=0; i<n; i++) {
        int temp = a+b;
        a=b;
        b=temp;
    }
    return a;
}


int main() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    
    printf("\nRecursive Fibonacci: %d",FibRecursive(n));
    printf("\nBottom Up dynamic programing: %d",FibBottomUp(n));
    printf("\nTop Down dynamic programing: %d",FibTopDown(n));
    
    return 0;
}



/*
#include <stdio.h>

// Recursive Fibonacci function
int fibRecursive(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }
}

// Bottom-up Dynamic Programming Fibonacci function
int fibBottomUp(int n) {
    int fibTable[n + 1];
    fibTable[0] = 0;
    fibTable[1] = 1;

    for (int i = 2; i <= n; i++) {
        fibTable[i] = fibTable[i - 1] + fibTable[i - 2];
    }

    return fibTable[n];
}

// Top-down Dynamic Programming Fibonacci function
int fibTopDown(int n) {
    int a = 0, b = 1;

    for (int i = 1; i < n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    return a;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Recursive Fibonacci
    printf("Recursive Fibonacci: %d\n", fibRecursive(n));

    // Bottom-up Dynamic Programming Fibonacci
    printf("Bottom-up Dynamic Programming: %d\n", fibBottomUp(n));

    // Top-down Dynamic Programming Fibonacci
    printf("Top-down Dynamic Programming: %d\n", fibTopDown(n));

    return 0;
}

*/


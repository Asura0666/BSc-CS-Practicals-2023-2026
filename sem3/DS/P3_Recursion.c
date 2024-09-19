
//Factorial
#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    
    if(n < 0){
        printf("Invalid Value");
        return 0;
    }

    printf("Factorial of %d is %d\n", n, factorial(n));
    return 0;
}


//fibonacci
#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print the Fibonacci series up to n terms
void printFibonacciSeries(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);
    
    if(n < 0){
        printf("Invalid Number");
        return 0;
    }

    printf("Fibonacci series up to %d terms:\n", n);
    printFibonacciSeries(n);

    return 0;
}
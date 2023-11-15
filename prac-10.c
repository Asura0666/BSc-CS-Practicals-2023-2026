



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




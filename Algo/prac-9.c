


//Tower Of Hanoi problem....

/*
#include <stdio.h>

void towerOfHanoi(int n, char source, char helper, char destination) {
    
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n",source,destination);
        return;
    }
    
    towerOfHanoi(n-1,source,destination,helper);
    printf("Move disk %d from %c To %c\n",n,source,destination);
    towerOfHanoi(n-1,helper,source,destination);

}


int main() {
    int n;
    printf("Enter the number of disk: ");
    scanf("%d",&n);
    
    towerOfHanoi(n,'S','H','D');
    return 0;
    
}
*/



//Factorial by recursive method...
/*
#include <stdio.h>
int Factorial(int n) {
    
    if(n==0 || n==1) {
        return 1;
    } else {
        return n * Factorial(n-1);
    }

}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n >= 0) {
        int result = Factorial(n);
        printf("Factorial of %d is: %d",n,result);
    } else {
        printf("Invaild Number...");
    }
    
    return 0;
}
*/


//Factorial by iterative method...
/*
#include <stdio.h>

int Factorial(int n) {
    int result = 1;
    for(int i=1; i<=n; i++) {
        result *= i;
    }
    return result;
}


int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    
    if(n >= 0) {
        int result = Factorial(n);
        printf("Factorial of %d is: %d",n,result);
    } else {
        printf("Invaild Number...");
    }
    
    return 0;
}
*/




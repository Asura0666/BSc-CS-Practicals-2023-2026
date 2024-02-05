//3.a.Write a program to print the table of the given number upto 10.

#include <stdio.h>

int main()
{
    int num;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    
    for(int i=1; i<=10; i++) {
        printf("\n%d X %d = %d",num,i,num*i);
    }
    
    return 0;
}

//3.b.Write a program to find out that the number is an armstrong number or not.

#include <stdio.h>
#include <math.h>
int main()
{
    int num, temp, rem, sum = 0;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    
    temp = num;
    
    while(num > 0) {
        rem = num % 10;
        sum = sum + pow(rem,3);
        num = num / 10;
    }
    
    if(temp != sum) {
        printf("\nNot Amstrong Number...");
    }else {
        printf("\nAmstrong Number...");
    }
    return 0;
}

//3.c.Write a program to print whether the number is a palindrome number or not

#include <stdio.h>
#include <math.h>
int main()
{
    int num, temp, rem, sum = 0;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    
    temp = num;
    
    while(num > 0) {
        rem = num % 10;
        sum = sum * 10 + rem;
        num = num / 10;
    }
    
    if(temp != sum) {
        printf("\nNot Palindrome Number...");
    }else {
        printf("\nPalindrome Number...");
    }
    return 0;
}

//3.d.write a program to print the fibonacci series of the element.

#include <stdio.h>
int main()
{
    int num, n1 = 0, n2 = 1, n3 ;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    
    printf("\n%d %d ",n1,n2);
    
    for(int i=2; i<num; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d ",n3);
    }
    
    return 0;
}
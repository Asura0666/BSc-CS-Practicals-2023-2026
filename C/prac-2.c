//2.a.Write a program to find the number Is even or odd.

#include <stdio.h>

int main()
{
    int num;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    
    if(num % 2 == 0) {
        printf("\nNumber is even (%d)",num);
    } else {
        printf("\nNumber is odd (%d)",num);
    }
    
    return 0;
}

//2.b.Write a program to check whether the person is eligible for voting or not.

#include <stdio.h>

int main()
{
    int age;
    printf("\nEnter a age: ");
    scanf("%d",&age);
    
    if(age >= 18) {
        printf("\nPerson is eligible for voting..");
    } else {
        printf("\nPerson is not eligible for voting..");
    }
    
    return 0;
}

//2.c.Write a program to find the greatest numbers among the three numbers.

#include <stdio.h>

int main()
{
    int a, b, c;
    printf("\nEnter 1st number: ");
    scanf("%d",&a);
    printf("\nEnter 2nd number: ");
    scanf("%d",&b);
    printf("\nEnter 3rd number: ");
    scanf("%d",&c);
    
    if(a > b && a > c) {
        printf("\n1st Number is largest(%d)",a);
    } else if(b > c && b > a) {
        printf("\n2nd Number is largest(%d)",b);
    } else if(c > b && c > a) {
        printf("\n3rd Number is largest(%d)",c);
    }
    
    return 0;
}

//2.d.Write a program to check whether the student is fail,pass, 
// second class,first class,excellent or invalid marks.

#include <stdio.h>

int main()
{
    int marks;
    printf("\nEnter your marks: ");
    scanf("%d",&marks);
    
    if(marks < 35) {
        printf("\nFail...");
    }else if(marks >= 35 && marks <= 50) {
        printf("\nPass");
    } else if(marks >= 51 && marks < 60) {
        printf("\nSecond class...");
    } else if(marks >= 60 && marks < 75) {
        printf("\nFirst class...");
    } else if(marks >= 75 ) {
        printf("\nExcellent...");
    } else {
        printf("\nInvalid marks...");
    }
    
    return 0;
}


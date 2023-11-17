//5.a.Write a program to add the value inside the function and Write the Before and After function call.
#include <stdio.h>
void change(int num) {
    printf("\nBefore adding value inside function num = %d",num);
    num = num + 100;
    printf("\nAfter adding value inside function num = %d",num);
}
int main()
{
    int x = 100;
    printf("\nBefore function call x = %d",x);
    change(x);
    printf("\nAfter function call x = %d",x);
    
    return 0;
}

//5.b.Write a program to swap two values of the variables (a→b) and (b→a) by call by value.

#include <stdio.h>
void swap(int , int);
int main()
{
    int a = 10;
    int b = 20;
    
    printf("\nBefore swaping value in main a = %d and b = %d",a,b);
    swap(a,b);
    printf("\nAfter swaping value in main a = %d and b = %d",a,b);
    return 0;
}
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = a;
    printf("\nAfter swaping value in function a = %d and b = %d",a,b);
}

//5.c.Write a program to swap two values of the variables (a→b) and (b→a) by call by reference.

#include <stdio.h>
void swap(int *, int *);
int main()
{
    int a = 10;
    int b = 20;
    
    printf("\nBefore swaping value in main a = %d and b = %d",a,b);
    swap(&a,&b);
    printf("\nAfter swaping value in main a = %d and b = %d",a,b);
    return 0;
}
void swap(int*a, int*b) {
    int temp = *a;
    *a = *b;
    *b = *a;
    printf("\nAfter swaping value in function a = %d and b = %d",*a,*b);
}


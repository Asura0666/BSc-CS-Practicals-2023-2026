//6.a.Write a program to print the memory address using pointers.

#include <stdio.h>
int main()
{
   int x;
   int *p;
   
   printf("\nEnter a number: ");
   scanf("%d",&x);
   p = &x;
   printf("\nValue: %d",*p);
   printf("\nAddress: %u",p);
   
    return 0;
}

//6.b.Write a program for multiplication of two pointers.

#include <stdio.h>
int main()
{
    int x,y,mul;
    int *p1;
    int *p2;
   
    printf("\nEnter 1st number: ");
    scanf("%d",&x);
    printf("\nEnter 2nd number: ");
    scanf("%d",&y);
    p1 = &x;
    p2 = &y;
   
    mul = (*p1) * (*p2);
    
    printf("\n%d X %d = %d",*p1,*p2,mul);
   
    return 0;
}

//6.c.Write a program to print the Index,Number,and Address of 5 numbers.

#include <stdio.h>

int main() {
    int arr[5];
    int *p;
    
    // Input values into the array
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    p = &arr[0];
    
    printf("\n**************************************");
    printf("\nIndex\tNumber\tAddress");
    

    for (int i = 0; i < 5; i++) {
        printf("\n%d\t%d\t%u", i + 1, *p, p);
        p++; 
    }
    
    return 0;
}

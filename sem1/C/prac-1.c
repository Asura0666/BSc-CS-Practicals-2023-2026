// 1.a.Write a program to find the add,subs,multi,div of the two numbers

#include <stdio.h>

int main()
{
    int a, b, sum, sub, mul, dive;
    printf("\nEnter 1st number: ");
    scanf("%d",&a);
    printf("\nEnter 2nd number: ");
    scanf("%d",&b);
    
    sum = a + b;
    sub = a - b;
    mul = a * b;
    dive = a / b;
    
    printf("\nSum of two number is: %d",sum);
    printf("\nSubtraction of two number is: %d",sub);
    printf("\nMultiplication of two number is: %d",mul);
    printf("\ndivision of two number is: %d",dive);
    
    return 0;
}

//1.b.Write a program to find the area and circumference of the circle.

#include <stdio.h>
#include <math.h>

int main()
{
    double radius;
    
    printf("\nEnter the radius: ");
    scanf("%lf",&radius);
    
    double area = M_PI * pow(radius, 2);
    double circumference = 2 * M_PI * radius;
    
    printf("\nArea of circle is: %lf",area);
    printf("\nCircumference of circle is: %lf",circumference);
    
    return 0;
}

//1.c.Write a program to find the area of the rectangle.

#include <stdio.h>
#include <math.h>

int main()
{
    float length;
    float breath;
    printf("\nEnter the length of rectangle: ");
    scanf("%f",&length);
    printf("\nEnter the breath of rectangle: ");
    scanf("%f",&breath);

    float area = length * breath;
    
    printf("\nArea of rectangle: %f",area);
    
    return 0;
}

//1.d.Write a program to find the area of square.

int main()
{
    float side;

    printf("\nEnter the side of Square: ");
    scanf("%f",&side);


    float area = side * side;
    
    printf("\nArea of Square: %f",area);
    
    return 0;
}

//1.e.Write a program to find the area of the triangle.

#include <stdio.h>
#include <math.h>

int main()
{
    float length;
    float breath;
    printf("\nEnter the length of triangle: ");
    scanf("%f",&length);
    printf("\nEnter the breath of triangle: ");
    scanf("%f",&breath);

    float area = 0.5 * length * breath;
    
    printf("\nArea of triangle: %f",area);
    
    return 0;
}
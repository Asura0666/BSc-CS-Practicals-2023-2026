// 4.1) Define a class ‘Overload’ which will overload the method ‘add ( )’ as int add (int x, int y) 
// & int add (int a, int b, int c) which will return the sum x+y & a+b+c respectively.

#include <iostream>
using namespace std;

class Overload {
    public:
        int add(int a, int b) {
            return a + b;
        }
        
        int add(int a, int b, int c) {
            return a + b + c;
        }
};

int main() {
    
    cout<<"\nFunction Overloading...";
    Overload O;
    
    cout<<"\nAddition of two number is: "<<O.add(10,5);
    cout<<"\nAddition of Three number is: "<<O.add(10,5,15);
    
    
    return 0;
}

// 4.2) Write a function Area( ) to find area of a circle, triangle. If only one argument is specified 
// it will calculate the area of circle. If two argument is specified it will calculate the area of triangle.
//  Use the concept of function overloading.

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    public:
        double area(double radius) {
            return M_PI * pow(radius,2);
        }
        
        double area(double height, double breath) {
            return 0.5 * height * breath;
        }
};

int main() {
    cout<<"\nFunction Overloading";
    Shape S;
    
    cout<<"\narea of circle is: "<<S.area(7);
    
    cout<<"\narea of triangle is: "<<S.area(4,5);
    
    return 0;
}

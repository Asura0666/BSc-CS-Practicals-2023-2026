// 5.1) Create a class CCircle to calculate area and circumference of a circle. 
// The program should initialize the variables through constructor. Use the same constructor for 
// reading radius of a circle. CIRCLE_AREA member function is used to calculate area of a circle 
// and CIRCLE_CIRCUMFERENCE is used to calculate circumference of a circle. 
// Member function SHOW to display area and circumference of a circle.

#include <iostream>
#include <cmath>
using namespace std;

class Circle {
    private:
        double radius;
        double area;
        double circumference;
    public:
        Circle(double r) {
            radius = r;
            calculateArea();
            calculateCircumference();
        }
        
        void calculateArea() {
            area = M_PI * pow(radius,2);
        }
        
        void calculateCircumference() {
            circumference = 2 * M_PI * radius;
        }
        
        void show() {
            printf("\nradius of circle is: %lf",radius);
            printf("\narea of circle is: %lf",area);
            printf("\ncircumference of circle is: %lf",circumference);
        }
};

int main() {
    double radius;
    cout<<"\nEnter the number: ";
    cin>>radius;
    
    Circle circle(radius);
    circle.show();
    
    return 0;
}

// 5.2) Create a class CPower for calculating any power of any number. It should have two 
// constructors one to read both number and its power and second to read number only and second 
// number should be 2. In addition class CPower should have two member functions RAISEDTO to calculate 
// power and SHOW to display result of calculation.

#include <iostream>
#include <cmath>
using namespace std;

class CPower {
    private:
        double number;
        int power;
    public:
        CPower(double num, int Pow){
            number = num;
            power = Pow;
        }
        CPower(double num) {
            number = num;
            power = 2;
        }
        
        double raiseToPower() {
            return pow(number,power);
        }
        
        void show() {
            double ans = raiseToPower();
            printf("\n%lf raise to the power of %d is: %lf",number,power,ans);
        }
};

int main() {
    double number;
    int power;
    
    cout<<"\nEnter the number: ";
    cin>>number;
    cout<<"\nEnter the power: ";
    cin>>power;
    
    CPower c1(number,power);
    c1.show();
    CPower c2(number);
    c2.show();
    
    return 0;
}

//6.1) Write a program to demonstrate overloading of binary operator. 
// Overload ‘-’ operator in the class complex.

#include <iostream>
using namespace std;

class Complex {
    int realPart, imaginaryPart;

public:
    Complex() {
        realPart = 0;
        imaginaryPart = 0;
    }

    Complex(int real, int imaginary) {
        realPart = real;
        imaginaryPart = imaginary;
    }

    Complex operator+(Complex);

    void display() {
        cout << realPart << " + " << imaginaryPart << "j";
    }
};

Complex Complex::operator+(Complex otherComplex) {
    Complex result;
    result.realPart = realPart + otherComplex.realPart;
    result.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;
    return result;
}

int main() {
    Complex complex1, complex2, resultComplex;

    cout << "1st Complex Number: ";
    complex1.display();

    cout << "\n2nd Complex Number: ";
    complex2.display();

    resultComplex = complex1 + complex2;

    cout << "\nAddition of two complex numbers: ";
    resultComplex.display();

    // Creating and adding two more complex numbers
    complex1 = Complex(4, 5);
    complex2 = Complex(10, 6);

    cout << "\n\n1st Complex Number: ";
    complex1.display();

    cout << "\n2nd Complex Number: ";
    complex2.display();

    resultComplex = complex1 + complex2;

    cout << "\nAddition of two complex numbers: ";
    resultComplex.display();

    return 0;
}

/*
Output:
1st Complex Number: 0 + 0j
2nd Complex Number: 0 + 0j
Addition of two Complex Number is: 0 + 0j
1st Complex Number: 4 + 5j
2nd Complex Number: 10 + 6j
Addition of two Complex Number is: 14 + 11j
*/


// 6.2) Create a class FLOAT that contains one float data member. 
// Overload all the four arithmetic operators so that they operate on the objects of FLOAT.


#include <iostream>
using namespace std;

class Float {
    float number;
    public:
        Float() {
            number = 0;
        }
        Float(float num) {
            number = num;
        }
        
        Float operator +(Float);
        Float operator -(Float);
        Float operator *(Float);
        Float operator /(Float);
        
        void display() {
            cout<<"Number : "<<number;
        }
};

Float Float :: operator +(Float F) {
    Float result;
    result.number = number + F.number;
    return result;
}

Float Float :: operator -(Float F) {
    Float result;
    result.number = number - F.number;
    return result;
}

Float Float :: operator *(Float F) {
    Float result;
    result.number = number * F.number;
    return result;
}

Float Float :: operator /(Float F) {
    Float result;
    result.number = number / F.number;
    return result;
}

int main() {
    Float F1,F2,F3;
    
    F1 = Float(15);
    F2 = Float(10);
    
    cout<<"\n1st number: ";
    F1.display();
    cout<<"\n2nd number: ";
    F2.display();
    
    F3 = F1 + F2;
    cout<<"\nAddition of two number is: ";
    F3.display();
    
    F3 = F1 - F2;
    cout<<"\nSubtraction of two number is: ";
    F3.display();
    
    F3 = F1 * F2;
    cout<<"\nMultiplication of two number is: ";
    F3.display();
    
    F3 = F1 / F2;
    cout<<"\nDivision of two number is: ";
    F3.display();
    
    return 0;
}



// 7.1) Create a class CAdd that reads two numbers adds it and print the result on the screen. 
//Create another class CSubtract that subtracts the two numbers which are read through CAdd class. 
//Write a full program using Simple inheritance.

#include <iostream>
using namespace std;

class C_ADD {
public:
    int a, b;

    void getdata() {
        cout << "\n Enter any two numbers";
        cin >> a >> b;
    }

    void display() {
        cout << "\na=" << a;
        cout << "\nb=" << b;
    }

    void add() {
        cout << "\nSum=" << a + b;
    }
};

class C_Substract : public C_ADD {
public:
    void substract() {
        cout << "\nSubtraction=" << a - b;
    }
};

int main() {
    C_Substract c1;
    c1.getdata();
    c1.display();
    c1.add();
    c1.substract();
    return 0;
}


// 7.2) Create a class CAdd that reads two numbers adds it and print the result on the screen. 
// Create another class CSubtract that subtracts the two numbers which are read through CAdd class. 
// Create another class CMultiply that multiplies two numbers that are read through CAdd class. 
// Write a full program using multilevel inheritance.

#include <iostream>
using namespace std;

class C_ADD {
public:
    int a, b;

    void getdata() {
        cout << "\nEnter any two numbers: ";
        cin >> a >> b;
    }

    void display() {
        cout << "\na=" << a;
        cout << "\nb=" << b;
    }

    void add() {
        cout << "\nSum=" << a + b;
    }
};

class C_Substract : public C_ADD {
public:
    void substract() {
        cout << "\nSubtraction=" << a - b;
    }
};

class C_Multiply : public C_Substract {
public:
    void multiply() {
        cout << "\nProduct=" << a * b;
    }
};

int main() {
    C_Multiply c1;
    c1.getdata();
    c1.display();
    c1.add();
    c1.substract();
    c1.multiply();

    return 0;
}


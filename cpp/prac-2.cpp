//Program 1: Demonstrating Use of Data Members & Member Functions

#include<iostream>
using namespace std;

class Student {
private:
    int id;
    char name[20];

public:
    void getdata() {
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
    }

    void display() {
        cout << "\nStudent ID: " << id;
        cout << "\nStudent Name: " << name;
    }
};

int main() {
    cout << "Your_name" << endl;

    Student s1;
    s1.getdata();
    s1.display();

    return 0;
}


//Programs based on branching and looping statements using classes.
//Program 2A: Branching Statements

#include<iostream>
using namespace std;

class Result {
public:
    float marks;

    void total() {
        int m, n, b;
        cout << "Maths: ";
        cin >> m;
        cout << "CS: ";
        cin >> n;
        cout << "Biology: ";
        cin >> b;

        int c = m + n + b;
        cout << "Marks Obtained: " << c << endl;
        marks = c;
    }

    void display_result() {
        cout << "Percentage obtained: " << (marks / 300 * 100) << "%" << endl;
        float b = marks / 300 * 100;

        if (b < 35) {
            cout << "You have failed the exam" << endl;
        } else if (b <= 65) {
            cout << "You have passed the exam" << endl;
        } else {
            cout << "You got Distinction in exam" << endl;
        }
    }
};

int main() {
    cout << "Your_name" << endl;

    Result S1;
    S1.total();
    S1.display_result();

    return 0;
}


//Program 2B: Looping Statement

#include<iostream>
using namespace std;

class Tables {
public:
    int mul, n;

    void getdata() {
        cout << "Enter a number: ";
        cin >> n;
    }

    void display() {
        for (int i = 1; i <= 10; i++) {
            mul = n * i;
            cout << "Table of " << n << ": " << n << " * " << i << " = " << mul << endl;
        }
    }
};

int main() {
    cout << "Your_name" << endl;

    Tables t1;
    t1.getdata();
    t1.display();

    return 0;
}

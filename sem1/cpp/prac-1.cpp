
//Practical 1_1: Write a program to interchange the values of two variables

#include <iostream>
using namespace std;

int main() {
    int a, b, t;
    cout << "Enter any two numbers: ";
    cin >> a >> b;
    cout << "Before Swapping values are " << a << "\t" << b;
    t = a;
    a = b;
    b = t;
    cout << "After Swapping values are " << a << "\t" << b;
    return 0;
}

//Practical 1_2: Write a program to find the largest among two numbers

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter any two numbers: ";
    cin >> a >> b;
    if (a > b) {
        cout << a << " is the largest";
    } else {
        cout << b << " is the largest";
    }
    return 0;
}

//Practical 1_3: In a week Monday comes on the 1st date, Tuesday on the 2nd, and so on. 
//Write a program that will display the day of the date entered. (Using if-else)

#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter any number: ";
    cin >> a;
    if (a <= 0 || a > 31)
        cout << "\nWrong input";
    else {
        int r = a % 7;
        if (r == 1) {
            cout << a << " Monday";
        } else if (r == 2) {
            cout << a << " Tuesday";
        } else if (r == 3) {
            cout << a << " Wednesday";
        } else if (r == 4) {
            cout << a << " Thursday";
        } else if (r == 5) {
            cout << a << " Friday";
        } else if (r == 6) {
            cout << a << " Saturday";
        } else if (r == 0) {
            cout << a << " Sunday";
        }
    }
    return 0;
}


//Practical 1_4: Write a program that will accept 2 numbers and one operator and 
//perform the operation depending upon the operator. (Using switch case)

#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "Enter operator from (+, -, *, /, %): ";
    cin >> op;

    switch (op) {
    case '+':
        cout << "Addition = " << a + b;
        break;
    case '-':
        cout << "Subtraction = " << a - b;
        break;
    case '*':
        cout << "Product = " << a * b;
        break;
    case '/':
        cout << "Division = " << a / b;
        break;
    case '%':
        cout << "Remainder = " << a % b;
        break;
    }

    return 0;
}


//Practical 1_5: Write a program that will display the factorial from 1 to 10. (for loop or while loop)

#include <iostream>
using namespace std;

int main() {
    long unsigned int fact = 1;
    int i, j;

    for (i = 1; i <= 10; i++) {
        fact = 1;
        for (j = 1; j <= i; j++)
            fact = fact * j;
        cout << "\nFactorial of " << i << " = " << fact;
    }

    return 0;
}

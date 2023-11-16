
//8.1) Create a class CAdd that reads two numbers adds it and print the result on the screen.
//Create another class CSubtract that reads two numbers subtracts it and print the result on
//the screen. Create another class CMultiply that multiplies numbers that are read through
//CAdd and CSubtract class. Write a full program using multiple.

#include <iostream>

using namespace std;

class AddTwoNumbers {
    public:
        int a,b;
        
        void getData() {
            cout<<"\nEnter the 1st number: ";
            cin>>a;
            cout<<"\nEnter the 2nd number: ";
            cin>>b;
        }
        
        void display() {
            printf("\n1st Number: %d",a);
            printf("\n2nd Number: %d",b);
        }
        
        void Sum() {
            printf("\nSum of two Number is: %d",a+b);
        }
};

class SubtractTwoNumbers {
    public:
    int c,d;
    
        void getData1() {
            cout<<"\nEnter the 1st number: ";
            cin>>c;
            cout<<"\nEnter the 2nd number: ";
            cin>>d;
        }
        
        void display1() {
            printf("\n1st Number: %d",c);
            printf("\n2nd Number: %d",d);
        }
        
        void Subtract() {
            printf("\nSubtract of two Number is: %d",c-d);
        }
};

class ProductOfTwoNumbers: public SubtractTwoNumbers, public AddTwoNumbers {
    public:
        void Product() {
            printf("\nProduct of two Number is: %d in AddTwoNumbers",a*b);
            printf("\nProduct of two Number is: %d in SubtractTwoNumbers",c*d);
        }
};

int main()
{
    ProductOfTwoNumbers P1;
    P1.getData();
    P1.display();
    P1.Sum();
    P1.getData1();
    P1.display1();
    P1.Subtract();
    P1.Product();

    return 0;
}

//8.2) Define a class ‘Publication’ having data members as String title, float price. Write display()
// function which will display the data. From this class derive two classes‘Book’ & ‘Tape’. ‘Book’ class
// will add int page_cnt as data member & ‘Tape’ class will add float play_time as data member.
// Override display() function for both classes. Write constructors for all classes.

#include <iostream>
#include <cstring>
using namespace std;

class Publication {
    public:
        string title;
        int price;
        
        Publication(string title, int price): title(title), price(price) {
            
        }
       
        void display() {
            printf("\nTitle is: %s",title.c_str());
            printf("\nPrice is: %d",price);
        }
};

class book : public Publication {
    public:
        int pageCount;
        
        book(string title, int price, int pageCount) : Publication(title, price), pageCount(pageCount) {
            
        }
        
        void display() {
            Publication::display();
            printf("\nBook pageCount is: %d",pageCount);
        }
};

class tape : public Publication {
    public:
        float playTime;
        tape(string title, int price, float playTime) : Publication(title, price), playTime(playTime) {
            
        }
        void display() {
            Publication:: display();
            printf("\nTape playTime is: %f",playTime);
        }
};

int main() {
    
    book b1 = book("Scissor Seven",1000,600);
    b1.display();
    tape t1 = tape("Super Yodha",200,25.5);
    t1.display();
    return 0;
}


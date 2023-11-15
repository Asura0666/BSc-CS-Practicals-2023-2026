//3.1 Define a class with 3 member functions. One to accept a five digit number from
//the user. Second to find the sum of its digit and the third to display the digits in
//reverse order.

#include <iostream>
using namespace std;

class Number {
private:
    int n;

public:
    void accept() {
        cout << "\nEnter any five-digit number: ";
        cin >> n;
        cout << "Entered Number = " << n;
    }

    int sum_of_digits() {
        int n1 = n;
        int sum = 0, r;
        while (n1 > 0) {
            r = n1 % 10;
            sum = sum + r;
            n1 = n1 / 10;
        }
        return sum;
    }

    int reverse() {
        int n1 = n;
        int rev = 0, r;
        while (n1 > 0) {
            r = n1 % 10;
            rev = rev * 10 + r;
            n1 = n1 / 10;
        }
        return rev;
    }
};

int main() {
    Number N1;
    N1.accept();
    cout << "\nSum of digits: " << N1.sum_of_digits();
    cout << "\nReverse: " << N1.reverse();
    return 0;
}


//3.2 Define a class called cricket that will describe the following information:
//Players name, team_name and batting average. Using cricket declare array with 10
//elements. And write a program to read information about 10 players and print the
//names of players with their batting average.

#include <iostream>
using namespace std;

class Cricket {
private:
    char player_name[15], team_name[15];
    float batting_avg;

public:
    void accept() {
        cout << "\nEnter Cricketer's name: ";
        cin >> player_name;
        cout << "Enter Team name: ";
        cin >> team_name;
        cout << "Enter Batting Average: ";
        cin >> batting_avg;
    }

    void display_data() {
        cout << "\nPlayer Name: " << player_name;
        cout << "\nTeam Name: " << team_name;
        cout << "\nBatting Average: " << batting_avg;
    }
};

int main() {
    Cricket c[10];
    int n, i;

    cout << "\nHow many players' data do you want to enter? ";
    cin >> n;

    for (i = 0; i < n; i++)
        c[i].accept();

    cout << "\n------- Data -------";
    for (i = 0; i < n; i++) {
        cout << "\nPlayer " << i + 1;
        c[i].display_data();
    }

    return 0;
}






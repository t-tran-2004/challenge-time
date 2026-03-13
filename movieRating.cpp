#include <iostream>

using namespace std;

int main() {
    // TODO: Build a ticket validation system for a movie theater.
    int age;
    char response;
    bool hasParent;

    cout << "Enter the customer's age: ";
    cin >> age;

    cout << "Is this customer parent-accompanied? (y or n): ";
    cin >> response;

    hasParent = (tolower(response) == 'y');

    if (hasParent || (age >= 17)) {
        cout << "Enjoy your R-rated movie!" << endl;
    }
    else if (age >= 13) {
        cout << "Enjoy your PG-13 movie!" << endl;
    }
    else {
        cout << "G-rated only." << endl;
    }

    return 0;
}
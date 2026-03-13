#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // TODO: Given three side lengths, classify the triangle type.
    double firstSideLength;
    double secondSideLength;
    double thirdSideLength;

    cout << "Enter the first side length: ";
    cin >> firstSideLength;
    
    cout << "Enter the second side length: ";
    cin >> secondSideLength;

    cout << "Enter the third side length: ";
    cin >> thirdSideLength;

    bool validTriangle = (firstSideLength + secondSideLength) > thirdSideLength;

    bool sideEquality1 = fabs(firstSideLength - secondSideLength) < 0.0001;
    bool sideEquality2 = fabs(firstSideLength - thirdSideLength) < 0.0001;
    bool sideEquality3 = fabs(secondSideLength - thirdSideLength) < 0.0001;

    if (!validTriangle) {
        cout << "Invalid triangle" << endl;
    }
    else if ((sideEquality1 && sideEquality2) && sideEquality3) {
        cout << "Equilateral triangle" << endl;
    }
    else if ((sideEquality1 || sideEquality2) || sideEquality3) {
        cout << "Isosceles triangle" << endl;
    }
    else {
        cout << "Scalene triangle" << endl;
    }

    return 0;
}
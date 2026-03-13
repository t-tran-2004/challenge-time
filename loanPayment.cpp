#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // TODO: Calculate the monthly payment of an annual loan.
    double principal;
    double annualInterestRate;
    int years;
    int numOfPayments = 0;
    double monthlyInterestRate = 0.0;
    double monthlyPayment = 0.00;
    const int YEAR_TO_MONTHS = 12;

    cout << "Enter the principal amount: $";
    cin >> principal;

    cout << "Enter the interest rate (%): ";
    cin >> annualInterestRate;

    cout << "Enter length of term (years): ";
    cin >> years;

    if ((years > 0) && (annualInterestRate > 0.0)) {
        monthlyInterestRate = (annualInterestRate / YEAR_TO_MONTHS) / 100.0;
        numOfPayments = years * YEAR_TO_MONTHS;
        monthlyPayment = principal * ((monthlyInterestRate * pow(1 + monthlyInterestRate, numOfPayments)) / (pow(1 + monthlyInterestRate, numOfPayments) - 1));
    }
    else {
        numOfPayments = years * YEAR_TO_MONTHS;
        monthlyPayment = (numOfPayments > 0) ? principal / numOfPayments : principal;
    }

    cout << setfill('-');
    cout << setw(35) << "" << endl;

    cout << "# of payments: " << numOfPayments << endl;

    cout << "Monthly interest: ";
    cout << fixed << setprecision(3) << monthlyInterestRate << "%" << endl;

    cout << "Monthly payment: $"; 
    cout << fixed << setprecision(2) << monthlyPayment << endl;

    cout << setw(35) << "" << endl;

    return 0;
}

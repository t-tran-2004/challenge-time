#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // TODO: Calculate the total price of items shipping overseas.
    double itemPrice;
    int quantity;
    double taxRate;
    double subtotal = 0.00;
    double taxAmount = 0.00;
    double finalPrice = 0.00;
    const double SHIPPING_FEE = 7.99;

    cout << "Enter the item unit price: $";
    cin >> itemPrice;

    cout << "How many items?: ";
    cin >> quantity;

    cout << "Enter the sales tax rate (%): ";
    cin >> taxRate;

    if (quantity > 0) {
        subtotal = itemPrice * quantity;
        taxAmount = subtotal * (taxRate / 100.0);
        finalPrice = subtotal + taxAmount + SHIPPING_FEE;
    }
    else {
        finalPrice = SHIPPING_FEE;
    }

    cout << setfill('-');
    cout << setw(35) << "" << endl;

    cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "Sales tax: $" << fixed << setprecision(2) << taxAmount << endl;
    cout << "Shipping fee: $" << fixed << setprecision(2) << SHIPPING_FEE << endl;
    cout << "Total: $" << fixed << setprecision(2) << finalPrice << endl;
    
    cout << setw(35) << "" << endl;

    return 0;
}

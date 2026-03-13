#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    // TODO: Implement a smart home controller program with three modes.
    double currentTemp;
    double targetTemp;
    char confirmation;
    string systemMode = "";

    cout << "Enter the current temperature (ºC): ";
    cin >> currentTemp;

    cout << "Enter the target temperature (ºC): ";
    cin >> targetTemp;

    cout << "Do you want to activate the system? (y or n): ";
    cin >> confirmation;

    bool activation = (tolower(confirmation) == 'y');
    bool isExactTemp = fabs(currentTemp - targetTemp) < 0.0001;

    if (activation && (currentTemp < targetTemp)) {
        systemMode.append("HEAT");
    }
    else if (activation && !isExactTemp) {
        systemMode.append("COOL");
    }
    else {
        systemMode.append("OFF");
    }

    switch(systemMode.at(0)) {
        case 'H':
            cout << "Heater On" << endl;
            break;

        case 'C':
            cout << "A/C On" << endl;
            break;
            
        case 'O':
        default:
            cout << "Idle" << endl;
    }

    return 0;
}
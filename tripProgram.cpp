#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double distance = 0.0;
    double avgSpeed = 0.0;
    double tripTime = 0.0;
    int tripTimeHours = 0;
    int tripTimeMinutes = 0;
    const int MINUTES_PER_HOUR = 60;

    cout << "Enter the travel distance (km): ";
    cin >> distance;

    cout << "Enter the average speed (km/h): ";
    cin >> avgSpeed;

    tripTime = distance / avgSpeed;
    tripTimeHours = (int)tripTime;
    tripTimeMinutes = (int)(tripTime * MINUTES_PER_HOUR) % MINUTES_PER_HOUR;

    cout << setfill('*');

    cout << setw(50) << "" << endl;

    cout << "The trip will take about " 
         << tripTimeHours << " hour(s) and "
         << tripTimeMinutes << " minutes." 
         << endl;

    cout << setw(50) << "" << endl;

    return 0;
}

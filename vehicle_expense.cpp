#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
using namespace std;

double calculateVehicleExpense(){
        double milesDriven; 
        const double RATE = 0.27; 
        do{
            cout << "Enter (miles driven): ";
            cin >> milesDriven;
            if (milesDriven < 0)
              cout << "Enter again: " << endl; 
        }while (milesDriven < 0);
        double vehicle_fee = RATE * milesDriven;
        cout << "Vehicle fees: $" << vehicle_fee << endl;
        return vehicle_fee;
}
#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;

double getCarRental()
{
    double carRental;
    do
    {
        cout << "The amount of any car rentals: $" ;
        cin >> carRental;
        if(carRental < 0)
          cout << "Error: The amount of car rental must be greater than 0" << endl;
        
    } while (carRental < 0);
    
    return carRental;
    
}

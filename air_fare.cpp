#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;

double getAirFare(){
    double airFare;
    do 
    {
        cout << "The amount of round-trip airfare: $" ;
        cin >> airFare;
        
        if(airFare < 0)
          cout << "Error: The amount of round-trip airfare must be greater than 0" << endl;
        
    }while (airFare < 0);
    return airFare;
   
}
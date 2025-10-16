#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;

int getTripDays()
{
    int days;
    do
    {
        cout << "Enter the total number of days spent on the trip: ";
        cin >> days;
        if(days < 1)
        cout << "Error: The number of days cannot be less than 1. Enter again." << endl;
       
    } while (days < 1);
    return days;
      
}
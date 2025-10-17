#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;


TotalTime getTime (){
    string departure_time, arrival_time;
    int deph, depm, arrh, arrm;
    do{
        cout << "Enter the departure time:";cin >> departure_time;
        cout << "Enter arrival time:";cin >> arrival_time;
        deph = stoi(departure_time.substr(0,2), 0);
        depm = stoi(departure_time.substr(3,2), 0);
        arrh = stoi(arrival_time.substr(0,2), 0);
        arrm = stoi(arrival_time.substr(3,2), 0);
        if (deph < 0 || deph >= 24 || depm < 0 || depm >= 60  || arrh < 0 || arrh >= 24 || arrm < 0 || arrm >= 60 )
        {   cout << "Check: " << endl;}
    } while (deph < 0 || deph >= 24 || depm < 0 || depm >= 60  || arrh < 0 || arrh >= 24 || arrm < 0 || arrm >= 60);
    cout << "Departure time: " << departure_time << "\nArrival time: " << arrival_time << endl;
    return {departure_time, arrival_time};
} 
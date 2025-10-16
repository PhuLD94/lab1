#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;



ParkingFee calculateParkingFee(){
    
    int PDays;
    double Allowed_Parking_Fee = 6;
    double used_per_day;
    double total_allowed_parking;
    double total_expense_parking = 0;
    do{
        cout<<"Enter the number of days spent at parking: ";
        cin>>PDays; 
       } while(PDays <= 0);
       total_allowed_parking =  Allowed_Parking_Fee * PDays;
    for(int i = 1; i <= PDays; i++){
        do{
        cout<<"Enter the Parking fee expenses " <<i<<" : $";
        cin>>used_per_day;
          }while(used_per_day < 0);
      
      total_expense_parking += used_per_day;
    }
    return {total_expense_parking,total_allowed_parking};
}	
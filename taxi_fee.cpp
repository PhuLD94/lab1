#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
using namespace std;


void calculateTaxiFee(int &TDays, double &total_expense_taxi, double &total_allowed_taxi) {
    
    double allowed_taxi_fee = 10;
    double used_per_day;
     total_allowed_taxi=0.0;
     total_expense_taxi = 0.0;
    do{
        cout<<"Enter the number of days spent on taxi: ";
        cin>>TDays; 
       } while(TDays <= 0);
       total_allowed_taxi = allowed_taxi_fee * TDays;
    for(int i = 1; i <= TDays; i++){
        do{
        cout<<"Enter the Taxi fee expenses for day " <<i<<": $";
        cin>>used_per_day;
          }while(used_per_day < 0);
     
      total_expense_taxi +=  used_per_day;
    }
    
}
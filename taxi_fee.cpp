#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;


TaxiFee calculateTaxiFee(){
    int TDays;
    double Allowed_Taxi_Fee = 10;
    double Used_per_day;
    double total_allowed_taxi;
    double total_expense_taxi = 0;
    do{
        cout<<"Enter the number of days spent on taxi: ";
        cin>>TDays; 
       } while(TDays <= 0);
       total_allowed_taxi = Allowed_Taxi_Fee * TDays;
    for(int i = 1; i <= TDays; i++){
        do{
        cout<<"Enter the Taxi fee expenses " <<i<<": $";
        cin>>Used_per_day;
          }while(Used_per_day < 0);
     
      total_expense_taxi +=  Used_per_day;
    }
    return {total_expense_taxi, total_allowed_taxi};
}
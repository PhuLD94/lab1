#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;



HotelExpense calculateHotelExpense(){
    int travelled_night;
    double allowed_hotel_fees_per_night = 90;
    double used_per_night;
    double total_allowed_hotel;
    double total_expense_hotel = 0;
    
    do{
        cout<<"Enter the night spent at the Hotel: ";
        cin>>travelled_night; 
       } while(travelled_night <= 0);
       total_allowed_hotel = allowed_hotel_fees_per_night * travelled_night;
    for(int i = 1; i <= travelled_night; i++){
        do{
        cout<<"Enter the Hotel expenses in the " <<i<<" night: $";
        cin>>used_per_night;
          }while(used_per_night < 0);
        
        
      total_expense_hotel  += used_per_night;
    }
      
    return {total_expense_hotel,total_allowed_hotel};
    
    
}
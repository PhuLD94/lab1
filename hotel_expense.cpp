#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"

using namespace std;



HotelExpense calculateHotelExpense(){
    int Travelled_Night;
    double Allowed_Hotel_fees_per_night = 90;
    double used_per_night;
    double total_allowed_hotel;
    double total_expense_hotel = 0;
    
    do{
        cout<<"Enter the night spent at the Hotel: ";
        cin>>Travelled_Night; 
       } while(Travelled_Night <= 0);
       total_allowed_hotel = Allowed_Hotel_fees_per_night * Travelled_Night;
    for(int i = 1; i <= Travelled_Night; i++){
        do{
        cout<<"Enter the Hotel expenses in the " <<i<<" night: $";
        cin>>used_per_night;
          }while(used_per_night < 0);
        
        
      total_expense_hotel  += used_per_night;
    }
      
    return {total_expense_hotel,total_allowed_hotel};
    
    
}
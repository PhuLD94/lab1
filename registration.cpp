#include <iostream>
#include "main.h"
using namespace std;

double getConference(){
    double registration_fees;
    do{
        cout<<"Enter the fee for Conference or Seminar registration: $";
        cin>>registration_fees;
       } while(registration_fees < 0);
        
    return registration_fees;
   
}

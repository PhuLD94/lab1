#include <iostream>
#include "main.h"
using namespace std;

double getConference(){
    double registration_fees;
    do{
        cout<<"Enter the fee for Conference or Seminar registration: $";
        cin>>registration_fees;
       } while(registration_fees < 0);
        cout<<"The fee for Conference or Seminar registration is: $"<< registration_fees << endl;
    return registration_fees;
   
}

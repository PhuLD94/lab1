#ifndef MAIN_H
#define MAIN_H
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;





struct TotalTime {
    string departure;
    string arrival;
};

int getTripDays();
void readTime(const string &label, int &hour, int &minute);
void getTime(int &depH, int &depM, int &arrH, int &arrM);
double getAirFare();
double getCarRental();
double calculateVehicleExpense();
double getConference();
void calculateParkingFee(int &PDays, double &total_expense_parking, double &total_allowed_parking);
void calculateHotelExpense(int &travelled_night, double &total_expense_hotel, double &total_allowed_hotel);
void calculateTaxiFee(int &TDays, double &total_expense_taxi, double &total_allowed_taxi);
void calculate_meal_expense(int total_day_travel, int depH, int depM,int arrH, int arrM,double &total_spent_meal,double &total_allowed_meal,double &total_saved_meal) ;

#endif
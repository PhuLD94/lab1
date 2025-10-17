#ifndef MAIN_H
#define MAIN_H
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;



struct TaxiFee{
    double total_expense_taxi;
    double total_allowed_taxi;
};
struct ParkingFee{
    double total_expense_parking;
    double total_allowed_parking;
};

struct MealExpense {
    float total_spent_meal;
    float total_allowed_meal;
    float total_saved_meal;
};



struct HotelExpense{
    double total_expense_hotel;
    double total_allowed_hotel;
};

struct TotalTime {
    string departure;
    string arrival;
};

int getTripDays();
TotalTime getTime();
double getAirFare();
double getCarRental();
double calculateVehicleExpense();
double getConference();
ParkingFee calculateParkingFee();
HotelExpense calculateHotelExpense();
TaxiFee calculateTaxiFee();
MealExpense calculate_meal_expense(int total_day_travel, string departure_time_string, string arrival_time_string);

#endif
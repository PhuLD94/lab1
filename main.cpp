#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
using namespace std;

int main() {
    
    double total_expenses=0.0;
    double total_allowed=0.0;
    double total_expense_hotel=0.0;
    double total_allowed_hotel=0.0;
    double total_expense_taxi=0.0;
    double total_allowed_taxi=0.0;
    int taxi_days=0;
    int travelled_nights=0;
    double total_spent_meal=0.0;
    double total_allowed_meal=0.0;
    double total_saved_meal=0.0;
    int parking_days=0;
    double total_expense_parking=0.0;
    double total_allowed_parking=0.0;
    int dh, dm, ah, am;
    // Functions
    int trip_days = getTripDays();
    getTime(dh, dm, ah, am);
    double air_fare= getAirFare();
    double car_rental = getCarRental();
    double vehicle_fee = calculateVehicleExpense();
    calculateParkingFee(parking_days, total_expense_parking, total_allowed_parking);
    calculateTaxiFee(taxi_days, total_expense_taxi, total_allowed_taxi);
    double registration = getConference();   
    calculateHotelExpense(travelled_nights, total_expense_hotel, total_allowed_hotel);
    calculate_meal_expense(trip_days, dh, dm, ah, am ,total_spent_meal, total_allowed_meal, total_saved_meal);
    
    //Calculate
    total_expenses=air_fare + car_rental + vehicle_fee + total_expense_parking + total_expense_taxi + registration + total_expense_hotel + total_spent_meal;
    total_allowed =air_fare + car_rental + vehicle_fee + total_allowed_parking + total_allowed_taxi + registration + total_allowed_hotel + total_allowed_meal + total_saved_meal;

    // ---------- Results ----------
    cout << "\n========== SUMMARY ==========\n";
    cout << "Total expenses:           $" << (total_expenses) << "\n";
    cout << "Total allowable expenses: $" << (total_allowed)  << "\n";

    if (total_expenses > total_allowed) {
        cout << "Excess to be reimbursed by employee: $" <<(total_expenses - total_allowed) << "\n";
    } else if (total_allowed > total_expenses) {
        cout << "Amount saved by employee: $"<< (total_allowed - total_expenses) << "\n";
    } else {
        cout << "Expenses exactly match the allowance.\n";
    }
    cout << "============================\n";
    
    return 0;
}
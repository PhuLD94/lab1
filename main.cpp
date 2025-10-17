#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
using namespace std;




int main() {
    
    double total_expenses=0.0;
    double total_allowed=0.0;

    // Functions
    int trip_days = getTripDays();
    TotalTime time = getTime();
    double air_fare= getAirFare();
    double car_rental = getCarRental();
    double vehicle_fee = calculateVehicleExpense();
    ParkingFee parking= calculateParkingFee();
    TaxiFee taxi= calculateTaxiFee();
    double registration = getConference();   
    HotelExpense hotel = calculateHotelExpense();
    MealExpense meal = calculate_meal_expense(trip_days, time.departure, time.arrival);
    
    //Calculate
    total_expenses=air_fare + car_rental + vehicle_fee + parking.total_expense_parking + taxi.total_expense_taxi + registration + hotel.total_expense_hotel + meal.total_spent_meal;
    total_allowed =air_fare + car_rental + vehicle_fee + parking.total_allowed_parking + taxi.total_allowed_taxi + registration + hotel.total_allowed_hotel + meal.total_allowed_meal + meal.total_saved_meal;

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
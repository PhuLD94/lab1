#include <iostream>
#include <string>
#include "meal_expense.h"
using namespace std;

const float BREAKFAST_ALLOWANCE = 9.0;
const float LUNCH_ALLOWANCE = 12.0;
const float DINNER_ALLOWANCE = 16.0;


MealExpense calculate_meal_expense(int total_day_travel, string departure_time_string, string arrival_time_string) {
    int departure_time = stoi(departure_time_string, 0);
    int arrival_time = stoi(arrival_time_string, 0);
    bool allow_breakfast_first = departure_time < 7;
    bool allow_breakfast_last = arrival_time > 8;
    bool allow_lunch_first = departure_time < 12;
    bool allow_lunch_last = arrival_time > 13;
    bool allow_dinner_first = departure_time < 18;
    bool allow_dinner_last = arrival_time > 19;
    float total_spent_meal = 0.0;
    float total_allowed_meal = 0.0;
    float total_saved_meal = 0.0;
    for(int i = 0; i < total_day_travel; i++){
        float breakfast_cost = 0.0, lunch_cost = 0.0, dinner_cost = 0.0;
        if (i == 0){
            if (allow_breakfast_first){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
            }
            if (allow_lunch_first){
                cout << "Enter lunch cost for day " << i+1 << ": ";
                cin >> lunch_cost;
            }
            if (allow_dinner_first){
                cout << "Enter dinner cost for day " << i+1 << ": ";
                cin >> dinner_cost;
            }
        }
        else if(i == total_day_travel - 1){
            if (allow_breakfast_last){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
            }
            if (allow_lunch_last){
                cout << "Enter lunch cost for day " << i+1 << ": ";
                cin >> lunch_cost;
            }
            if (allow_dinner_last){
                cout << "Enter dinner cost for day " << i+1 << ": ";
                cin >> dinner_cost;
            }
        }
        else{
            cout << "Enter breakfast cost for day " << i+1 << ": ";
            cin >> breakfast_cost;
            cout << "Enter lunch cost for day " << i+1 << ": ";
            cin >> lunch_cost;
            cout << "Enter dinner cost for day " << i+1 << ": ";
            cin >> dinner_cost;
        }

        total_spent_meal += breakfast_cost + lunch_cost + dinner_cost; 

        if (breakfast_cost > BREAKFAST_ALLOWANCE) total_allowed_meal += BREAKFAST_ALLOWANCE;
        else{
            total_allowed_meal += breakfast_cost;
            total_saved_meal += BREAKFAST_ALLOWANCE - breakfast_cost;
        } 

        if (lunch_cost > LUNCH_ALLOWANCE) total_allowed_meal += LUNCH_ALLOWANCE;
        else{
            total_allowed_meal += lunch_cost;
            total_saved_meal += LUNCH_ALLOWANCE - lunch_cost;
        } 

        if (dinner_cost > DINNER_ALLOWANCE) total_allowed_meal += DINNER_ALLOWANCE;
        else{
            total_allowed_meal += dinner_cost;
            total_saved_meal += DINNER_ALLOWANCE - dinner_cost;
        }
    }

    return {total_spent_meal, total_allowed_meal, total_saved_meal};

}


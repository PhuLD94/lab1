#ifndef MEAL_EXPENSE_H
#define MEAL_EXPENSE_H

#include <string>
using namespace std;

struct MealExpense {
    float total_spent_meal;
    float total_allowed_meal;
    float total_saved_meal;
};

// This function return the total meal expense spent and allowed
// Args:
    // int total_day_travel: total days of travel
    // string departure_time_string: departure time in string format "HH:MM"
    // string arrival_time_string: arrival time in string format "HH:MM"
// Return:
    // float: total meal expense spent
    // float: total meal expense allowed
    // float: total meal expense saved
MealExpense calculate_meal_expense(int total_day_travel, string departure_time_string, string arrival_time_string);

#endif

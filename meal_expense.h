#ifndef MEAL_EXPENSE_H
#define MEAL_EXPENSE_H

#include <string>
using namespace std;

struct MealExpense {
    float total_spent_meal;
    float total_allowed_meal;
};

// Function declaration (prototype)
MealExpense calculate_meal_expense(int total_day_travel, string departure_time_string, string arrival_time_string);

#endif

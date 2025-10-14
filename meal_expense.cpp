#include <iostream>
#include <string>
using namespace std;

const float BREAKFAST_ALLOWANCE = 9.0;
const float LUNCH_ALLOWANCE = 12.0;
const float DINNER_ALLOWANCE = 16.0;

struct MealExpense {
    float total_spent_meal;
    float total_allowed_meal;
};
// This function return the total meal expense spent and allowed
// Args:
    // int total_day_travel: total days of travel
    // string departure_time_string: departure time in string format "HH:MM"
    // string arrival_time_string: arrival time in string format "HH:MM"
// Return:
    // float: total meal expense spent
    // float: total meal expense allowed
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
    float breakfast_cost = 0.0, lunch_cost = 0.0, dinner_cost = 0.0;
    for(int i = 0; i < total_day_travel; i++){
        float breakfast_cost = 0.0, lunch_cost = 0.0, dinner_cost = 0.0;
        if (i == 0){
            if (allow_dinner_last){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
                cout << "Enter lunch cost for day " << i+1 << ": ";
                cin >> lunch_cost;
                cout << "Enter dinner cost for day " << i+1 << ": ";
                cin >> dinner_cost;
            }
            else if (allow_lunch_last){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
                cout << "Enter lunch cost for day " << i+1 << ": ";
                cin >> lunch_cost;
            }
            else if (allow_breakfast_last){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
            }
        }
        else if (i == total_day_travel - 1){
            if (allow_dinner_last){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
                cout << "Enter lunch cost for day " << i+1 << ": ";
                cin >> lunch_cost;
                cout << "Enter dinner cost for day " << i+1 << ": ";
                cin >> dinner_cost;
            }
            else if (allow_lunch_last){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
                cout << "Enter lunch cost for day " << i+1 << ": ";
                cin >> lunch_cost;
            }
            else if (allow_breakfast_last){
                cout << "Enter breakfast cost for day " << i+1 << ": ";
                cin >> breakfast_cost;
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
        if (breakfast_cost > BREAKFAST_ALLOWANCE){
            total_allowed_meal += BREAKFAST_ALLOWANCE;
            breakfast_cost -= BREAKFAST_ALLOWANCE;
        }
        else breakfast_cost = 0.0;

        if (lunch_cost > LUNCH_ALLOWANCE){
            total_allowed_meal += LUNCH_ALLOWANCE;
            lunch_cost -= LUNCH_ALLOWANCE;
        }
        else lunch_cost = 0.0;

        if (dinner_cost > DINNER_ALLOWANCE){
            total_allowed_meal += DINNER_ALLOWANCE;
            dinner_cost -= DINNER_ALLOWANCE;
        }
        else dinner_cost = 0.0;

        total_spent_meal += breakfast_cost + lunch_cost + dinner_cost; 
    }

    return {total_spent_meal, total_allowed_meal};

}

int main(){
    MealExpense result = calculate_meal_expense(1, "06:30", "14:25");
    cout << result.total_spent_meal << " " << result.total_allowed_meal << endl;
    return 0;

}

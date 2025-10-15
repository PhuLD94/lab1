#include <bits/stdc++.h>
using namespace std;

const float BREAKFAST_ALLOWANCE = 9.0;
const float LUNCH_ALLOWANCE = 12.0;
const float DINNER_ALLOWANCE = 16.0;

struct MealExpense {
    float total_spent_meal;
    float total_allowed_meal;
};

MealExpense calculateMealExpense(int total_day_travel, string departure_time_string, string arrival_time_string) {
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


//Function for days spent on the trip
int getTripDays()
{
    int days;
    do
    {
        cout << "Enter the total number of days spent on the trip: ";
        cin >> days;
        if(days < 1)
        cout << "Error: The number of days cannot be less than 1. Enter again." << endl;
       
    } while (days < 1);
    return days;
      
}


//Function for airfare
double getAirFare(double totalExpense, double totalAllowed){
    double airFare;
    do 
    {
        cout << "The amount of round-trip airfare: $" << endl;
        cin >> airFare;
        
        if(airFare < 0)
          cout << "Error: The amount of round-trip airfare must be greater than 0" << endl;
        
    }while (airFare < 0);
    return airFare;
    totalAllowed+=airFare;
    totalExpense+=airFare;
}
//Function for car rentals
double getCarRental(double totalExpense , double totalAllowed)
{
    double carRental;
    do
    {
        cout << "The amount of any car rentals: $" << endl;
        cin >> carRental;
        if(carRental < 0)
          cout << "Error: The amount of car rental must be greater than 0" << endl;
        
    } while (carRental < 0);
    totalAllowed+=carRental;
    totalExpense+=carRental;
    return carRental;
    

    
}

struct TotalTime {
    string departure;
    string arrival;
};

TotalTime totaltime (){
    string departure_time, arrival_time;
    int deph, depm, arrh, arrm;
    do{
        cout << "Enter the departure time: \n";
        cin >> departure_time;
        cout << "Enter arrival time  : \n";
        cin >> arrival_time;
        deph = stoi(departure_time.substr(0,2), 0);
        depm = stoi(departure_time.substr(3,2), 0);
        arrh = stoi(arrival_time.substr(0,2), 0);
        arrm = stoi(arrival_time.substr(3,2), 0);
        if (deph < 0 || deph >= 24 || depm < 0 || depm >= 60  || arrh < 0 || arrh >= 24 || arrm < 0 || arrm >= 60 )
        {   cout << "Check: " << endl;}
    } while (deph < 0 || deph >= 24 || depm < 0 || depm >= 60  || arrh < 0 || arrh >= 24 || arrm < 0 || arrm >= 60);
    cout << "Departure time: " << departure_time << "\n Arrival time: " << arrival_time << endl;
    return {departure_time, arrival_time};
} 

  

double Conference_Seminar_fee(){
    double registration_fees;
    do{
        cout<<"Enter the fee for Conference or Seminar registration: $";
        cin>>registration_fees;
       } while(registration_fees < 0);
    return registration_fees;
}

double ParkingFee(double &exceed_Parking){
    
    int PDays;
    double Allowed_Parking_Fee = 6;
    double Used_per_day;
    double Total_Allowed_fees;
    double Total_used_fees = 0;
    do{
        cout<<"Enter the number of days spent at parking: ";
        cin>>PDays; 
       } while(PDays <= 0);
       Total_Allowed_fees =  Allowed_Parking_Fee * PDays;
    for(int i = 1; i <= PDays; i++){
        do{
        cout<<"Enter the Parking fee expenses " <<i<<" : $";
        cin>>Used_per_day;
          }while(Used_per_day < 0);
      if(Used_per_day > 10){
        exceed_Parking = exceed_Parking + Used_per_day - 6;
        }
      Total_used_fees = Total_used_fees + Used_per_day;
    }
    return Total_used_fees;
}	
double TaxiFee(double &exceed_Taxi){
    int TDays;
    double Allowed_Taxi_Fee = 10;
    double Used_per_day;
    double Total_Allowed_fees;
    double Total_Used_Fees = 0;
    do{
        cout<<"Enter the number of days spent on taxi: ";
        cin>>TDays; 
       } while(TDays <= 0);
       Total_Allowed_fees = Allowed_Taxi_Fee * TDays;
    for(int i = 1; i <= TDays; i++){
        do{
        cout<<"Enter the Taxi fee expenses " <<i<<": $";
        cin>>Used_per_day;
          }while(Used_per_day < 0);
     if(Used_per_day > 10){
            exceed_Taxi = exceed_Taxi + Used_per_day - 10;
        }
      Total_Used_Fees = Total_Used_Fees + Used_per_day;
    }
    return Total_Used_Fees;
}


double Hotel_expenses(double &Exceed_Hotel_fee){
    int Travelled_Night;
    double Allowed_Hotel_fees_per_night = 90;
    double Used_per_night;
    double Total_Allowed_fees;
    double Total_Used_fees = 0;
    
    do{
        cout<<"Enter the night spent at the Hotel: ";
        cin>>Travelled_Night; 
       } while(Travelled_Night <= 0);
       Total_Allowed_fees = Allowed_Hotel_fees_per_night * Travelled_Night;
    for(int i = 1; i <= Travelled_Night; i++){
        do{
        cout<<"Enter the Hotel expenses in the " <<i<<" night: $";
        cin>>Used_per_night;
          }while(Used_per_night < 0);
        if(Used_per_night > 90){
            Exceed_Hotel_fee = Exceed_Hotel_fee + Used_per_night - 90;
        }
      Total_Used_fees = Total_Used_fees + Used_per_night;
    }
      
    return Total_Used_fees;
}

double calVehicleExpense(){
        double milesDriven; // số dặm đã lái
        const double RATE = 0.27; // 0.27 USD mỗi dặm
        do{
            cout << "Enter (miles driven): \n";
            cin >> milesDriven;
            if (milesDriven < 0)
              cout << "Enter again: " << endl; 
        }while (milesDriven < 0);
        double vehiclefees = RATE * milesDriven;
        cout << "Vehicle fees: $" << vehiclefees << endl;
        return vehiclefees;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double totalExpenses=0.0;
    double totalAllowed=0.0;
    // Your code here
    int trip_days = getTripDays();
    getAirFare(totalExpenses, totalAllowed);
    TotalTime time = totaltime();
    double car_rental = getCarRental(totalExpenses, totalAllowed);
    double exceed_Parking = 0;
    double exceed_Taxi = 0;
    double exceed_hotel = 0;
    double vehicle_fee = calVehicleExpense();
    double parking_fee=ParkingFee(exceed_Parking);
    double taxi_fee=TaxiFee(exceed_Taxi);
    double registration_fees =Conference_Seminar_fee();
    MealExpense meal = calculateMealExpense(trip_days, time.departure, time.arrival);
    double Exceed_Hotel_fee = 0;
    double hotel_fee = Hotel_expenses(Exceed_Hotel_fee);
    cout<<"The fee for Conference or Seminar registration is: $"<< registration_fees << endl;
    cout<<"The total Hotel expenses are: $"<< hotel_fee <<endl;
    cout<<"The exceed fee is: $"<< Exceed_Hotel_fee;
    totalExpenses = car_rental + vehicle_fee + parking_fee + taxi_fee + registration_fees + hotel_fee + meal.total_spent_meal;
    totalAllowed = meal.total_allowed_meal;
    // ---------- Results ----------
    cout << "\n========== SUMMARY ==========\n";
    cout << "Total expenses:           $" << (totalExpenses) << "\n";
    cout << "Total allowable expenses: $" << (totalAllowed)  << "\n";

    if (totalExpenses > totalAllowed) {
        cout << "Excess to be reimbursed by employee: $" <<(totalExpenses - totalAllowed) << "\n";
    } else if (totalAllowed > totalExpenses) {
        cout << "Amount saved by employee: $"<< (totalAllowed - totalExpenses) << "\n";
    } else {
        cout << "Expenses exactly match the allowance.\n";
    }
    cout << "============================\n";
    
    return 0;
}

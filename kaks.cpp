#include <bits/stdc++.h>
using namespace std;



struct MealExpense {
    float total_spent_meal;
    float total_allowed_meal;
};

struct ParkingFee{
    double total_expense_parking;
    double total_allowed_parking;
};

struct TaxiFee{
    double total_expense_taxi;
    double total_allowed_taxi;
};

struct HotelExpense{
    double total_expense_hotel;
    double total_allowed_hotel;
};


const float BREAKFAST_ALLOWANCE = 9.0;
const float LUNCH_ALLOWANCE = 12.0;
const float DINNER_ALLOWANCE = 16.0;

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
    // float breakfast_cost = 0.0, lunch_cost = 0.0, dinner_cost = 0.0;
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

        if (breakfast_cost > BREAKFAST_ALLOWANCE){
            total_allowed_meal += BREAKFAST_ALLOWANCE;
            breakfast_cost -= BREAKFAST_ALLOWANCE;
        }
        else{
            total_allowed_meal += breakfast_cost;
            breakfast_cost = 0.0;
        } 

        if (lunch_cost > LUNCH_ALLOWANCE){
            total_allowed_meal += LUNCH_ALLOWANCE;
            lunch_cost -= LUNCH_ALLOWANCE;
        }
        else{
            total_allowed_meal += lunch_cost;
            lunch_cost = 0.0;
        } 

        if (dinner_cost > DINNER_ALLOWANCE){
            total_allowed_meal += DINNER_ALLOWANCE;
            dinner_cost -= DINNER_ALLOWANCE;
        }
        else{
            total_allowed_meal += dinner_cost;
            dinner_cost = 0.0;
        }

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
double getAirFare(){
    double airFare;
    do 
    {
        cout << "The amount of round-trip airfare: $" << endl;
        cin >> airFare;
        
        if(airFare < 0)
          cout << "Error: The amount of round-trip airfare must be greater than 0" << endl;
        
    }while (airFare < 0);
    return airFare;
   
}
//Function for car rentals
double getCarRental()
{
    double carRental;
    do
    {
        cout << "The amount of any car rentals: $" << endl;
        cin >> carRental;
        if(carRental < 0)
          cout << "Error: The amount of car rental must be greater than 0" << endl;
        
    } while (carRental < 0);
    
    return carRental;
    

    
}

struct TotalTime {
    string departure;
    string arrival;
};

TotalTime totalTime (){
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

  

double getConference(){
    double registration_fees;
    do{
        cout<<"Enter the fee for Conference or Seminar registration: $";
        cin>>registration_fees;
       } while(registration_fees < 0);
    return registration_fees;
    cout<<"The fee for Conference or Seminar registration is: $"<< registration_fees << endl;
}



ParkingFee calculateParkingFee(){
    
    int PDays;
    double Allowed_Parking_Fee = 6;
    double used_per_day;
    double total_allowed_parking;
    double total_expense_parking = 0;
    do{
        cout<<"Enter the number of days spent at parking: ";
        cin>>PDays; 
       } while(PDays <= 0);
       total_allowed_parking =  Allowed_Parking_Fee * PDays;
    for(int i = 1; i <= PDays; i++){
        do{
        cout<<"Enter the Parking fee expenses " <<i<<" : $";
        cin>>used_per_day;
          }while(used_per_day < 0);
      
      total_expense_parking += used_per_day;
    }
    return {total_expense_parking,total_allowed_parking};
}	


TaxiFee calculateTaxiFee(){
    int TDays;
    double Allowed_Taxi_Fee = 10;
    double Used_per_day;
    double total_allowed_taxi;
    double total_expense_taxi = 0;
    do{
        cout<<"Enter the number of days spent on taxi: ";
        cin>>TDays; 
       } while(TDays <= 0);
       total_allowed_taxi = Allowed_Taxi_Fee * TDays;
    for(int i = 1; i <= TDays; i++){
        do{
        cout<<"Enter the Taxi fee expenses " <<i<<": $";
        cin>>Used_per_day;
          }while(Used_per_day < 0);
     
      total_expense_taxi +=  Used_per_day;
    }
    return {total_expense_taxi, total_allowed_taxi};
}


HotelExpense calculateHotelExpense(){
    int Travelled_Night;
    double Allowed_Hotel_fees_per_night = 90;
    double used_per_night;
    double total_allowed_hotel;
    double total_expense_hotel = 0;
    
    do{
        cout<<"Enter the night spent at the Hotel: ";
        cin>>Travelled_Night; 
       } while(Travelled_Night <= 0);
       total_allowed_hotel = Allowed_Hotel_fees_per_night * Travelled_Night;
    for(int i = 1; i <= Travelled_Night; i++){
        do{
        cout<<"Enter the Hotel expenses in the " <<i<<" night: $";
        cin>>used_per_night;
          }while(used_per_night < 0);
        
        
      total_expense_hotel  += used_per_night;
    }
      
    return {total_expense_hotel,total_allowed_hotel};
    
    
}

double calculateVehicleExpense(){
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
    
    double total_expenses=0.0;
    double total_allowed=0.0;
    // Your code here
    int trip_days = getTripDays();
    TotalTime time =  totalTime();
    double car_rental = getCarRental();
    double air_fare=getAirFare();
    double exceed_parking = 0;
    double allowed_parking=0;
    double exceed_taxi = 0;
    double allowed_taxi=0;
    double exceed_hotel = 0;
    double exceed_hotel_fee = 0;

    double vehicle_fee = calculateVehicleExpense();
    
    ParkingFee parking=calculateParkingFee();
    TaxiFee taxi=calculateTaxiFee();
    double registration_fees =getConference();
    HotelExpense hotel = calculateHotelExpense();
    MealExpense meal = calculate_meal_expense(trip_days, time.departure, time.arrival);
    
    //
    total_expenses=air_fare + car_rental + vehicle_fee + parking.total_expense_parking + taxi.total_expense_taxi + registration_fees + hotel.total_expense_hotel + (meal.total_spent_meal+meal.total_allowed_meal);
    total_allowed =air_fare + car_rental + vehicle_fee + parking.total_allowed_parking + taxi.total_allowed_taxi + registration_fees + hotel.total_allowed_hotel+ meal.total_allowed_meal;

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
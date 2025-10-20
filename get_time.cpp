#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "main.h"
using namespace std;





// Hàm nhập 1 mốc thời gian (giờ, phút)
void readTime(const string &label, int &hour, int &minute) {
    while (true) {
        cout << "Enter " << label << " time (HH MM): ";
        cin >> hour >> minute;

        if (cin.fail()|| hour < 0 || hour >= 24 || minute < 0 || minute >= 60) {
            cout << " Invalid time. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        } else break;
    } 
}

// Hàm chính lấy thời gian khởi hành và đến nơi
void getTime(int &depH, int &depM, int &arrH, int &arrM) {
    cout << "Enter Travel Times\n";
    readTime("departure", depH, depM);
    readTime("arrival", arrH, arrM);
    cout << "Departure: " << depH << ":" << depM<<endl;
    cout << "Arrival  : " << arrH << ":" << arrM << endl;
}

#include <iostream>
#include "date.h"
using namespace std;

int months[12][2] = {{1,31}, {2,28}, {3,31}, //jan-march
                     {4,30},{5,31},{6,30}, //april-june
                     {7,31},{8,31},{9,30}, //july-sept
                     {10,31},{11,30},{12,31}}; //oct-dec

bool validDate(int month, int day, int year) {

    if ((months[month-1][1]  >= day && day > 0) && //if 0 < d < 31 in (m,d)
        (12 >= month && month > 0) && year > 0) { //if 0 < m <= 12
        cout << "valid month" << endl;
        return true;
    }
    return false;
}
Date::Date() {
    format = 'd';
    day = 1;
    month = 1;
    year = 2000;
}
Date::Date(int m, int d, int y) {
    format = 'd';
    if (validDate(m,d, y)) {
        day = d;
        month = m;
        year = y;
    } else cout << "Invalid date entered." << endl;
    cout << "initial date: " << month << "/" << day << "/" << year << endl;

}

int Date::GetMonth() {
    return month;
}

int Date::GetDay() {
    return day;
}

int Date::GetYear() {
    return year;
}

bool Date::Set(int m, int d, int y) {
    if (validDate(m,d, y)) {
        month = m;
        day = d;
        year = y;
        return true;
    }
    return false;
}

void Date::Increment(int numDays) { //
    while (numDays > 0) {
        int daysLeftInMonth = months[month-1][1] - day; //days left in month
        if ((months[month-1][1] - day) <= numDays) { //if (days left in current month) < increment, that means change month
            cout << "value in numDays: " << numDays << endl;
            //case: amount of days is less than a month but still carries into the next month
            numDays -= (months[month-1][1] - day + 1); //delete the amount of days in that month from numDays
            month += 1;
            day = 1;

            cout << "days left in numDays: " << numDays << endl;
        } else {
            day += numDays; //if month is not being changed, just add days left to current day.
            numDays = 0;
        }
        if (month > 12) {
            year += 1;
            month = 1;
        }
    }
    cout << "date: " << month << "/" << day << "/" << year << endl;
}







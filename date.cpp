#include <iostream>
#include "date.h"
#include <string>
using namespace std;

//is code okay

int months[12][2] = {{1,31}, {2,28}, {3,31}, //jan-march
                     {4,30},{5,31},{6,30}, //april-june
                     {7,31},{8,31},{9,30}, //july-sept
                     {10,31},{11,30},{12,31}}; //oct-dec


string monthWords[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
bool validDate(int month, int day, int year) {
    if ((months[month-1][1]  >= day && day > 0) && //if 0 < d < 31 in (m,d)
        (12 >= month && month > 0) && year > 0) { //if 0 < m <= 12
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
    } else {
        day = 1;
        month = 1;
        year = 2000;
    }
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

void Date::Increment(int numDays) {
    while (numDays > 0) {
        //if year is not century year
        //if year is century year and divisible by 400
        if (year % 100 == 0) { //if year is century year
            if (year % 400 == 0) { //if year is century leap year
                months[1][1] = 29;
            }
        } else {
            if (year % 4 == 0) {
                months[1][1] = 29;
            } else {
                months[1][1] = 28;
            }
        }

        if ((months[month-1][1] - day) <= numDays) { //if (days left in current month) < increment, that means change month
            //case: amount of days is less than a month but still carries into the next month
            numDays -= (months[month-1][1] - day + 1); //delete the amount of days in that month from numDays
            month += 1;
            day = 1;
        } else {
            day += numDays; //if month is not being changed, just add days left to current day.
            numDays = 0;
        }
        if (month > 12) {

            year += 1;
            month = 1;

        }
    }
}

int Date::Compare(const Date &d) {
    if (year > d.year) return 1;
    if (year < d.year) return -1;
    if (year == d.year) {
        if (month > d.month) return 1;
        if (month < d.month) return -1;
        if (month == d.month) {
            if (day > d.day) return 1;
            if (day <= d.day) return 0;
        }
    }
    return 0;
}

bool Date::SetFormat(char f) {
    if (f == 'd' || f == 'D') {
        format = 'd';
        return true;
    } else if (f=='t' || f == 'T') {
        format = 't';
        return true;
    } else if (f=='l' || f == 'L') {
        format = 'l';
        return true;
    } else return false;
}

void Date::Show() {
    if (format == 'd') {
        cout << month << "/" << day << "/" << year << endl;
    } else if (format == 't') {
        string DAY_DIGIT, MONTH_DIGIT, YEAR_DIGIT;
        if (day < 10) cout << 0;
        cout << day << "/";
        if (month < 10) cout << 0;
        cout << month << "/";
        if (year % 100 < 10) {
            cout << "0";
        }
        cout << (year%100) << endl;
    } else if (format == 'l') {
        cout << monthWords[month - 1] << " " << day << ", " << year << endl;
    }
}

void Date::Input() {
    char slash;
    int m,d,y;
    cout << "Please enter a date... " ;
    cin >> m >> slash >> d >> slash >> y;
    if (slash != '/') {
        cout << "Wrong format!" << endl;
    } else {
        if (validDate(m,d,y)) {
            month = m;
            day = d;
            year = y;
        }
    }
}
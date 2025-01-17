#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
    Date(){}
    // TODO: Define one argument constructor here
    Date(int y) : year(y), month(1), day(1) {}

    // TODO: Define two argument constructor here
    Date(int y, int m) : year(y), month(m), day(1) {}

    Date(int y, int m, int d) : year(y), month(m), day(d) {}


    Date& addMonths(int n) {
        year += (month + n) / 12;
        month = (month + n) % 12;
        return *this;
    }

    Date& addDays(int n) {
        int d = daysToDate() + n;
        int y = year, m = 1;
        while (d > daysInMonth(y, m)) {
            d -= daysInMonth(y, m);
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        day = d;
        month = m;
        year = y;

        return *this;
    }

    static bool isLeapYear(int y) {
        return (y % 4 || (y % 100 == 0 && y % 400)) ? false : true;
    }

    string toString() {

        const string monthNames[] = {
            "Jan", "Feb", "Mar", "Apr", "May", "June",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        }; 
        ostringstream monthString;
        monthString << monthNames[month - 1] << " " << day << ", " << year << endl;
        return monthString.str();

        // TODO: complete this function implementation here.
        
    }

    int daysToDate() {
        int days_in_month[]{ 31, isLeapYear(year) ? 29 : 28, 31,
                            30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int days = 0;
        for (int m = 0; m < month - 1; m++) {
            days += days_in_month[m];
        }
        days += day;
        return days;
    }


    // TODO: Overload operator+ here

    friend Date operator+(Date& d, int n) {
        Date newDate = d;
        newDate.addDays(n);
        return newDate;
    }

    // TODO: overload operator<< here
    friend ostream& operator<<(ostream& out, Date& d) {
        out << d.toString();
        return out;
    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }
private:
    int year, month, day;

    static int daysInMonth(int y, int m) {
        int days_in_month[]{ 31, isLeapYear(y) ? 29 : 28, 31,
                            30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days_in_month[m - 1];
    }
};


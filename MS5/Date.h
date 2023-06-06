// Final Project Milestone 5
//
// Version 1.0
// Date    2023-04-07
// Author    Suna Kim
// File name    Date.h
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
#include "Error.h"
#include "POS.h"

using namespace std;

namespace sdds {
    class Date {
        int m_year;
        int m_month;
        int m_day;
        int m_hour;
        int m_minute;
        bool m_dateOnly;
        Error m_error;

    public:
        Date();
        Date(int year, int month, int day);
        Date(int year, int month, int day, int hour);
        Date(int year, int month, int day, int hour, int mins);
        void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
        int uniqueDateValue(int year, int mon, int day, int hour, int min) const;
        int daysOfMonth(int year, int month) const;

        operator int() const;
        operator bool() const;

        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator>=(const Date& right) const;

        void valid();
        Date& dateOnly(bool dateOnly);
        Error& error();
        ostream& display(ostream& os) const;
        istream& read(istream& istr = cin);
    };
    ostream& operator<<(ostream& ostr, const Date& right);
    istream& operator>>(istream& istr, Date& right);
}

#endif

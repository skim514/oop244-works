// Final Project Milestone 4
//
// Version 1.0
// Date    2023-03-12
// Author    Suna Kim
// File name    Date.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include "Date.h"

using namespace std;

namespace sdds {
    Date::Date() {
        m_dateOnly = false;
        getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
        m_error = Error();
    }
    Date::Date(int year, int month, int day) {
        m_year = year;
        m_month = month;
        m_day = day;
        m_hour = 0;
        m_minute = 0;
        m_dateOnly = true;
        m_error = Error();
        valid();
    }
    Date::Date(int year, int month, int day, int hour) {
        m_year = year;
        m_month = month;
        m_day = day;
        m_hour = hour;
        m_minute = 0;
        m_dateOnly = false;
        m_error = Error();
        valid();
    }
    Date::Date(int year, int month, int day, int hour, int mins) {
        m_dateOnly = false;
        m_error = Error();

        m_year = year;
        m_month = month;
        m_day = day;
        m_hour = hour;
        m_minute = mins;
        valid();// 여기서 검증하는 이유.
    }
    void Date::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;

        if (dateOnly)
        {
            hour = min = 0;
        }
        else
        {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
    int Date::uniqueDateValue(int year, int mon, int day, int hour, int min)const {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }
    int Date::daysOfMonth(int year, int month) const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    bool Date::operator==(const Date& right) const {
        bool result = false;
        if (int(*this) == int(right))
        {
            result = true;
        }
        return result;
    }
    bool Date::operator!=(const Date& right) const {
        bool result = false;
        if (int(*this) != int(right))
        {
            result = true;
        }
        return result;
    }
    bool Date::operator<(const Date& right) const {
        bool result = false;
        if (int(*this) < int(right))
        {
            result = true;
        }
        return result;
    }
    bool Date::operator>(const Date& right) const {
        bool result = false;
        if (int(*this) > int(right))
        {
            result = true;
        }
        return result;
    }
    bool Date::operator<=(const Date& right) const {
        bool result = false;
        if (int(*this) <= int(right))
        {
            result = true;
        }
        return result;
    }
    bool Date::operator>=(const Date& right) const {
        bool result = false;
        if (int(*this) >= int(right))
        {
            result = true;
        }
        return result;
    }
    void Date::valid() {
        if (m_year < MIN_YEAR || m_year > MAX_YEAR)
        {
            m_error = "Invalid Year";
        }
        else
        {
            if (m_month < 1 || m_month > 12)
            {
                m_error = "Invalid Month";
            }
            else
            {
                if (m_day < 1 || m_day > daysOfMonth(m_year, m_month))
                {
                    m_error = "Invalid Day";
                }
                else
                {
                    if (!m_dateOnly)
                    {
                        if (m_hour < 1 || m_hour > 23)
                        {
                            m_error = "Invalid Hour";
                        }
                        else
                        {
                            if (m_minute < 0 || m_minute > 59)
                            {
                                m_error = "Invlid Minute";
                            }
                        }
                    }
                }
            }
        }
    }
    Date& Date::dateOnly(bool dateOnly) {
        if (dateOnly)
        {
            m_dateOnly = true;
            m_hour = 0;
            m_minute = 0;
        }
        return *this;
    }
    Date::operator bool() const {
        return !m_error;
    }

    Date::operator int() const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
    }
    Error& Date::error() {
        return m_error;
    }
    ostream& Date::display(ostream& os) const {//콘솔출력과 파일에 출력  둘다하기 위해선 매개변수를 통해서 하는것임(여기서는 os). no cout(얘는 콘솔에만 출력)
        if (m_dateOnly)
        {
            if (m_error)
            {
                os << m_error << "(" << m_year << "/";
                os.fill('0');
                os.width(2);
                os << m_month << "/";
                os.fill('0');
                os.width(2);
                os << m_day << ")";
            }
            else
            {
                os << m_year << "/";
                os.fill('0');
                os.width(2);
                os << m_month << "/";
                os.fill('0');
                os.width(2);
                os << m_day;
            }
        }
        else
        {
            if (m_error)
            {
                os << m_error << "(" << m_year << "/";
                os.fill('0');
                os.width(2);
                os << m_month << "/";
                os.fill('0');
                os.width(2);
                os << m_day << ", ";
                os.fill('0');
                os.width(2);
                os << m_hour << ":";
                os.fill('0');
                os.width(2);
                os << m_minute << ")";
            }
            else
            {
                os << m_year << "/";
                os.fill('0');
                os.width(2);
                os << m_month << "/";
                os.fill('0');
                os.width(2);
                os << m_day << ", ";
                os.fill('0');
                os.width(2);
                os << m_hour << ":";
                os.fill('0');
                os.width(2);
                os << m_minute;
            }
        }
        return os;
    }
    istream& Date::read(istream& istr) {
        if (!m_error)
        {
            m_error.clear();
            m_year = m_month = m_day = m_hour = m_minute = 0;

            istr >> m_year;
            if (istr.fail())
            {
                m_error = "Cannot read year entry";
            }
            else
            {
                istr.ignore();
                istr >> m_month;
                if (istr.fail())
                {
                    m_error = "Cannot read month entry";
                }
                else
                {
                    istr.ignore();
                    istr >> m_day;
                    if (istr.fail())
                    {
                        m_error = "Cannot read day entry";
                    }
                    else
                    {
                        if (!m_dateOnly)
                        {
                            istr.ignore();
                            istr >> m_hour;
                            if (istr.fail())
                            {
                                m_error = "Cannot read hour entry";
                            }
                            else
                            {
                                istr.ignore();
                                istr >> m_minute;
                                if (istr.fail())
                                {
                                    m_error = "Cannot read minute entry";
                                }
                            }
                        }
                    }
                }
            }
        }
        if (!m_error)
        {
            valid();
        }
        return istr;
    }
    ostream& operator<<(ostream& ostr, const Date& right) {
        return right.display(ostr);
    }
    istream& operator>>(istream& istr, Date& right) {
        return right.read(istr);
    }
}
/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.h
// Version 1.0
// Date    2023/02
// Author Suna Kim
// Description
// Tests the Bus module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_

using namespace std;

namespace sdds{
    
    const double fare = 125.34;
    
    class Bus{
        int m_noOfPassangers;
        int m_noOfSeat;
        void setOutOfService();
        void drawBus(int seats, int noOfPassengers, ostream& ostr) const;
        
    public:
        Bus(int size = 20, int m_noOfPassangers = 0);
        Bus& set(int size, int m_noOfPassangers);
        
        ostream& display(ostream& ostr = cout) const;
        istream& read(istream& istr = cin);
        
        operator bool() const;
        operator int() const;
        operator double() const;
        
        bool operator--();
        bool operator++();
        bool operator--(int);
        bool operator++(int);
        
        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);
        bool operator==(const Bus& right) const;
    };
    int operator+(int left, const Bus& right);
    ostream& operator<<(ostream& ostr, const Bus& right);
    istream& operator>>(istream& istr, Bus& right);
}

#endif

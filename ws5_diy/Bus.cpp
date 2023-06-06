/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bus.h"

using namespace std;

namespace sdds{
    void Bus::setOutOfService(){
        m_noOfPassangers = -1;
        m_noOfSeat = -1;
    }
    //constructor
    Bus::Bus(int seats, int noOfPassangers){
        if(seats % 2 == 0 && seats >= 10 && seats <= 40 && noOfPassangers >= 0 && noOfPassangers <= seats){
            set(seats, noOfPassangers);
        }
        else{
            setOutOfService();
        }
    }
    //Member function
    Bus& Bus::set(int seats, int noOfPassangers){
        m_noOfSeat = seats;
        m_noOfPassangers = noOfPassangers;
        return *this;
    }
    
    ostream& Bus::display(ostream& ostr) const{
        if (m_noOfSeat % 2 == 0 && m_noOfSeat >= 10 && m_noOfSeat <= 40 && m_noOfPassangers >= 0 && m_noOfPassangers <= m_noOfSeat) {
            drawBus(m_noOfSeat, m_noOfPassangers, ostr);
            cout << "Total Fare Price: ";
            cout << fixed; cout.precision(2);
            cout << operator double() << endl;
        }
        else{
            cout << "Out of service!" << endl;
        }
        return ostr;
    }
    void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
      int i, p;
      ostr.fill('_');
      ostr.width((seats / 2) * 3 + 4);
      ostr << "_";
      ostr << endl << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
      ostr << "|_\\_" << endl;
      ostr << "| ";
      ostr.fill(' ');
      ostr.width(((seats / 2) * 3 - 14) / 2);
      ostr << " " << "Seneca College";
      ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
      ostr << " " << "    )" << endl;
      ostr << "`---OO";
      ostr.fill('-');
      ostr.width((seats / 2) * 3 - 5);
      ostr << "-" << "O---'" << endl;
    }
    istream& Bus::read(istream& istr){
        
        istr >> m_noOfSeat;
        istr.ignore(5,','); //(갯수, 이거 전까지)
        istr >> m_noOfPassangers;
        istr.ignore(5,'\n');
        if (m_noOfSeat % 2 == 0 && m_noOfSeat >= 10 && m_noOfSeat <= 40 && m_noOfPassangers >= 0 && m_noOfPassangers <= m_noOfSeat) {
            set(m_noOfSeat, m_noOfPassangers);//컨스트럭터는 항상 셋팅함
        }
        else{
            setOutOfService();
        }
        return istr;
    }
    //Type conversion operator overloads
    Bus::operator bool() const{
        return m_noOfSeat >= 0;
    }
    Bus::operator int() const{
        return (bool(*this)) ? m_noOfPassangers : -1;
    }
    Bus::operator double() const{
        double totalFare = 0.0;
        totalFare += fare * m_noOfPassangers;
        return (bool(*this)) ? totalFare : -1.0;
    }
    //Unary operator overloads
    //prefix
    bool Bus::operator--(){
        bool result = true;
        if (!bool(*this) || m_noOfPassangers == 0) { //bool(*this)이 자체로 트루 펄스를 가져오는게 아니니까 이렇게 써야함.
            result = false;
        }
        else{
            m_noOfPassangers--;
        }
        return result;
    }
    bool Bus::operator++(){
        bool result = true;
        if (!bool(*this) || m_noOfPassangers == m_noOfSeat) {
            result = false;
        }
        else{
            m_noOfPassangers++;
        }
        return result;
    }
    //postfix
    bool Bus::operator--(int){
        bool result = true;
        if (!bool(*this) || m_noOfPassangers == 0) {
            result = false;
        }
        else{
            --m_noOfPassangers;
        }
        return result;
    }
    bool Bus::operator++(int){
        bool result = true;
        if (!bool(*this) || m_noOfPassangers == m_noOfSeat) {
            result = false;
        }
        else{
            ++m_noOfPassangers;
        }
        return result;
    }
    //Binary Member Operators
    Bus& Bus::operator=(int value){
        m_noOfPassangers = value;
        if (m_noOfPassangers > m_noOfSeat) {
            setOutOfService();
        }
        return *this;
    }
    Bus& Bus::operator+=(int value){
        if (bool(*this)) {
            m_noOfPassangers += value;
        }
        else if(m_noOfPassangers > m_noOfSeat){
            setOutOfService();
        }
        return *this;
    }
    Bus& Bus::operator+=(Bus& right){
        if (bool(*this) && bool(right)) {
            m_noOfPassangers += right.m_noOfPassangers;
            right.m_noOfPassangers = 0;
            if (m_noOfSeat - m_noOfPassangers < right.m_noOfPassangers){
                right.m_noOfPassangers -= m_noOfSeat - m_noOfPassangers;
                m_noOfPassangers += m_noOfSeat - m_noOfPassangers;
            }
        }
        return *this;
    }
    bool Bus::operator==(const Bus& right) const{
        bool result = false;
        if (bool(*this) && bool(right) && m_noOfPassangers == right.m_noOfPassangers) {
            result = true;
        }
        return result;
    }
    //Helper binary operator overloads
    int operator+(int left, const Bus& right){
        return bool(right) ? int(right) + left : 0;
    }
    ostream& operator<<(ostream& ostr, const Bus& right){
        return right.display(ostr);
    }
    istream& operator>>(istream& istr, Bus& right){
        return right.read(istr);
    }
}

/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Toys.cpp
// Version 1.0
// Date    2023/02/04
// Author Suna Kim
// Description
// Tests Toys module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
//#include "Store.h"
#include "Toys.h"

using namespace std;

namespace sdds{
    //After checking the validity, this method will set the received values to the appropriate data members. Otherwise will be set to an empty state.
    void Toys::addToys(const char* tname, int sku, double price,int age)
        {
            if (tname != nullptr && sku > 9999999 && sku < 99999999 && price >= 0.0 && age >= 0)
            {
                //validation
                strcpy(m_tname, tname);
                m_sku = sku;
                m_price = price;
                m_age = age;
                m_onSale = false;//모든 품목이 세일하지 않음. 세일하는것만 트루를 주어야함. 그래서 폴스.

            }
            else
            {
                empty();
            }
        }
    //It will assign the received value to the data member m_onSale.
    void Toys::isSale(bool sale){
        m_onSale = sale;
    }
    //It will decrease the toys price to 20% then the original price.
    void Toys::calSale(){
        m_price = m_price * 0.8;
    }
    //If a Toy object is valid
    //a) prints m_tname with width 15, left justified and filled with empty spaces.
    //b) prints m_sku with width 10
    //c) prints m_age with width 6
    //d) prints m_price with width 12 and after the decimal point 2 digits.
    //e) If the toy is on sale it will print "On Sale" with width 10. Otherwise, print empty spaces with width 8.
    //otherwise prints, "Invalid Toy".
    void Toys::display()const{
        if (m_tname[0] != '\0') {
            cout.width(15);
            cout.setf(ios::left);
            cout << m_tname;
            cout.fill(' ');
            cout.unsetf(ios::left);//a
            cout.width(10);
            cout << m_sku; //b
            cout.width(6);
            cout << m_age; //c
            cout.width(12);
            cout << fixed; cout.precision(2);
            cout << m_price;
            if (m_onSale == true) {
                cout.width(10);
                cout << "On Sale";
                cout << " ";
                
            } else {
                cout.width(8);
                cout << " ";
            }
        }
        else{
            cout << "Invalid Toy";
        }
        cout << endl;
    }
    void Toys::empty(){
        m_tname[0] = '\0';
        m_sku = 0;
        m_price = 0;
        m_age = 0;
        m_onSale = false;
    }
    bool Toys::checkToFind(int sku){
        bool result = false;
        if (sku == m_sku) {
            result = true;
        }
        return result;
    }
}

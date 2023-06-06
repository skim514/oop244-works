/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Store.cpp
// Version 1.0
// Date    2023/02/04
// Author Suna Kim
// Description
// Tests Store module
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
#include "Store.h"
#include "Toys.h"

using namespace std;

namespace sdds{
    //This will set the store name and the number of toys that could be added to the store. For invalid value, it will set the values to an empty state.
    void Store::setStore(const char* sName, int no){
        if (sName != nullptr) {
            strcpy(m_sName, sName); //스트링카피 제발 쓰자!! 좀!!!!!!
            m_noOfToys = no;
            m_addToys = 0;//리셋
        }
        else{
            setEmpty();
        }
    }
    //This will add the toys one at a time to the m_toy array and will keep track of the number of toys added. Toys will be added until num of added toys is less than m_noOfToys
    void Store::setToys(const char* tname, int sku, double price, int age){
        if (m_addToys < m_noOfToys)
        {
            m_toy[m_addToys].addToys(tname, sku, price, age);
            //m_toy[m_addToys].addToys(tname, sku, price, age);//[인덱스: 에드토이즈 만큼].에드토이즈 함수 콜
            m_addToys++;
        }
    }
    //If a Store object is valid
    //a) prints "*" with width 60 and fill with "*", then print m_sName and a new line.
    //b) prints "*" with width 60 and fill with "*", then prints "list of the toys" and a new line.
    //c) prints "SKU" with width 30 and fill with empty spaces
    //d) prints "Age" with width 10 and fill with empty spaces
    //e) prints "Price" with width 11 and fill with empty spaces
    //f) prints "Sale" with width 10 and fill with empty spaces then a new line
    //g) prints all the toys information. For details see the sample output.
    //otherwise prints, "Invalid Store" then a new line.
    void Store::display() const{
        int i = 0;
        if (m_sName[0] != '\0' && m_noOfToys >= 0 && m_addToys >= 0) {
            cout.width(60);
            cout.fill('*');
            cout << "*" << endl;
            cout << m_sName << endl;//a
            cout.width(60);
            cout.fill('*');
            cout << "*" << endl;
            cout << "list of the toys" << endl;//b
            cout.width(30);
            cout.fill(' ');
            cout << "SKU";//c
            cout.width(10);
            cout.fill(' ');
            cout << "Age";//d
            cout.width(11);
            cout.fill(' ');
            cout << "Price";//e
            cout.width(10);
            cout.fill(' ');
            cout << "Sale" << endl;//f
        }
        if (m_sName[0] == '\0') {
            cout << "Invalid Store" << endl;
        }
        for (i = 0; i < m_noOfToys; i++) {
            cout.width(0);
            cout << "Toy[";
            cout << i + 1 << "] :";
            m_toy[i].display();
        }
    }
    //This method will go through the arrays of toys. It will match the received SKU number with the stored toys' SKU number to find out if the toys are on sale or not. If the number matches then it will pass true to the appropriate Toys method. After that, it will call the calSale() of the toys class to know the sale value.
    void Store::find(int sku){
        int i = 0;
        for (i = 0; i < m_addToys; i++) {
            if (m_toy[i].checkToFind(sku)) {
                m_toy[i].isSale(true);
                m_toy[i].calSale();
            }
        }
    }
    //set the store to an empty state
    void Store::setEmpty(){
        int i = 0;
        m_sName[0] = '\0';
        m_noOfToys = 0;
        m_addToys = 0;
        for (i = 0; i < m_addToys; i++) {//add한만큼만 돌아야지. 왜냐면 이게 추가된 만큼이니까.
            m_toy[i].empty();//얘의 존재이유. 토이클래스 변수에 직접접근을 못하기 때문에 퍼블릭함수를 만들어서 불러서 사용.
        }
    }
}

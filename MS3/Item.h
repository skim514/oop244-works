// Final Project Milestone 3
//
// Version 1.0
// Date    2023-03-26
// Author    Suna Kim
// File name    Item.h
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include <iostream>
#include "PosIO.h"
#include "POS.h"
#include "Error.h"

using namespace std;

namespace sdds{    
    class Item : public PosIO
    {
        char m_SKU[MAX_SKU_LEN+1];
        char* m_name;
        double m_price;
        bool m_isTaxed;
        int m_qty;

    protected:
        int m_displayType;
        Error m_error;
        
        
    public:
        Item();
        Item(const Item& another);//Rule of three
        Item& operator=(const Item& right);//Rule of three
        ~Item();//Rule of three
        bool operator==(const char* right) const;
        bool operator>(const Item& right) const;
        int operator+=(int right);
        int operator-=(int right);
        operator bool() const;
        ostream& write(ostream& os) const;
        ofstream& save(ofstream& os)const;
        istream& read(istream& is);
        ifstream& load(ifstream& is);
        virtual char itemType() const = 0;
        ostream& bprint(ostream& os) const;
        void setEmpty();
        
        Item& displayType(int pos);
        double cost() const;
        int quantity() const;
        Item& clear();
    };
    double operator+=(double& left, const Item& right);
}

#endif

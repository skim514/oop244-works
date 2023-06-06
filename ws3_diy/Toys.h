/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Toys.h
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
#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_
//#include "Store.h"
#define MAX_TNAME 31

namespace sdds{

    class Toys{
        char m_tname[MAX_TNAME + 1]; // toy name, up to MAX_TNAME size
        int m_sku; //SKU number, maximum 8 digits long
        double m_price;//toy price
        int m_age; //toy according to age group
        bool m_onSale; // keep track, if toys are on sale or not
        
    public:
        void addToys(const char* tname, int sku, double price,int age);
        void isSale(bool sale);
        void calSale();
        void display()const;
        void empty();
        bool checkToFind(int sku);
    };
}
#endif

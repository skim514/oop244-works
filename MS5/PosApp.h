// Final Project Milestone 5
//
// Version 1.0
// Date    2023-04-07
// Author    Suna Kim
// File name    PosApp.h
#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include "POS.h"
#include "Item.h"
#include "NonPerishable.h"
#include "Perishable.h"

namespace sdds {
    class PosApp {
        char m_fileName[128 + 1];
        Item* Iptr[MAX_NO_ITEMS];
        int nptr;
        char m_actionTitle[100+1];
        //int m_addstock;
        //bool m_loaded;

    public:
        //void operator=(const Item& right);
        
        void menu();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void printHeader();
        void POS();
        void saveRecs();
        void loadRecs();
        void bubble(Item* names[], int size);
        PosApp();
        PosApp(const char* fileName);
        ~PosApp();
        void run();
    };
}

#endif

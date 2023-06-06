// Final Project Milestone 5
//
// Version 1.0
// Date    2023-04-07
// Author    Suna Kim
// File name    PosApp.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "PosApp.h"

using namespace std;

namespace sdds {
    
    void PosApp::menu() {
        int userInput = 0;
        bool isValid = false;

        do
        {
            cout << "The Sene-Store" << endl;
            cout << "1- List items" << endl << "2- Add item" << endl << "3- Remove item" << endl;
            cout << "4- Stock item" << endl << "5- POS" << endl << "0- exit program" << endl << "> ";
            cin >> userInput;
            cin.ignore(1, '\n');
            isValid = true;
            if (cin.fail()) {
                cout << "Invalid Integer, try again: ";
                cin.clear();
                cin.ignore(10, '\n');
            }
            else if (userInput < 0 || userInput > 5) {
                cout << "[0<=value<=5], retry: > ";
            }
            else
            {
                if (userInput == 1) {
                    listItems();
                }
                else if (userInput == 2) {
                    addItem();
                }
                else if (userInput == 3) {
                    cout << ">>>> Remove Item";
                    cout.width(62);
                    cout.fill('.');
                    cout << '\n';
                    cout << "Running removeItem()" << endl;
                }
                else if (userInput == 4) {
                    cout << ">>>> Select an item to stock";
                    cout.width(50);
                    cout.fill('.');
                    cout << '\n';
                    cout << "Running stockItem()" << endl;
                }
                else if (userInput == 5) {
                    cout << ">>>> Starting Point of Sale";
                    cout.width(51);
                    cout.fill('.');
                    cout << '\n';
                    cout << "Running POS()" << endl;
                }
                else if (userInput == 0) {
                    saveRecs();
                    isValid = false;
                }
            }            
        } while (isValid);
    }
    void PosApp::addItem()
    {   
        bool done = true;
        
        strcpy(m_actionTitle, "Adding Item to the store");
        printHeader();
        do
        {
            if (nptr == MAX_NO_ITEMS)
            {
                cout << "Inventory Full!" << endl;
                done = false;
            }
            else
            {
                char tempType = 0;

                cout << "Is the Item perishable? (Y)es/(N)o: ";
                cin.get(tempType);
                cin.ignore(1, '\n');
                if (!cin.fail() && (tempType == 'Y' || tempType == 'y'))
                {
                    Iptr[nptr] = new Perishable;
                    cin >> *Iptr[nptr];
                    nptr++;
                    strcpy(m_actionTitle, "DONE!");
                    printHeader();
                    done = false;
                }
                else if (!cin.fail() && (tempType == 'N' || tempType == 'n'))
                {
                    Iptr[nptr] = new NonPerishable;
                    cin >> *Iptr[nptr];
                    nptr++;
                    strcpy(m_actionTitle, "DONE!");
                    printHeader();
                    done = false;
                }
                else
                {
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << ", try again...\n";
                    }
                }
            }
        } while (done);
    }
    void PosApp::removeItem() {

    }
    void PosApp::stockItem() {

    }
    void PosApp::listItems()
    {
        double totalAmount = 0.0;
        
        strcpy(m_actionTitle, "Listing Items");
        printHeader();
        bubble(Iptr, nptr);
        
        cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
        cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
        for (int i = 0; i < nptr; i++)
        {
            cout.width(4); cout.setf(ios::right);
            cout.fill(' ');
            cout.unsetf(ios::right);
            cout << i+1 << " | ";
            cout << Iptr[i]->displayType(POS_LIST); //마지막 인덱스 데이터 없어서 에러나는것 같음. 수정

            totalAmount += Iptr[i]->cost() * Iptr[i]->quantity();
        }

        cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
        cout << "                               Total Asset: $  |";
        cout.width(14); cout.setf(ios::right);
        cout.fill(' ');
        cout.unsetf(ios::right);
        cout << totalAmount << "|" << endl;
        cout << "-----------------------------------------------^--------------^" << endl << endl;
    }
    void PosApp::POS() {

    }
    void PosApp::printHeader()
    {
        cout << ">>>> ";
        cout.width(72);
        cout.fill('.');
        cout.setf(ios::left);
        cout << m_actionTitle << endl;
        cout.unsetf(ios::left);
    }
    void PosApp::saveRecs()
    {
        strcpy(m_actionTitle, "Saving Data");//1
        printHeader();
        cout << "Goodbye!" << endl;
        ofstream outfile(m_fileName);//2
        for (int i = 0; i < nptr; i++)//3
        {
            outfile << *Iptr[i] << endl;
        }
    }
    void PosApp::loadRecs()
    {
        strcpy(m_actionTitle, "Loading Items");//1
        printHeader();
        ifstream input(m_fileName);//2
        for (int i = 0; i < MAX_NO_ITEMS; i++)//4
        {
            delete Iptr[i];
        }
        while (!input.fail() && nptr < MAX_NO_ITEMS)//5
        {
            char tempType = 0;

            input.get(tempType); //5.1
            input.ignore();
            if (!input.fail() && tempType == 'P')
            {
                Iptr[nptr] = new Perishable;
                input >> *Iptr[nptr];
                nptr++;
            }
            else if (!input.fail() && tempType == 'N')
            {
                Iptr[nptr] = new NonPerishable;
                input >> *Iptr[nptr];
                nptr++;
            }
            input.ignore(10000, '\n');
        }        
    }
    void PosApp::bubble(Item* names[], int size)
    {
        int i, j;
        Item* temp;

        for (i = size - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (*names[j] > *names[j + 1])
                {
                    temp = names[j];
                    names[j] = names[j + 1];
                    names[j + 1] = temp;
                }
            }
        }
    }    
    PosApp::PosApp() {
        m_fileName[0] = 0;
        for (int i = 0; i < MAX_NO_ITEMS; i++)
        {
            Iptr[i] = nullptr;
        }
        nptr = 0;
        m_actionTitle[0] = 0;
    }
    PosApp::PosApp(const char* fileName) {
        strcpy(m_fileName, fileName);
        for (int i = 0; i < MAX_NO_ITEMS; i++)
        {
            Iptr[i] = nullptr;
        }
        nptr = 0;
        m_actionTitle[0] = 0;
    }
    PosApp::~PosApp() {
        int i = 0;
        for (i = 0; i < MAX_NO_ITEMS; i++)
        {
            Iptr[i]->setEmpty();
            delete Iptr[i];
        }
    }
    void PosApp::run() {

        loadRecs();
        menu();        
    }
}
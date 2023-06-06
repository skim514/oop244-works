/***********************************************************************
// Workshop 1 p2: tester program
//
// File  UI.cpp
// Version 1.0
// Date  winter 2023
// Author Suna Kim
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

/*
NAME: Suna Kim
E-MAIL: skim514@myseneca.ca
STUDENT ID: 104690227
DATE: Jan 22nd, 2023
*/

#include <iostream>
#include <cstring>
#include "GPA.h"
#include "File.h"
#include "GPAlist.h"

//call function for user input.
using namespace std; // not allowed in a ".h" file

namespace sdds {

    // flushes the keyboard
    void flushkeys() {
        while (cin.get() != '\n');
    }

    // returns true if user enter 'y' or 'Y'
    bool yes() {
        char ch = '\0';
        bool value = true;
        cin >> ch;
        flushkeys();

        if (ch == 'Y' || ch == 'y')
        {
            value = true;
        }
        else if (ch == 'N' || ch == 'n')
        {
            value = false;
        }
        return value;
    }

    void inputGPA() {
        char userOption = '\0';
        double userGPA = 0.0;
        bool isValid = true;

        cout << "Enter GPA query..." << endl;
        do
        {
            isValid = true;
            cout << "? ";
            cin >> userOption;

            if (userOption == '!')
            {
                cout << "Exit the program? (Y)es/(N)o: ";
                isValid = !yes();
            }
            else
            {
                cin >> userGPA;
                flushkeys();

                if (userOption == '>' || userOption == '<' || userOption == '~')
                {
                    displayOptionGPA(userOption, userGPA); //When the condition are matched, it should print student index.

                }
                else
                {
                    cout << "Syntax error: ? [Op][value]<ENTER>" << endl << "Op: [>,<,~,!]" << endl << "value: GPA value" << endl << endl;
                }
            }
        } while (isValid);
    }
}
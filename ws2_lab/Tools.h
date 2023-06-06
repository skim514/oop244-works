/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File    Tools.h
// Version 1.0
// Date Winter 2023
// Author  Suna Kim
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
    int openFile_r(const char filename[]); // Provided
    void closefile(); // Provided
    int noOfTraces(); // Provided

    // ADD: Declare read prototypes (4 prototypes)

    bool read(char* string);
    bool read(int& intNum);
    bool read(double& dbNum);
    bool read(char& character);

    void strCpy(char* des, const char* src); // Provided
    int strLen(const char* s); // Provided
}
#endif 

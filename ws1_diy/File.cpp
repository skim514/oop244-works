/***********************************************************************
// Workshop 1 p2: tester program
//
// File  File.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"

using namespace std; // not allowed in a ".h" file

namespace sdds {

    FILE* fptr;

    // opens the data file and returns true is successful
    bool openFile(const char fileName[]) {
        fptr = fopen(fileName, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // reads the students name from the global fptr File pointer
    // returns true if successful
    bool readName(char studentName[]) {
        return fscanf(fptr, "%[^,],", studentName) == 1; //studentName is before comma
    }

    // reads the student numbers from the global fptr File pointer
    // returns true if successful
    bool readStudentNum(int* studentNum) {
        return fscanf(fptr, "%d,", studentNum) == 1; //studentNum is before comma
    }

    // reads the gpa from the global fptr File pointer
    // returns true if successful
    bool readGPA(double* gpa) {
        return fscanf(fptr, "%lf\n", gpa) == 1; //gpa is before gpa
    }
}
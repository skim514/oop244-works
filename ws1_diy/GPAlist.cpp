/***********************************************************************
// Workshop 1 p2: tester program
//
// File  GPAlist.cpp
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
#include "UI.h"

using namespace std; // not allowed in a ".h" file

namespace sdds {

    GPA gpalist[86]; //database space

    // loads gpa into the global array of structures.
    bool gpaQuery(const char* fileName) {
        GPA studentGPAtemp = { 0 }; //temp to file read

        int studentIndex = 0; // number of student read
        bool ok = true;
        
        if (openFile(fileName)) {
            while (ok && studentIndex < 86) {
                ok = readName(studentGPAtemp.name) &&
                    readStudentNum(&studentGPAtemp.stno) &&
                    readGPA(&studentGPAtemp.gpa);

                if (ok) gpalist[studentIndex++] = studentGPAtemp;
            }
            closeFile(); //close file -> sorting -> call UI function.
            gpaSorting(gpalist, 86);
            inputGPA(); //UI module
        }
        return studentIndex == 86;
    }

    //Referred from professor Cameron Gray's material in the IPC144 course in 1st semester.
    void gpaSorting(struct GPA* student, int arrayLength)
    {
        int i = 0, j = 0;
        int firstStudentID = 0, secStudentID = 0;
        struct GPA tmp = { 0 };

        for (i = 0; i < arrayLength - 1; i++)
        {
            for (j = 0; j < arrayLength - i - 1; j++)
            {
                firstStudentID = student[j].stno;
                secStudentID = student[j + 1].stno;

                if (firstStudentID > secStudentID)
                {
                    tmp = student[j];
                    student[j] = student[j + 1];
                    student[j + 1] = tmp;
                }

                firstStudentID = student[j].stno;
                secStudentID = student[j + 1].stno;

                if (firstStudentID == secStudentID)
                {
                    tmp = student[j];
                    student[j] = student[j + 1];
                    student[j + 1] = tmp;
                }
            }
        }
    }

    bool studentGPA(const GPA* student, const char option, double userGPA) {
        bool found = false;

        if ('>' == option) {
            if (student->gpa > userGPA)
            {
                found = true;
            }
        }
        else if ('<' == option)
        {
            if (student->gpa < userGPA)
            {
                found = true;
            }
        }
        else if ('~' == option)
        {
            if (userGPA - 0.05 <= student->gpa && userGPA + 0.05 >= student->gpa)
            {                
                found = true;
            }
        }
        return found;
    }

    void displayStudent(const GPA* student) {

        //Refered from a blog. (Link: https://jokerkwu.tistory.com/127)
        cout << " " << student->stno << ": " << fixed;
        cout.precision(1);
        cout << student->gpa << " (" << student->name << ")" << endl;
    }

    void displayOptionGPA(const char option, double inputGPA) {
        int i, j;
        for (i = 0, j = 1; i < 86; i++) {
            if (studentGPA(&gpalist[i], option, inputGPA)) { //클래스에서 사용자 입력값과 하나씩 스트링비교
                cout << "[" << j++ << "]";
                displayStudent(&gpalist[i]);
            }
        }
        if (j == 1) {
            cout << "No match found for: " << option << endl;
        }
    }
}
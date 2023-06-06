/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File    Tools.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {

    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');//
        }
        //The rewind() function in C++ sets the file position indicator to the beginning of the given file stream.
        rewind(fp);//동적메모리 포인터 초기화
        
        return noOfTraces;
    }
    

    // To Do: read functions (4 overloaded read functions)
    
    bool read(char* string){
        return fscanf(fp, "%60[^\n]\n", string) == 1;
    }
    bool read(int& intNum){
        return fscanf(fp, "%d,", &intNum) == 1;
    }
    bool read(double& dbNum){
        return fscanf(fp, "%lf,", &dbNum) == 1;
    }
    bool read(char& character){
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &character) == 1;
    }


    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}


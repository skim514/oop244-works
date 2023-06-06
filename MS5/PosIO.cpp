// Final Project Milestone 5
//
// Version 1.0
// Date    2023-04-07
// Author    Suna Kim
// File name    PosIO.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "PosIO.h"

using namespace std;

namespace sdds{
    PosIO::~PosIO(){
    }
    ostream& operator<<(ostream& ostr, const PosIO& ro)
    {
        return ro.write(ostr);
    }
    istream& operator>>(istream& istr, PosIO& ro)
    {
        return ro.read(istr);
    }
    ofstream& operator<<(ofstream& ostr, const PosIO& ro)
    {
        return ro.save(ostr);
    }
    ifstream& operator>>(ifstream& istr, PosIO& ro)
    {
        return ro.load(istr);
    }
}

// Final Project Milestone 3
//
// Version 1.0
// Date    2023-03-26
// Author    Suna Kim
// File name    Error.h
#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include <iostream>
#include "POS.h"

using namespace std;

namespace sdds{
    class Error
    {
        char* m_errorMsg;
        
    public:
        Error();
        Error(const char* errorMsg);
        void setError(const char* errorMsg);
        Error(const Error& another);//Rule of three
        Error& operator=(const Error& right);
        ~Error();
        Error& operator=(const char* errorMsg);
        operator bool() const;
        Error& clear();
        ostream& display(ostream& os) const;
    };
    ostream& operator<<(ostream& os, const Error& another);
}

#endif

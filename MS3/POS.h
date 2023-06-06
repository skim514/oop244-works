// Final Project Milestone 3
//
// Version 1.0
// Date    2023-03-26
// Author    Suna Kim
// File name    POS.h
#ifndef SDDS_POS_H_
#define SDDS_POS_H_

using namespace std;

namespace sdds{ //For constant values.
    const double TAX = 0.13;
    const int MAX_NAME_LEN = 40;
    const int MAX_SKU_LEN = 7;
    const int MAX_STOCK_NUMBER = 99;
    const int POS_LIST = 1;
    const int POS_FORM = 2;
    
    //char str[5] = { 0 };
    //char str[] = "test";//이 자체가 사이즈임

    const char ERROR_POS_SKU[] = "SKU too long";
    const char ERROR_POS_NAME[] = "Item name too long";
    const char ERROR_POS_PRICE[] = "Invalid price value";
    const char ERROR_POS_TAX[] = "Invalid tax status";
    const char ERROR_POS_QTY[] = "Invalid quantity value";
    const char ERROR_POS_STOCK[] = "Item out of stock";
    const char ERROR_POS_EMPTY[] = "Invalid Empty Item";
}
#endif

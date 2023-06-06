// Final Project Milestone 5
//
// Version 1.0
// Date    2023-04-07
// Author    Suna Kim
// File name    Error.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Error.h"

using namespace std;

namespace sdds{
    Error::Error(){
        m_errorMsg = nullptr;
    }
    Error::Error(const char* errorMsg):m_errorMsg{nullptr}{
        clear();
        if (errorMsg)
        {
            setError(errorMsg);
        }
    }
    void Error::setError(const char* errorMsg){
        clear();
        m_errorMsg = new char[strlen(errorMsg)+1];
        strcpy(m_errorMsg, errorMsg);
    }
    Error::Error(const Error& another):m_errorMsg{ nullptr } {//오른쪽에 있는것을 왼쪽에 전달해주는 역할
        operator=(another);
    }
    Error& Error::operator=(const Error& right){
        if (this != &right) { // prevents self copying
            clear(); // set empty in case S is empty;
            
        if (right.m_errorMsg) {  // the same as bool operator and !isEmpty
            m_errorMsg = new char[strlen(right.m_errorMsg)+1];
            strcpy(m_errorMsg, right.m_errorMsg);
            }
        }
        return *this;
    }
    Error::~Error(){
        delete [] m_errorMsg;
    }
    Error& Error::operator=(const char* errorMsg){
        if (errorMsg != nullptr) {
            clear();
            m_errorMsg = new char[strlen(errorMsg)+1];
            strcpy(m_errorMsg, errorMsg);
        }
        return *this;
    }
    Error::operator bool() const{
        return m_errorMsg != nullptr;
    }
    Error& Error::clear(){
        if (m_errorMsg)
        {
            delete[] m_errorMsg;
        }
        m_errorMsg = nullptr;
        return *this;
    }
    ostream& Error::display(ostream& os) const{//ostream으로 파일도 사용 가능
        if (m_errorMsg) {
            os << m_errorMsg;
        }
        return os;
    }
    ostream& operator<<(ostream& os, const Error& another){
        return another.display(os);
    }
}

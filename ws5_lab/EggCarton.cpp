#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "EggCarton.h"

using namespace std;

namespace sdds{

    void EggCarton::setBroken(){
        m_sizeOfCarton = -1;
        m_numOfEggs = -1;
    }
    //constructor
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize){//bool 기본값이 false?
        if (size % 6 == 0 && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size) {
            set(size, noOfEggs, jumboSize);//컨스트럭터는 항상 셋팅함
        }
        else{
            setBroken();
        }
    }
    
    //Member function
    EggCarton& EggCarton::set(int size, int noOfEggs, bool jumbo){
        m_sizeOfCarton = size;
        m_numOfEggs = noOfEggs;
        m_isJumbo = jumbo;
        return *this;//클래스 자체 리턴은 this
    }

    ostream& EggCarton::display(ostream& ostr) const{
        return (bool(*this)) ? displayCarton(m_sizeOfCarton, m_numOfEggs, m_isJumbo, ostr) : cout << "Broken Egg Carton!" << endl;
    }
    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const {
      int cartonWidth = size == 6 ? 3 : 6;
      for(int i = 0; i < size; i++) {
         ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
         ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
      }
      return ostr;
    }
    istream& EggCarton::read(istream& istr){
        char cha = '\0';
        int size = 0, noOfEggs = 0;
        bool jumboSize = false;
        
        istr >> cha;
        istr.ignore(100,','); //(갯수, 이거 전까지)
        if (cha == 'j') {
            jumboSize = true;
        }
        istr >> size;
        istr.ignore(100,',');
        istr >> noOfEggs;
        istr.ignore(100,'\n');
        if (size % 6 == 0 && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size) {
            set(size, noOfEggs, jumboSize);//컨스트럭터는 항상 셋팅함
        }
        else{
            setBroken();
        }
        return cin;
    }

    //Type conversion operator overloads
    EggCarton::operator bool() const{
        return m_sizeOfCarton > 0;//conversion은 항상 리턴하려는 타입을 리턴
    }
    EggCarton::operator int() const{
        return (bool(*this)) ? m_numOfEggs : -1;
    }
    EggCarton::operator double() const{
        double totalWeight = 0.0;
        if(m_isJumbo){
            totalWeight = (JumboEggWieght* m_numOfEggs)/1000.0;
        }
        else{
            totalWeight = (RegularEggWieght* m_numOfEggs)/1000.0;
        }
        return (bool(*this)) ? totalWeight : -1.0;
    }

    //Unary operator overloads
    //prefix
    EggCarton& EggCarton::operator--(){
        if(bool(*this) && m_numOfEggs > 0)
        {
            m_numOfEggs--;
        }
        return *this;
    }
    EggCarton& EggCarton::operator++(){
        if (bool(*this) && m_numOfEggs < m_sizeOfCarton) {
            m_numOfEggs++;
        }
        else{
            setBroken();
        }
        return *this;
    }
    //postfix
    EggCarton EggCarton::operator--(int){
        EggCarton carton = *this;
        --(*this);
        return carton;
    }
    EggCarton EggCarton::operator++(int){
        EggCarton carton = *this;
        ++(*this);
        return carton;
    }

    //Binary Member Operators
    EggCarton& EggCarton::operator=(int value){
        if (value > m_sizeOfCarton) {
            setBroken();
        }
        else{
            m_numOfEggs = value;
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(int value){
        if (value + m_numOfEggs > m_sizeOfCarton) {
            setBroken();
        }
        else{
            m_numOfEggs += value;
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(EggCarton& right){
        if (m_sizeOfCarton - m_numOfEggs < right.m_numOfEggs) {
            right.m_numOfEggs -= m_sizeOfCarton - m_numOfEggs;
            m_numOfEggs += m_sizeOfCarton - m_numOfEggs;
        }
        else{
            m_numOfEggs += right.m_numOfEggs;
            right.m_numOfEggs = 0;
        }
        return *this;
    }
    bool EggCarton::operator==(const EggCarton& right) const{
        bool result = false;
        if (double(*this) - double(right) < 0.001 && double(*this) - double(right) > -0.001) {
            result = true;
        }
        return result;
    }

    //Helper binary operator overloads
    int operator+(int left, const EggCarton& right){
        return bool(right) ? int(right) + left : left;
    }
    ostream& operator<<(ostream& ostr, const EggCarton& right){
        return right.display(ostr);
    }
    istream& operator>>(istream& istr, EggCarton& right){
        return right.read(istr);
    }
}

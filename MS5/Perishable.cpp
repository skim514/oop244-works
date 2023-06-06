// Final Project Milestone 4
//
// Version 1.0
// Date    2023-03-12
// Author    Suna Kim
// File name    Perishable.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include "Perishable.h"

using namespace std;

namespace sdds {
	char sdds::Perishable::itemType() const
	{
		return 'P';
	}
	istream& Perishable::read(istream& istr)
	{
		Item::read(istr);
		istr.ignore(100, '\n');
		if(!istr.fail() || *this)
		{			
			Date tempDate;
			tempDate.dateOnly(true);
			cout << "Expiry date (YYYY/MM/DD)" << endl << "> ";			
			istr >> tempDate;//값 잘들어왔는지 디버깅(인풋받는것은 항상)
			if (bool(tempDate))
			{
				m_date = tempDate;// !!!!!!!!!!!(변수값은 모두체크)
				m_error = Error();
			}
		}
		return istr;
	}
	ostream& Perishable::write(ostream& ostr) const
	{
		Item::write(ostr);
		if (*this)
		{
			if (m_displayType == POS_LIST)
			{
				ostr << "  " << m_date << " |";
			}
			else if (m_displayType == POS_FORM)
			{
				ostr << "Expiry date: " << m_date << endl << "=============^" << endl;
			}
		}
		return ostr;
	}
	ifstream& Perishable::load(ifstream& istr)
	{
		Item::load(istr);
		if (!istr.fail())
		{
			Date tempDate;
			tempDate.dateOnly(true);
			istr.ignore(1, ',');
			istr >> tempDate; //!!!!!!!!!!!
			if (bool(tempDate))
			{
				m_date = tempDate; //!!!!!!!!!!!
			}
			else
			{
				m_error = tempDate.error();//!!!!!!!!!!
			}
		}
		return istr;
	}
	ofstream& Perishable::save(ofstream& ostr) const
	{
		Item::save(ostr);
		if (*this)
		{
			ostr << "," << m_date;
		}
		return ostr;
	}
}
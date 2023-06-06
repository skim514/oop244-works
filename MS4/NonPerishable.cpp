// Final Project Milestone 4
//
// Version 1.0
// Date    2023-03-12
// Author    Suna Kim
// File name    NonPerishable.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include "Date.h"
#include "NonPerishable.h"

using namespace std;

namespace sdds {
	char sdds::NonPerishable::itemType() const
	{
		return 'N';
	}
	ostream& NonPerishable::write(ostream& ostr) const
	{
		if (*this)
		{
			if (POS_LIST == m_displayType)
			{
				Item::write(ostr);
				ostr << "     N / A   |";
			}
			else if (POS_FORM == m_displayType)
			{
				Item::write(ostr);
				ostr << "=============^" << endl;
			}
		}
		else
		{
			ostr << m_error;
		}

		return ostr;
	}
}
// Final Project Milestone 4
//
// Version 1.0
// Date    2023-03-26
// Author    Suna Kim
// File name    Perishable.h
#ifndef SDDS_PERISHABLE_H_
#define SDDS_PERISHABLE_H_
#include "Date.h"
#include "Item.h"

using namespace std;

namespace sdds {
	class Perishable : public Item {
		Date m_date;

	public:
		char itemType() const;
		istream& read(istream& istr);
		ostream& write(ostream& ostr) const;
		ifstream& load(ifstream& istr);
		ofstream& save(ofstream& ostr)const;
	};
}
#endif

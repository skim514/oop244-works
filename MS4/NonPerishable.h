// Final Project Milestone 4
//
// Version 1.0
// Date    2023-03-26
// Author    Suna Kim
// File name    NonPerishable.h
#ifndef SDDS_NONPERISHABLE_H_
#define SDDS_NONPERISHABLE_H_
#include "Item.h"

using namespace std;

namespace sdds {
    class NonPerishable : public Item {
    public:
        char itemType() const;
        ostream& write(ostream& ostr) const;
    };
}
#endif

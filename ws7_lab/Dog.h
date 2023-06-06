#ifndef SDDS_DOG_H
#define SDDS_DOG_H

#include <iostream>
#include "Pet.h"

using namespace std;

namespace sdds {
    class Dog : public Pet{
        const double CLONING_FEE = 8.00;
        const double COST_DOG = 4.00;
        const double DOG_RESPAWN_FEE = 1.00;
        const double DOG_FEED_FEE = 0.25;
        
        int m_numWalks;
        
    public:
        //Dog();
        Dog(const char* name, int age = 0);
        //~Dog();
        void operator++ (int nextday);
        Dog& operator=(const Dog& rhs);
        void feed();
        void walk();
        int totalWalk();
        void reSpawn();
    };
    ostream& operator<<(ostream& os, Dog& dog);
}
#endif

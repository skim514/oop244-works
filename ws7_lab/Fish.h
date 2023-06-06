#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include <iostream>
#include "Pet.h"

using namespace std;

namespace sdds {
    class Fish : public Pet{
        const double CLONING_FEE = 4.00;
        const double COST_FISH = 2.00;
        const double FISH_RESPAWN_FEE = 0.50;
        const double FISH_FEED_FEE = 0.10;
        
    public:
        //Fish();
        Fish(const char* name, int age = 0);
        //~Fish();
        void feed();
        void reSpawn();
        void operator++ (int nextday);
        Fish& operator=(const Fish& fish);
    };
    ostream& operator<<(ostream& os, Fish& fish);
}
#endif

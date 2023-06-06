#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Fish.h"

using namespace std;

namespace sdds{
//    Fish::Fish(){
//        
//    }
    Fish::Fish(const char* name, int age): Pet (name, age, COST_FISH){
    }
    void Fish::feed(){
        Pet::feed();
        if (Pet::isAlive()) {
            Pet::addCharge(FISH_FEED_FEE);
        }
    }
    void Fish::reSpawn(){
        Pet::reSpawn();
        Pet::addCharge(FISH_RESPAWN_FEE);
    }
    void Fish::operator++ (int nextday){
        double healthDelta = 0;
        if (bool(Pet::isAlive())) {
            healthDelta += 0.20 * (getFeeds() - 1);
        }
        Pet::applyHealthDelta(healthDelta);
        Pet::operator++(nextday);
    }
    Fish& Fish::operator=(const Fish& fish){
        Pet::operator=(fish);
        Pet::addCharge(CLONING_FEE);
        return *this;
    }
    ostream& operator<<(ostream& os, Fish& fish){
        cout << "** Generic Fish **" << endl;
        //fish.outputData(os);
        return fish.outputData(os);
    }
}

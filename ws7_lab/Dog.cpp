#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Dog.h"

using namespace std;

namespace sdds{
//    Dog::Dog(){
//        Pet::
//    }
    Dog::Dog(const char* name, int age): Pet (name, age, COST_DOG){
        //Pet(name, age, baseCost);
        m_numWalks = 0;
    }
//    Dog::~Dog(){
//
//    }
    void Dog::operator++ (int nextday){
        double healthDelta = 0;
        if (Pet::isAlive()) {
            healthDelta += 0.15 * (getHugs()   - 1);
            healthDelta += 0.10 * (getFeeds()  - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (m_numWalks  - 2);
        }
        Pet::applyHealthDelta(healthDelta);
        Pet::operator++(nextday);
        m_numWalks = 0;
    }
    Dog& Dog::operator=(const Dog& dog){
        Pet::operator=(dog);
        Pet::addCharge(CLONING_FEE);
        m_numWalks = dog.m_numWalks;
        return *this;
    }
    void Dog::feed(){
        Pet::feed();
        if (Pet::isAlive()) {
            Pet::addCharge(DOG_FEED_FEE);
        }
    }
    void Dog::walk(){
        if (Pet::isAlive()) {
            m_numWalks++;
        }
    }
    int Dog::totalWalk(){
        return m_numWalks;
    }
    void Dog::reSpawn(){
        Pet::reSpawn();
        Pet::addCharge(DOG_RESPAWN_FEE);
        m_numWalks = 0;
    }
    ostream& operator<<(ostream& os, Dog& dog){
        cout << "** Generic Dog **" << endl << "   Walks: " << dog.totalWalk() << endl;
        
        //dog.outputData(os);
        return dog.outputData(os);
    }
}

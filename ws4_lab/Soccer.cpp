#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Soccer.h"

using namespace std;

namespace sdds{
    //It will set the team name, fine and fouls of the team.
    void SoccerTeam::setTeam(const SoccerTeam& team){
        setName(team.m_teamName);
        setFine(team.m_fines, team.m_noFouls);
    }
    //If the received name pointer is valid and not null it will copy the received name to the data member m_teamName
    void SoccerTeam::setName(const char* tname){
        if (tname[0] != '\0' && tname != nullptr) {
            strcpy(m_teamName, tname);
            }
    }
    //It will receive the information about fines and no of foul. After checking the validity it will set the values to the appropriate data members. Fine and foul should be grater than and equal to zero. Otherwise, it will set the soccerTeam object to an empty state.
    void SoccerTeam::setFine(double fines, int foul){
        if (fines > -1.0 && foul > -1) {
            m_noFouls = foul;
            m_fines = fines;
            }
        else{
            setEmpty();
            }
    }
    //Sets the soccerTeam object to an Empty State. Do this by setting the m_teamName to an empty Cstring, m_noFoul and m_fines to a negative number and m_goals to 0.
    void SoccerTeam::setEmpty(){
        m_teamName[0] = '\0';
        m_noFouls = -1;
        m_fines = -1.0;
        m_goals = 0;
    }
    //Returns true if m_teamName is not null, m_fines and m_noFouls is grater than 0.
    bool SoccerTeam::isEmpty() const{
        bool result = false;
        if (m_teamName[0] != '\0' && m_fines >= 0.0 && m_noFouls >= 0) {
            result = true;
            }
        return result;
        }
    //If this function is called it will increases the fine by 20% of the old fine value.
    void SoccerTeam::calFines(){
        m_fines = m_fines * 1.2;
        }
    //It will return the m_noFoul
    int SoccerTeam::fouls() const{
            return m_noFouls;
        }
    SoccerTeam::SoccerTeam(){
        setEmpty();
    }

    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul){
        if (tname[0] != '\0' && tname != NULL) {
            setName(tname);
            setFine(fines, foul);
            m_goals = 0;
            }
        else{
            setEmpty();
            }
    }
    //1. If a soccerTeam object is valid
    // a) prints m_teamName with width 30, left justified and fill with empty spaces.
    // b) prints m_fines with width 6 and after the decimal point 2 digits.
    // c) prints m_noFoul with width 6
    // d) prints m_fines with width 6
    // e) prints m_golas with width 10. If number of goals are greater than zero then it will print "w" besides the number.
    //2. otherwise prints, "Invalid Team".
    //3. At the end return the reference of the ostream object.
    ostream& SoccerTeam::display()const{
        if (isEmpty()) {
            cout.width(30);
            cout.setf(ios::left);
            cout << m_teamName;
            cout.unsetf(ios::left);//a
            cout.width(6);
            cout << fixed; cout.precision(2);//b
            cout << m_fines;
            cout.width(6);
            cout << m_noFouls;//c
            cout.width(10);
            cout << m_goals;
            if (m_goals > 0) {
                cout << "w";
            }//e
            else
            {
                cout << " ";
            }
        }
        else{
            cout << "Invalid Team";
        }
        return cout;
    }
}


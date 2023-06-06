#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Tournament.h"

using namespace std;

namespace sdds{
    //First, it will check the validity of all the received arguments. Tournament name should be valid and non-empty Cstring. Number of teams should be greater than zero.
    //It will set m_num to the corresponding argument value.
    //Then it will dynamically allocate memory for tournament name in the tournament name pointer attribute and then copies the content of the tournament name argument into the newly allocated memory.
    //It will dynamically allocate an array of soccer team pointed by m_soccer member variable. The length of this array will be m_num.
    //Lastly, add all the teams to the dynamically allocated array of m_soccer.
    //If any of the arguments are not valid it will set the Tournament to an empty state.
    void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer){
        int i = 0;
        if (name != nullptr && name[0] != '\0' && noOfteam > 0) {
            m_num = noOfteam;
            m_name = nullptr;
            m_name = new char[strlen(name)+1];
            strcpy(m_name, name);
            m_soccer = nullptr;
            m_soccer = new SoccerTeam[m_num];
            for (i = 0; i < m_num; i++) {
                m_soccer[i] = soccer[i];
            }
        }
        else{
            setEmpty();
        }
    }
    //Sets the Tournamnet object to an Empty State. Do this by setting the m_name and m_soccer to null and m_num to 0.
    void Tournament::setEmpty(){
        m_name = nullptr;
        m_soccer = nullptr;
        m_num = 0;
    }
    //Returns true if m_name and m_soccer is not null and m_num is grater than 0.
    bool Tournament::isEmpty() const{
        return m_name != nullptr && m_name[0] != '\0' && m_soccer != nullptr && m_num > 0;
    }
    //This function will find out the winner between 2 soccer teams by having matches. It will loop through all the teams.
    //First it will check which team is having more no of fouls.
    //If first team is having less fouls then second team then, second team`s no of foul will increase by double and fine will be increased by 20%
    //First team`s goal will be increased by 1.
    //If seconds team`s no of foul exceed the MAX_FOUL then this team will become a invalid team. You can do this by setting the number to foul to an invalid value.
    //At the end it will return the reference of the current object.
    Tournament& Tournament::match(const SoccerTeam* ls){
        for (int i = 0; i <1; i++) {
            if (m_soccer[i].fouls() < m_soccer[i + 1].fouls()) {
                m_soccer[i + 1].m_noFouls *= 2;
                m_soccer[i + 1].calFines();
                m_soccer[i].m_goals++;
                if (m_soccer[i + 1].m_noFouls > MAX_FOUL) {
                    m_soccer[i + 1].m_noFouls = -1;
                    }
                }
           }
          return *this;
    }
    //If Tournament object is valid
    //1. a) prints "Tournament name: " then tournament name
    //b) prints "list of the teams" after that a newline
    //c) prints "Fines" with width 45 and fill with empty spaces.
    //d) prints "Fouls" with width 10 and fill with empty spaces.
    //e) prints "Goals" with width 10 and fill with empty spaces.
    //f) prints all the soccer teams information. For details see the sample output.
    //2. otherwise prints, "Invalid Tournament".
    //3. At the end return the reference of the ostream object.
    ostream& Tournament::display() const{
        if (isEmpty()) {
            cout << "Tournament name: " << m_name << endl;
            cout << "list of the teams" << endl;
            cout.width(45);
            cout << "Fines";//c
            cout.width(10);
            cout << "Fouls";//d
            cout.width(10);
            cout << "Goals" << endl;//e
            for (int i = 0; i < m_num; i++) {
                cout << "Team[" << i + 1 << "] :" ;
                m_soccer[i].display() << endl; //다이나믹메모리 어레이임!! 좀 외우자!!!
            }
        }
        else{
            cout << "Invalid Tournament";
        }
        return cout;
    }
    //By default a Tournament is initiated by setting all the member variable values to default values. You can do this by setting m_name, m_soccer to nullptr and m_num to a value like 0.
    Tournament::Tournament(){
        setEmpty();
    }
    //It works exactly like the setTournamnet()
    Tournament::Tournament(const char* name, int noOfteam,const SoccerTeam* soccer){
        
        setTournament(name, noOfteam, soccer);
    }
    //Deallocate the memory allocated by m_name and m_soccer.
    Tournament::~Tournament(){
        delete [] m_name;
        m_name = nullptr;
        delete [] m_soccer;
        m_soccer = nullptr;
    }
}

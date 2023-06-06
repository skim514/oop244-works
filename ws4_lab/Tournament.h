#ifndef SDDS_TOURNAMENT_H_
#define SDDS_TOURNAMENT_H_
#include "Soccer.h"

namespace sdds {

    class Tournament{
        char* m_name;//points to a dynamically allocated Cstring
        int m_num; //size of the dynamically allocated array of soccer team. It should be more thenzero.
        SoccerTeam* m_soccer = nullptr; //pointer to the dynamically allocated array of soccerTeam.
        
    public:
        void setTournament(const char* name, int noOfteam,const SoccerTeam* soccer);
        void setEmpty();
        bool isEmpty() const;
        Tournament& match(const SoccerTeam* ls);
        std::ostream& display() const;
        
        Tournament();
        Tournament(const char* name, int noOfteam,const SoccerTeam* soccer);
        ~Tournament();
    };
}

#endif


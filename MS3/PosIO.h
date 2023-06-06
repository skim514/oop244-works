// Final Project Milestone 3
//
// Version 1.0
// Date    2023-03-26
// Author    Suna Kim
// File name    PosIO.h
#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_

using namespace std;

namespace sdds{
    class PosIO
    {
    public:
        virtual ~PosIO();
        virtual ostream& write(ostream& os) const = 0;
        virtual ofstream& save(ofstream& os) const = 0;
        virtual istream& read(istream& is) = 0;
        virtual ifstream& load(ifstream& is) = 0;
        
    };
    ostream& operator<<(ostream& ostr, const PosIO& ro);
    istream& operator>>(istream& istr, PosIO& ro);
    ofstream& operator<<(ofstream& ostr, const PosIO& ro);
    ifstream& operator>>(ifstream& istr, PosIO& ro);
}

#endif

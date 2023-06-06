#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_

using namespace std;

namespace sdds {

    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;

    class EggCarton{
        
        int m_sizeOfCarton;
        int m_numOfEggs;
        bool m_isJumbo;
        void setBroken();
        ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;
        
    public:
        EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false);
        
        EggCarton& set(int size, int noOfEggs, bool jumbo);
        
        ostream& display(ostream& ostr = cout) const;
        istream& read(istream& istr = cin);
        
        operator bool() const;
        operator int() const;
        operator double() const;
        
        EggCarton& operator--();
        EggCarton& operator++();
        EggCarton operator--(int);
        EggCarton operator++(int);
        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;
        
    };
    int operator+(int left, const EggCarton& right);
    ostream& operator<<(ostream& ostr, const EggCarton& right);
    istream& operator>>(istream& istr, EggCarton& right);
}
#endif

#ifndef RATIONAL_H
#define RATIONAL_H
#include <fstream>

class Rational{
private:
    int num;
    int den;
public:
    Rational();
    Rational(int num, int den);
    int get_num(){return num;}
    int get_den(){return den;}
    void operator +=(Rational rhs){
        num=((get_num()*rhs.get_den()) + (get_den()*rhs.get_num()));
        den=get_den()*rhs.get_den();
    }
};


Rational operator*(Rational lhs, Rational rhs);
Rational operator+(Rational lhs, Rational rhs);
bool operator==(Rational lhs, Rational rhs);
std::ostream& operator<<(std::ostream& os, Rational a);


#endif // RATIONAL_H

#include <rational.h>
#include <iostream>
using namespace std;


Rational::Rational(){
    num=0;
    den=1;
}

Rational::Rational(int newnum, int newden){
    num=newnum;
    den=newden;
}

ostream& operator<<(ostream& os, Rational a){
    os<<a.get_num()<<"/"<<a.get_den()<<endl;
    return os;
}

Rational operator*(Rational lhs, Rational rhs){
    return Rational(
                    lhs.get_num()*rhs.get_num(),
                    lhs.get_den()*rhs.get_den());
}
Rational operator+(Rational lhs, Rational rhs){
    return Rational(
                    (lhs.get_num()*rhs.get_den())+ (rhs.get_num()*lhs.get_den()),
                    lhs.get_den()*rhs.get_den());

}
bool operator==(Rational lhs, Rational rhs){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    bool fufu=true;
    if((double(lhs.get_num())/double(lhs.get_den()))==(double(rhs.get_num())/double(rhs.get_den()))){
        return fufu;
    }
    else{
        fufu=false;
        return fufu;
    }
}


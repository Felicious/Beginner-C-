#include "dbigunit.h"
#include <algorithm>
#include <cassert>

dbiguint::dbiguint(int n){
    int temp = n;
    _capacity = 0;
    while(temp != 0){
        temp = (temp/10);
        _capacity++;
    }
    _data = new unsigned short[_capacity];
     for(std::size_t i = 0; i<_capacity; i++){
         if(n==0) _data[i] = 0;
         else{
             _data[i] = n%10;
             n = n/10;
         }
     }
 }
 dbiguint::dbiguint (const std::string & s)
 {
     if (s.size() == 0)
         return;

     _capacity = s.size();
     unsigned short * _data = new unsigned short[_capacity];

     char c = s[0];
     int j(0);
     for (int i = s.size()-1; j < _capacity && i >= 0; --i)
     {
         assert(isdigit(s[i]));
         _data[j] = s[i] - '0';
         ++j;
     }
 }

 // pre:  none    //NEW
 // post: copy constructor: creates a new dynamic bigint which is
 //                         a copy of given dynamic bigint
dbiguint::dbiguint (const dbiguint & b){
        _capacity = b._capacity;
        _data = new unsigned short[_capacity];
        std::copy(b._data, b._data+_capacity, _data);
}

 unsigned short dbiguint::operator [](std::size_t pos) const
 {
     assert(pos < _capacity);
     return _data[pos];
 }

dbiguint:: ~dbiguint(){
    delete [] _data;
    _capacity = 0;
}

size_t dbiguint:: size() const{
    return _capacity;
}
/*
 int biguint::compare(const biguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }

     return 0;
 }
void dbiguint::operator += (const dbiguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i< _capacity; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
std::string dbiguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
*/

void dbiguint::operator =(const dbiguint &b){
    _capacity = b.size();
    delete [] _data;
    _data= new unsigned short [_capacity];
    for (int i = 0; i < b.size(); i++){
        _data[i] = b._data[i];
    }
}

std::ostream &operator << (std::ostream & os, dbiguint & b){
    for (int i = b.size() - 1; i > 0; --i){
        os << b[i];
    }
    return os;
}

 /*std::istream & operator >> (std::istream & is, dbiguint & b)
 {
     std::string s;
     is >> s;
     b = dbiguint(s);
     return is;


 }
 */

 /*bool operator <(const dbiguint& a, const dbiguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) != 0);
 }
//You do > and >= */


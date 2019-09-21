#include "lbiguint.h"
#include "node.h"

#include <cassert>
#include <sstream>

 lbiguint::lbiguint(int n){
     head = tail = nullptr;
     int copy = n;
     int size = 0;
     while (copy!=0){
         copy=copy/10;
         ++size;
     }
     for(int i = 0; i < size; ++i){
         node* temp = new node(n%10,nullptr);
        if(tail == nullptr){
            head=tail = temp;
        }
        else{
            tail->set_link(temp);
            tail=temp;
        }
        n = n/10;
    }
 }
 lbiguint::lbiguint (const std::string & s)
 {
     head=tail = nullptr;
     for (int i = 0; i < s.size(); ++i)
     {
         if(tail == nullptr){
             tail=head=new node((s[i] - '0'),head); //first case
         }else{
         head= new node((s[i] - '0'),head); //everything else
        }
     }
 }

lbiguint::~lbiguint(){
    if(tail == head){
        tail = nullptr;
    }
    for(node* p = head; p != nullptr; p = head){
        head = head->link();
        delete p;
    }
}

std::size_t lbiguint::size(){
    size_t counter = 0;
    for(node* p = head; p!=nullptr; p = p->link()){
        ++counter;
    }
    return counter;
}

unsigned short lbiguint::operator [](std::size_t pos)
{
    assert(size() >= pos);
    for(node* p = head; p != nullptr; p = p->link()){
        if(pos == 0){
            return p->data();
        }
        --pos;
    }
    return 0;
}

std::ostream & operator<<(std::ostream &out, lbiguint &a){
    for(int i = a.size()-1; i >= 0; --i){
        out << a[i];
    }
    return out;
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



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string biguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 std::ostream & operator << (std::ostream & os, const biguint & b)
 {

     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

 std::istream & operator >> (std::istream & is, biguint & b)
 {
     std::string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }

//You do > and >=
*/

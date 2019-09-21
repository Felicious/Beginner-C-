#ifndef COORDINATE_H
#define COORDINATE_H
#include "rational.h"
using namespace std;

template <typename T>
class Coord{
private:
    T a[10];
    int size;
public:
    //constructors
    Coord<T>();
    Coord<T>(int b);
    Coord<T>(T newval[], int newb);

    //getter!
    T get_item(int i); //getting the ith term

    int get_size(); //returns size
};

template <typename T>
Coord<T>::Coord(){
    size = 0;
}

template <typename T>
Coord<T>::Coord(int b){
    size=b;
}

template <typename T>
Coord<T>::Coord(T newval[], int newb){
    for (int i =0; i < newb; i++){
        a[i] = newval[i];
    }
    size=newb;
}

template <typename T>
T Coord<T>::get_item(int i){ //getting the ith term
    return a[i];
}

template <typename T>
int Coord<T>::get_size(){
    return size;
}

template <typename T>
Coord<T> operator+(Coord<T> h, Coord<T> g){
    Coord<T> newpoint;
    int counter = h.get_size();
    for(int i=0; i<counter; i++){
        newpoint.get_item(i) = (h.get_item(i)+g.get_item(i));
    }
    return newpoint;
}

template <typename T>
bool operator==(Coord<T> x, Coord<T> y){
    int counter = x.get_size();
    int truth = 0;
    for(int i = 0; i < counter; i++){
        if(x.get_item(i)==y.get_item(i)){
            truth++;
        }
    }
    if(truth == counter){
        return true;
    }else{
    return false;
    }
}

#endif // COORDINATE_H

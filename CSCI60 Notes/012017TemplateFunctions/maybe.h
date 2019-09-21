#ifndef MAYBE_H
#define MAYBE_H

#include <stdexcept> //Need to throw a runtime error

template <typename T> //typename == class
class Maybe {
private:
    T value_;
    bool has_value_;
public:
    Maybe(); //default constructor
    Maybe(T value);
    bool has_value();
    T value();
};

//constructors
template<typename T>
T Maybe<T>::Maybe(){
    has_value_ = false;
}

template<typename T>
T Maybe<T>::Maybe(){
    value = has_value();
    return value;
}

template <typename T>
T Maybe<T>::value(){ //maybe is out of scope so u have to specify its type (T) put its type in its name
    if(!has_value()){
        throw std::runtime_error("Called value, but has no value");
    }
    return value_;
}

bool Maybe<T>::has_value(){
    return has_value_;
}

#endif // MAYBE_H

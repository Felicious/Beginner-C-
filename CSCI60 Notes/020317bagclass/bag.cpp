#include "bag.h"
template <typename T>
bag<T>::bag(){
    data = new T[capacity_]; //constructor (?)
}

template <typename T>
bag<T>::~bag(){ //deconstructors never take inputs or cause errors
    delete[] data;
}

template <typename T>
bag<T>::bag(const bag<T>& that){
    size_ = that.size_;
    capacity_ = that.capacity_;
    data_ = new T[capacity_];
    for (size_type i = 0; i < size_; ++i) data_[i] = that.data_[i];
}

template <typename T>
bag<T>& bag<T>::operator=(const bag<T>& that){
    if (this == &that) return *this; //VERY IMPORTANT
            //you don't want to assign them to each other because the object &
            //pointers aren't the same. just return the pointer.
            size_ = that.size_;
            capacity_ = that.capacity_;
            delete[] data_;
            data_ = nullptr;
            data = new T[capacity_];
            //continue copying
}

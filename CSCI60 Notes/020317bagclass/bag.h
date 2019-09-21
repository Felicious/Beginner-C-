#ifndef BAG_H
#define BAG_H

template<typename T>
class bag
{
private:
    template <typename T>
    T size_;

public:
    //creates an empty bag
    bag();

    //copy constructor; create one bag from another bag
    bag(const bag<T>& that);

    //deconstructor
    ~bag();

    //assignment operator
    //x = y
    //has to return ref to *this to chain
    bag& operator=(const bag<T>& that);
    //the asterisk * indicates that it is the object, and the same thing without the
    //asterisk is what that represents you
    // for example, Felicia is my name and *Felicia is myself.
    //Felicia represents me, but *Felicia is my whole person, the object, that is
    //unable to be represented by lines of text

    using value_type = T; //Outside bag::value_type
    using size_type = std::size_t; //std::size_t is the size type that's used as an index of an array
    //typically an unsigned long int or some sort of 64 bit unsigned int

    size_type size() const;

    void insert (const value_type& value);
    size_type count(const value_type& value) const;

    bool erase_one(const value_type& value);
    size_type erase(const value_type& value);

    value_type* begin();
    value_type* end();

    void operator +=(const bag& that);
};

template <typename T>
bag<T> operator+(const bag<T>& bag1, const bag<T>& bag2);

template <typename T>
typename bag<T>::value_type *bag<T>::begin(){
    return data_;
}

template <typename T>
typename bag<T>::value_type* bag<T>::end(){
    return data_ + size_;
}

#endif // BAG_H

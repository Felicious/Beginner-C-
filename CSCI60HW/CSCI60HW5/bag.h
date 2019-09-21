#ifndef bag_H
#define bag_H
#include <cstdlib>
#include <string>

template <typename T>
class Uniquebag {
 public:
    uniquebag();
    uniquebag(const Uniquebag<T>& that);
    Uniquebag& operator=(const Uniquebag<T>& that);

    using value_type = T;
    using size_type = std::size_t;
    static constexpr size_type CAPACITY = 25;  // uniquebag::CAPACITY

    size_type size() const;
    void insert(const value_type& value);
    size_type count(const value_type& value) const;
    bool erase_one(const value_type& value);
    size_type erase(const value_type& value);

    void operator+=(const Uniquebag& that);

    void debug_info(std::string name);  // Added to help with debugging
 private:
    value_type data_[CAPACITY] = {0};
    size_type size_ = 0;
};

template <typename T>
Uniquebag<T> operator+(const Uniquebag<T>& rhs, const Uniquebag<T>& lhs);

//
// Implementations below this point.
//

template <typename T>
Uniquebag<T>::uniquebag() {}

template <typename T>
Uniquebag<T>::uniquebag(const Uniquebag<T>& that) {
    size_ = that.size_;
    for (size_type i = 0; i < size_; ++i) data_[i] = that.data_[i];
}

template <typename T>
Uniquebag<T>& Uniquebag<T>::operator=(const Uniquebag<T>& that) {
    if (this == &that) return *this;
    size_ = that.size_;
    for (size_type i = 0; i < size_; ++i) data_[i] = that.data_[i];
    return *this;
}

template <typename T>
typename Uniquebag<T>::size_type Uniquebag<T>::size() const {
    return size_;
}

template <typename T>
void Uniquebag<T>::insert(const Uniquebag<T>::value_type& value) {
  assert(size_ < CAPACITY);
  if(count(value)==0)
  data_[size_++] = value;
}

// We need to prefix the return type to this function with 'typename', as
// uniquebag<T>::size_type is what is known as a dependent type.
//
// You can read more about dependent types here:
//   http://en.cppreference.com/w/cpp/language/dependent_name
template <typename T>
typename Uniquebag<T>::size_type Uniquebag<T>::count(
    const Uniquebag<T>::value_type& value) const {
  size_type count = 0;
  for (size_type i = 0; i < size_; ++i) {
    if (data_[i] == value) count++;
  }
  return count;
}

template <typename T>
bool Uniquebag<T>::erase_one(const Uniquebag<T>::value_type& value) {
    size_type i = 0;
    while (i < size_ && data_[i] != value) ++i;
    if (i == size_) return false;
    data_[i] = data_[--size_];
    return true;
}

template <typename T>
typename Uniquebag<T>::size_type Uniquebag<T>::erase(const Uniquebag<T>::value_type& value) {
  size_type count = 0;
  while (erase_one(value)) ++count;
  return count;
}

template <typename T>
void Uniquebag<T>::operator+=(const Uniquebag<T>& that) {
    for (size_type i = 0; i < that.size_; ++i) insert(that.data_[i]);
}

template <typename T>
void Uniquebag<T>::debug_info(std::string name) {
  using namespace std;
  cout << name << endl;
  cout << "    size_ = " << size_ << endl << "    data_ = {";
  for (size_type i = 0; i < size_; ++i) {
    cout << data_[i];
    if (i < size_ - 1) cout << ", ";
  }
  cout << "}" << endl;
}

template <typename T>
Uniquebag<T> operator+(const Uniquebag<T>& rhs, const Uniquebag<T>& lhs) {
  Uniquebag<T> temp = rhs;
  temp += lhs;
  return temp;
}

#endif // uniquebag_H

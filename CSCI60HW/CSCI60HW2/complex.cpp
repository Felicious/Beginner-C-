#include <iostream>
#include <fstream>
#include "header.h"

std::ostream& operator<<(std::ostream& os, Complex x) {
  os << x.get_real() << " + " << x.get_imag() << "i";
  return os;
}

Complex operator+(Complex lhs, Complex rhs) {
  return Complex(lhs.get_real() + rhs.get_real(),
                 lhs.get_imag() + rhs.get_imag());
}

Complex operator*(Complex lhs, Complex rhs) {
  return Complex(
      lhs.get_real() * rhs.get_real() - lhs.get_imag() * rhs.get_imag(),
      lhs.get_imag() * rhs.get_real() + lhs.get_real() * rhs.get_imag());
}

Complex operator-(Complex lhs, Complex rhs){
    return Complex(lhs.get_real() - rhs.get_real(),
                   lhs.get_imag() - rhs.get_imag());
}

Complex operator/(Complex lhs, Complex rhs){
    return Complex(lhs.get_real() / rhs.get_real(),
                   lhs.get_imag() / rhs.get_imag());
}

bool operator==(Complex lhs, Complex rhs){
    bool equals = false;
    if((lhs.get_real() == rhs.get_real())||(lhs.get_imag() == rhs.get_imag())){
        equals = true;
    }
    return equals;
}

bool operator!=(Complex lhs, Complex rhs){
    bool not_equals = false;
    if((lhs.get_real() != rhs.get_real())||(lhs.get_imag() != rhs.get_imag())){
        not_equals = true;
    }
}

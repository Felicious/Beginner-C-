#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>

class Complex {
 private:
  double real_;
  double imag_;

 public:
  Complex(double real, double imag){
      real_ = real;
      imag_= imag;
  }
  Complex(){
      real_ = 0;
      imag_ = 0;
  }

  double get_real();
  double get_imag();

void operator+=(Complex rhs){
    real_ += rhs.get_real();
    imag_ += rhs.get_imag();
}
void operator-=(Complex rhs){
    real_ -= rhs.get_real();
    imag_ -= rhs.get_real();
}
void operator*=(Complex rhs){
    real_ = (real_*rhs.get_real()) - (imag_*rhs.get_imag());
    imag_ = (real_*rhs.get_imag()) + (imag_*rhs.get_real());
}
void operator/=(Complex rhs){
    real_ = ((real_*rhs.get_real()) - (imag_*(-rhs.get_imag())))/(pow(rhs.get_real(),2)-pow(rhs.get_imag(),2));
    imag_ = ((real_*(-rhs.get_imag())) + (imag_*rhs.get_real()))/(pow(rhs.get_real(),2)-pow(rhs.get_imag(),2));
}
Complex operator+(){
    return Complex(real_,imag_);
}

Complex operator-(){
    return Complex(-real_,-imag_);
}

Complex conju(Complex num){
    return Complex(num.real_,-num.imag_);
}
};

#endif // HEADER_H

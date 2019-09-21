#include <iostream>
#include "header.h"

// Implementation of Complex class methods

double Complex::get_real() { return real_; } //this is what happens when get_real() is called

double Complex::get_imag() { return imag_; }

std::ostream& operator<<(std::ostream& os, Complex x);
Complex operator+(Complex lhs, Complex rhs);
Complex operator*(Complex lhs, Complex rhs);
Complex operator-(Complex lhs, Complex rhs); //subtraction
Complex operator/(Complex lhs, Complex rhs); //division
bool operator==(Complex lhs, Complex rhs); //equality
bool operator!=(Complex lhs, Complex rhs); //not equals
Complex conju(Complex num);


int main()
{
    Complex x(8,2);
    Complex y(2,-3);
    std::cout<< " x + y: " << x + y << std::endl;
    std::cout<< " x - y: " << x - y << std::endl;
    std::cout<< " x * y: " << x*y << std::endl;
    std::cout<< " x / y: " << x/y << std::endl;
    std::cout<< " +x: " << +x << std::endl;
    std::cout<< " -x " << -x << std::endl;
    x+=y;
    std::cout<< " x+=y: " << x << std::endl;
    x-=y;
    std::cout<< " x-=y: " << x << std::endl;
    x*=y;
    std::cout<< " x*=y: " << x << std::endl;
    x/=y;
    std::cout<< "x/=y:" << x << std::endl;

    return 0;
}


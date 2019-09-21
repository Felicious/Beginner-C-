#include "shape.h"
#include <fstream>

shape::shape(){
    x_ = 0;
    y_ = 0;
}

shape::shape(double x, double y)
    : x_(x), y_(y) //sets x equal to x_
{
}

void shape::setY(double y){
    y_ = y;

}
void shape::setX(double x){
    x_ = x;
}

std::ostream& operator <<(std::ostream& os, shape s){
    os << "x = " << s.x() << "y= " << s.y() <<std::endl;
}

#include <iostream>
#include <cmath>

using namespace std;
double tri_area(double base, double height);

int main() {
    double a=0;
    double b=0;
    cout<<"Enter the base: ";
    cin>>a;
    cout<<"Enter the height: ";
    cin>>b;
    cout<<"The area of the triangle: "<<tri_area(a,b);
    return 0;
}
double tri_area(double base, double height){
    double area = (base*height)/2;
    return area;
}

#include <iostream>
#include <cmath>

using namespace std;
bool ap(double a, double b, double c, double &inside, double &outside);

int main()
{
    double a=0;
    cout<< "Enter the side length of a: ";
    cin>>a;
    double b=0;
    cout<<"Enter the side length of b: ";
    cin>>b;
    double c=0;
    cout<<"Enter the side length of c: ";
    cin>>c;
    double area, perimeter;
    if (ap(a,b,c,area,perimeter)){
        cout<<"Your area is: "<<area<<".\n";
        cout<<"Your perimeter is: "<<perimeter<<".\n";
    }
    else {
        cout<<"Your side lengths do not make a triangle.\n";
    }

    return 0;
}
bool ap(double a, double b, double c, double &inside, double &outside){
    double s = ((a+b+c)/2);
    double x = s*(s-a)*(s-b)*(s-c);
    if ((x<0)||(a<0)||(b<0)||(c<0)){
        return false;
    }
    else{ //(x>0)
        inside = sqrt(x);
        outside = a+b+c;
        return true;
    }
    }


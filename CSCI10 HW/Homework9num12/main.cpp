#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Point2D{
    double x;
    double y;
};

void print_point(Point2D p);
Point2D get_point();
double ur_distance(Point2D p, Point2D q);

int main()
{
    Point2D p;
    Point2D q;
    p = get_point();
    q = get_point();
    cout<< ur_distance(p,q);

    return 0;
}
void print_point(Point2D p){
    cout<<"("<<p.x<<","<<p.y<<")"<<endl;
}
Point2D get_point(){
    Point2D p;
    cout << "Enter an x: ";
    cin>>p.x;
    cout << "Enter a y: ";
    cin>>p.y;
    return p;
}
double ur_distance(Point2D p, Point2D q){
    double heron = pow((p.x - q.x),2) + pow((p.y - q.y),2);
    return sqrt(heron);
}

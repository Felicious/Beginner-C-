#include <iostream>
#include <cmath>

using namespace std;
double average(double s[], int sz);
double deviation(double s[], int sz);

int main()
{
    int sz = 9;
    double s[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<"The average is: "<<average(s,sz)<<" The standard deviation is: "<<deviation(s,sz);
    return 0;
}

double average(double s[], int sz){
    double sum = 0;
    for (int i = 0; i < sz; i++){
        sum += s[i];
    }
    double ave = sum/sz;
    return ave;
}
double deviation(double s[], int sz){
    double disgusting = 0;
    for (int i = 0; i<sz; i++){
        disgusting += pow(s[i]-average(s,sz),2);
    }
    double blah = disgusting/sz;
    return sqrt(blah);
}

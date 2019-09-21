#include <iostream>

using namespace std;

int main()
{
int sec = 0;
cout << "Please enter time in seconds: ";
cin >> sec;
int m = sec/60;
sec = sec % 60;
int hour = m/60;
m = m % 60;
int day = hour/24;
hour = hour % 24;
int year = day/365;
day = day % 365;

if (year > 0) {
    if (year == 1){
        cout << year << " year ";
    }
    else {
        cout << year << " years ";
    }
}
if (day > 0) {
    if (day == 1){
        cout << day << " day ";
    }
    else {
        cout << day << " days ";
    }
}
if (hour > 0) {
    if (hour == 1){
        cout << hour << " hour ";
    }
    else {
        cout << hour << " hours ";
    }
}
if (m > 0) {
    if (m == 1){
        cout << m << " minute ";
    }
    else {
        cout << m << " minutes ";
    }
}
if (sec > 0) {
    if (sec == 1){
        cout << sec << " second ";
    }
    else {
        cout << sec << " seconds ";
    }
}

return 0;
}

#include <iostream>

using namespace std;

template<typename T> //templates aren't code; cookie cutters aren't cookies and are used to make cookies!
T my_max(T x, T y){
    if (x > y){
        return x;
    }else{
        return y;
    }
}// function that isn't a function; it makes functions and returns them

string dbl (string s){
    return s+s;
}

int main()
{
    int a = 5;
    int b = 7;
    cout << my_max(a,b) << endl;
    double x = 7.5;
    double y = 9.0;
    cout << my_max(x,y);//tests whether it actually makes a function
    auto v = 5; //the program can figure out the type you're using. types are optional
    return 0;
}

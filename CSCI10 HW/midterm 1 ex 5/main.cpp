#include <iostream>

using namespace std;

int main()
{
    int n=0;
    //product
    int p =1;
    cout << "Input a number: ";
    cin >> n;
    for (int x=1; x<(n+1); x++){
        p=(p*x);
    }
    cout << p;

    return 0;
}

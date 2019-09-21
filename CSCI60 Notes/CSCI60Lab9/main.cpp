#include <iostream>
#include <node.h>
#include <lbiguint.h>

using namespace std;

int main()
{

    lbiguint a("1472");
    lbiguint b(1472);
    //b.~lbiguint();

    cout << a << endl;
    cout << b;
    return 0;
}

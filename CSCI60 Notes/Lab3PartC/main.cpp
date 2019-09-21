#include <iostream>
#include "template.h"

using namespace std;
template <typename T1, typename T2>
T1 frequent(T1 a[], T2 size);

int main()
{
    int y = 10;
    int x[y] = {2,3,45,6,7,2,2,2,2,4};
    cout<<frequent(x,y)<<endl;
    return 0;
}

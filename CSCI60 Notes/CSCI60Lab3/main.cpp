#include "rational.h"
#include "coordinate.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int size = 4;
    int oo[size] = {3,4,2,1};
    Coord <int> test(oo,4);
    int ill[size] = {1,4,3,1};
    Coord <int> test2(ill,4);
    for(int i = 0; i < 4; i++){
        cout<<(test.get_item(i)+test2.get_item(i))<<endl;
    }

    cout<<(oo==ill)<<endl;



    return 0;
}

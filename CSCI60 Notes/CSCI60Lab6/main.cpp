#include <iostream>
#include "dbigunit.h"


int main()
{
    dbiguint a(0);
    dbiguint b(1246888775);
    std::cout<<b[2]<<std::endl; //couts 7
    std::cout << b << std::endl; //couts 1246.....
    std::cout << b.size() << std::endl; //couts 10


    return 0;
}

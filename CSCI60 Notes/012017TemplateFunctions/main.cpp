#include <iostream>
#include "maybe.h"

int main()
{
    Maybe<int> t(3);
    std::cout << t.has_value() << std::endl <<t.value() << std:endl;
    return 0;
}

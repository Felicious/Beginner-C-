#include <iostream>
#include <cassert>

using age = int; //means that every time there is an age, it is an int

age year(age x) {
    return x+1;
}

int main()
{
    //this can basically check if what u typed equals the thing u want
    int n;
    std::cin >> n;
    assert(n==10);

    age x =20;
    std::cout << x << std::endl;
    return 0;
}

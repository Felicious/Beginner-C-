#include <iostream>
#include <array>

int main(){
    std::array<int,5> arr = {0,1,2,3,4};
    std::cout << arr[3] << std::endl << arr.size() << std::endl; //modern arrays return size!!!!!
    //std::cout << arr.at(10); //.at checks bounds

    for (auto x : arr) //this loops over the values in the array
        std::cout << x << " "; //this prints out 0 1 2 3 4
    for (auto& y : arr)
        y = 0; //zero outs all values in the array
        std::cout << y;
    return 0;
}

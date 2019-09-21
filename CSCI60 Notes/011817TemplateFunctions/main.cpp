#include <iostream>

template<typename T1, typename T2>
T1 my_sum(T1 a, T2 b){
    return a+b;
}
//template<typename T1, typename T2>
//auto my_sum(T1 a, T2 b) -> decltype(a+b)
//return a+b;

int main(){

    int x = 5;
    double y = 7.7;
    //returns a sum of the type of the first number.
    std::cout << my_sum(x,y)<<std::endl;
    //if you do this, you are telling it the type.
    std::cout << my_sum<double>(x,y)<<std::endl;

    //floats and doubles and stuff
    auto n = div(a,b);
    if (n.fail()){

    }
    int i = n.value();
    std::cout << 0/0 << std::endl; //garbage
    std::cout << 1.0/0 << std::endl; //infinity
    std::cout << -1.0/0 <<std::endl; // negative infinity
    std::cout << 0.0/0.0 << std::endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

template <typename T, typename S>
S max_index(std::vector<T>& vec, S sz){
    S max_i = 0;
    T max = vec[max_i];
    for (S i = 0; i < sz; ++i){
        if( max < vec[i]){
            max_i = i;
            max = vec[max_i];
        }
    }
    return max_i;
}

template <typename T, typename S>
void selection_sort(std::vector<T>& vec, S sz){ //should pass a vector by reference, not copy
    if(sz == 0) return; //means if sz = 0, end the program
    S k = max_index(vec,sz);
    std::swap(vec[sz-1],vec[k]);
    selection_sort(vec,sz-1); //a function call to yourself is no more special than
    //a function call to other functions
}

int main()
{
    //the proper way to use random generators
    //three step process:
    std::random_device rd; //initialize with "true random number generators"
    std::mt19937 engine(rd()); //initialize truly random bit generator
    //this will give us a stream of random bits
    //always pass/return this by reference or you'll get the same random number
    std::uniform_int_distribution<int> ud(-100,100);
    //u want to uniformly distribute ur random numbers

    //sorting of random numbers using selection sort
    //selection sort swaps the bigger number u encounter and put it at the end. second
    //loop disregards the final element where the swapped final element is ignored

    std::vector<int> vec;
    for(int i = 0; i < 10; ++i) vec.push_back(ud(engine));
    for(const auto& e : vec) std::cout << e << " ";
    std::cout << std::endl;
    selection_sort(vec, vec.size());
    for(const auto& e : vec) std::cout << e << " ";
    return 0;
}

#include <iostream>

int sum_n(int k){
    int ret = 0;
    if(k == 0){
        ret = 0;
    }else{
        ret = sum_n(k-1);
    }
    return k + ret;
}//must assume ur program works for the recursive value, and then u add the right value.
//for example, if you wanted to sum of numbers from 1 - 10, you assume you have the right
//sum from 1 to 9 and you just add 10 to that sum.

//fibonachi and do multiple function calls
int fib(int n){
    if(n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    int s = sum_n(5);
    std::cout<<s<<std::endl;


    return 0;
}

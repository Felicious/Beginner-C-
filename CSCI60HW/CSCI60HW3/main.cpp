#include <iostream>

//#1
template<typename T>
T my_dist(T a, T b){
    if ((a-b) < (b-a)){
        return b-a;
    }else{
        return a-b;
    }
}

//#2
template<typename T1, typename T2>
T1 my_product(T1 arr[], T2 sz){
    T1 total = arr[0];
    for (T2 i = 1; i < sz; i++){
        total*=arr[i];
    }
    return total;
}

//#3
template<typename T>
void my_swap(T &a, T &b){
    T temp;
    temp = b;
    b = a;
    a = temp;
}

//#4
template<typename T1, typename T2>
T2 my_mismatch(T1 arr1[], T1 arr2[], T2 sz){
    for (T2 i = 0; i < sz; i++){
        if(arr1[i] != arr2[i]){
            return i;
        }
    }
    return sz;
}

int main()
{
    //#1
    int x(8);
    int y(5);
    std::cout<<my_dist(x,y)<<std::endl;
    //#2
    int a[5]={1,2,3,4,5};
    std::cout<<my_product(a,5)<<std::endl;
    //#3
    std::string g = "aaa";
    std::string h = "b&w";
    my_swap(g,h);
    std::cout<< "g = " << g << " h= " << h << std::endl;
    //#4
    int z[3]={1,2,3};
    int j[3]={1,2,5};
    std::cout<<my_mismatch(z,j,3)<<std::endl;
    return 0;
}

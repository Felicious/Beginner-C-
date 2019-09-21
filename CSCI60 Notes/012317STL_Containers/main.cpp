#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    using std::cout;
    using std::endl;
    //vectors
    std::vector<int> vec; //no () !
    //can initialize like an array :
    // vector<int> vec = {9,9,9,9,9,9};
    for (int i = 0; i < 10; i++){
        vec.push_back(i); //this re-sizes arrays!
    }
    vec.pop_back();
    for (auto x : vec){
        //std::cout<< x << " ";
    }

    std::vector<int> vect = {3,1,4,7,3,2,7,1,8,9,3,2};
    std::sort(vect.begin(), vect.end());
    for (auto x : vect) cout << x << " ";
    cout << endl;

    //starting a function that switches the sorting order -> 9 8 7 to 7 8 9
    auto comp = [](int a, int b) {return a > b;}; //this is a Lambda
    cout << comp(3,2) << endl << comp(1,10); //tests to see if the function above works.

    //passing a function into a function.
    //Lambdas: throw away functions that allows functions to return functions
    std::sort(vec.begin(), vec.end(), [](int a, int b)  {return a > b;}    ); //probably never put anything in the [].


    return 0;
}

#include <iostream>
#include <utility>
#include <tuple>

int main(){
    // this is a type name that is ugly:
    std::pair<std::string, int> name_id("Felicia", 60310);

    //better alternative (:
    /* auto name_id = std::make_pair("Felicia", 60310);

    std::cout << "first = " << name_id.first<< std::endl;
    std::cout << "second = " << name_id.second << std::endl; */

    //the prettiest way!
    auto name_id = std::make_pair("Felicia", 60310);

    string name;
    int id;
    std::tie(name,id) = name_id;
    //C++ 17 way : auto [name , id] = name_id;
    //this way can work with structs
    std::cout << name << std::endl << std::cout << id <<std::endl;

    return 0;
}

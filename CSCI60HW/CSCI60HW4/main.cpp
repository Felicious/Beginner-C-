#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <map>
#include <vector>

int main(){
    std::ifstream in_file;

    std::map<int, std::pair<int,std::vector<std::string>>>mappie;

    in_file.open("/Users/freak/OneDrive/Documents/CSCI60HW/CSCI60HW4/scores.txt");
    assert(!in_file.fail() && "file didn't open");

    //putting values into the map
    std::string key;
    std::string name;
    while(std::getline(in_file,key,' ')){
        int score = 0;
        score = std::stoi(key); //the index u will use as key to get info from pair
        mappie[score].first++;//number of ppl who got the score

        getline(in_file, name); //gets the rest of the line, which is the name
        mappie[score].second.push_back(name); //name of the person/ppl who has the score

    }
    in_file.close();

    //printing out the complete histogram:
    for (int i = 0; i <= 10; i++){
        std::cout << i << '\t';
        for(int j = 0; j < mappie[i].first; j++){
            std::cout << "X";
        }
        std::cout << std::endl;
    }

    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    int scoree = 0;
    scoree = stoi(input);

    std::cout << "The people who received the score "<< scoree << " are " << std::endl;
    for(int i = 0; i < mappie[scoree].second.size(); i++){
        std::cout << mappie[scoree].second[i] << std::endl;
    }


    return 0;
}

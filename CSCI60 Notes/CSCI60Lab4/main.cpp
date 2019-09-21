#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main()
{
    /*a) */ set<string> ppl_served;
    ifstream in_file;
    ofstream out_file;
    in_file.open("/Users/freak/OneDrive/Documents/CSCI60 Notes/CSCI60Lab4/names.txt");

    for(string word; getline(in_file, word);){
        ppl_served.insert(word);
    }
    in_file.close();
    out_file.open("people.txt");
    for (auto x : ppl_served) out_file << x <<endl;
    out_file.close();

    return 0;
}

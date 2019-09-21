#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string revrse(string s);

int main()
{
    ifstream in_file;
    ofstream out_file;
    in_file.open("input.txt");
    string s[1000];
    string line;
    string another;
    int count = 0;
    while (getline(in_file, line)){
        another = revrse(line) + '\n';
        s[count] += another;
        count++;
    }
    in_file.close();
    out_file.open("input.txt");
    for (int i = 0; i < count; i++){
        out_file << s[i];
    }
    out_file.close();
    return 0;
}
string revrse(string s){
    string newstring = "";
    for (int i = s.length()-1; i >= 0; i--){
        newstring += s.at(i);
    }
return newstring;
}

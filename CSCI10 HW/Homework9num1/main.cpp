#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in_file;
    ofstream out_file;
    in_file.open("input.txt");
    out_file.open("output.txt");
    string s;
    while(getline(in_file,s)){
        if((s[0] != '/') && (s[1] != '/')){
            out_file << s << endl;
        }
    }
    in_file.close();
    out_file.close();
    return 0;
}

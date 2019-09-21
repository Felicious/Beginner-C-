#include <iostream>

using namespace std;
string remove_vowel(string s);
bool isvowel(string s);
int main()
{
    cout<<remove_vowel("Hello my NAME'S Michael!!!!");
    return 0;
}
bool isvowel(char x){
        if ((x == 'a')||(x=='A')||(x=='e')||(x=='E')||(x=='o')||(x=='O')||(x=='i')||(x=='I')||(x=='u')||(x=='U')){
            return true;
        }else{
            return false;
        }
}
string remove_vowel(string s){
    string new_string;
    for (int i = 0; i < (s.length()); i++){
        if (isvowel(s[i]) == false){
            new_string += s[i];
        }
    }
    return new_string;
}

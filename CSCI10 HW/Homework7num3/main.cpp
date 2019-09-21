#include <iostream>
#include <string>

using namespace std;
string revrse(string s);
bool palindrome(string s);
int main()
{
    string s = "racecar";
    cout<< revrse(s)<< endl << palindrome(s)<<endl;
    return 0;
}
string revrse(string s){
    string newstring = "";
    for (int i = s.length()-1; i >= 0; i--){
        newstring += s.at(i);
    }
return newstring;
}
bool palindrome(string s){
    if (s == revrse(s)){
      return true;
    }else{
    return false;
    }
}


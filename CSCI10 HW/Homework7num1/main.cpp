#include <iostream>

using namespace std;
int str2int(string s);
int calculate(string s, int first_i);


int main()
{
    cout<< str2int("-476589");
    return 0;
}
int str2int(string s){
    int neg = 1;
    int x = 0;
    int first_i = 0;
    if (s[0]== '-'){
        first_i = 1;
        neg = -1;
    }
    x = neg*calculate(s,first_i);
    return x;
}
int calculate(string s, int first_i){
    int temp =0;
    int y = 0;
    for(int i = first_i; i<s.length();i++){
        y = (s[i]-'0');
        for (int j = 0; j < (s.length()-(i+1)); j++){
            y *= 10;
        }
            temp += y;
    }
    return temp;
}

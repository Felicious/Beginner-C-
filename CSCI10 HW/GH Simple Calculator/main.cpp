#include <iostream>
#include <string>

using namespace std;
void location_of_math(string input, int n_of_i[], int &count);

int main()
{
    string input;
    getline(cin, input);
    int count = 0;
    int n_of_i[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    location_of_math(input, n_of_i, count); //function figures out the position (i) of the sign u want to calculate with
    return 0;
}
void location_of_math(string input, int n_of_i[], int &count){
    count = 0;
    for (int i = 0; i < input.length(); i++){
        if ((input[i] == '+')||(input[i] == '-')||(input[i] == '/')||(input[i] == '*')){
            n_of_i[count] += i;
            count++;
        }
    }
}

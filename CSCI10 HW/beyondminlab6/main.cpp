#include <iostream>


using namespace std;

void factors(int n, int facts[]);
bool isperfect(int n, int factors[]);

int main()
{
    int a[50];
    int test =0;
    cout << "Enter a number!" << endl;
    cin >> test;
    if (test >= 50){
        cout << "Sorry! Can't test numbers that high!";
    }
    else{
        factors(test, a);
        if (isperfect(test,a)==true){
            cout << "Perfect!" << endl;
        }
        else{
            cout << "Imperfect. :(" << endl;
        }
    }
    return 0;
}

void factors(int n, int facts[]){
    facts[0] = 0;
    for (int i = 1; i<=n; i++){
        if ((n%i)== 0){
            facts[i] = 1;
        }else {
            facts[i] = 0;
        }
    }
}

bool isperfect(int n, int factors[]){
    int sum = 0;
    for (int i = 1; i<n; i++){
        if (factors[i]==1){
            sum+=i;
        }
    }
    if (sum == n){
        return true;
    }
    else{
        return false;
    }
}

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void rng(int a, int b, int &x);
void test(int y,int rn,bool&s);

int main(){
    int rn;
    rng(1,100,rn);
    int y=0;
    cout<<"I have chosen a number between 1 and 100 Try to guess it!\n";
    bool win = false;
    test(y,rn,win);
if (win == true){
    cout<<"You have guessed it!!!\n";
}
else{
    cout<<"You lost. My number was "<<rn<<".\n";
}
 return 0;
}
void rng(int a, int b, int &x){
    srand(time(0));
    rand();
    x= (rand() % (b-a+1)+a);

}
void test (int y,int rn,bool&s){
    for (int i=0; i<8; i++){
        cin >>y;
        if (rn != y){
            if(y>rn){
                cout<<"Your number is too big!\n";
            }
            else { //y<rn
                cout<<"Your number is too low!\n";
            }
        }
        else{
            s = true;
            break;
        }
    }
}

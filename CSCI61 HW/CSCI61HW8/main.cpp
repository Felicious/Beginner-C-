#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main(){
    int N(7);
    for (int i = 1; i <= N; ++i){
        string name("g");
        name = name + to_string(i) + ".txt";
        ifstream s(name);
        if (s.fail()){
            cout << "Can't open file for reading!" << endl;
            exit(1);
        }
        graph g;
        s >> g;
        s.close();
        cout << g.two_colorable() << endl;
    }
    return 0;
}

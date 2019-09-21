#include <iostream>
#include "btnode.h"
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

btnode<int> * make_tree(int n){
    if (n == 0)
        return new btnode<int>(0);
    int c = rand() % 3;
    switch(c){
        case 0:
            return new btnode<int>(0, make_tree(n));
        case 1:
            return new btnode<int>(0, nullptr, make_tree(n));
        case 2:
            int l = rand() % n;
            int r = n-1-l;
            return new btnode<int>(0, make_tree(l), make_tree(r));
    }
}

int main(){
    srand(time(0));
    for (int i = 0; i < 1000; ++i){
        int r = rand() % 1000;
        btnode<int> *root = make_tree(r);
        assert(r == n2(root));
        bt_clear(root);
    }
    cout << "Passed!" << endl;
    return 0;
}

#include <iostream>
#include "queue.h"
#include <cstdlib>
#include <ctime>

int main(){
    queue<int> Q;
    queue<int> q;

    srand(time(0));

    for (int i = 0; i < 10000000; ++i){
        int choice = rand() % 2;
        int r;
        switch(choice){
            case 0:
                if (!q.empty())
                    q.pop();
                if (!Q.empty())
                    Q.pop();
                break;
            case 1:
                r = rand();
                q.push(r);
                Q.push(r);
                break;
            default:
                break;
        }
        // verify
        assert(q.size() == Q.size() && q.empty() == Q.empty());
        if  (!q.empty())
            assert(q.front() == Q.front());
    }

    std::cout << "Passed!" << std::endl;

    return 0;
}

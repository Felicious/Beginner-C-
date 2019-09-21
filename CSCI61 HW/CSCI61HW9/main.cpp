#include <iostream>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "graph.h"
#include <cassert>

using namespace std;
bool valid(const string &s, const string &t){
    assert(s.size() == t.size());
    int n = static_cast<int>(sqrt(s.size()));
    char label = '0' + s.size();

    int e1 = s.find(label);
    int e2 = t.find(label);

    for (int i = 0; i < s.size(); ++i)
        assert(s[i] == t[i] || s[i] == label || t[i] == label);

    return (e1-e2 == 1 && e1 % 3 != 0) || (e2-e1 == 1 && e2 % 3 != 0) || (abs(e1-e2) == 3);
}
set<string> poss_moves(const string & initial){
    size_t pos = initial.find("9");
    size_t top = pos - 3;
    size_t right = pos + 1;
    size_t bot = pos + 3;
    size_t left = pos - 1;
    string copy = initial;
    set<string> ans;
    if(0==(pos%3)){ //on the left, so will always have a right
        swap(copy[pos],copy[right]);
        ans.insert(copy);
        copy = initial;
        if(6!=pos){ //6 doesn't have a bot, so this works with 0 3
            swap(copy[pos],copy[bot]);
            ans.insert(copy);
        }
        copy = initial;
        if(0!=pos){//0 doesnt have top, so this works with 3 6
            swap(copy[pos],copy[top]);
            ans.insert(copy);
        }
    }else if(1==(pos%3)){ //has a left and right
        swap(copy[pos],copy[left]);
        ans.insert(copy);
        copy = initial;
        swap(copy[pos],copy[right]);
        ans.insert(copy);
        copy = initial;
        if(7!=pos){ //5 no bot, so this works with 1 4
            swap(copy[pos],copy[bot]);
            ans.insert(copy);
        }
        copy = initial;
        if(1!=pos){ //1 no top, so swap top with rest
            swap(copy[pos],copy[top]);
            ans.insert(copy);
        }
    }
    else{ // on the right, so always have a left
        swap(copy[pos],copy[left]);
        ans.insert(copy);
        copy = initial;
        if(2!=pos){//2 doesn't have a top, but others do
            swap(copy[pos],copy[top]);
            ans.insert(copy);
        }
        copy = initial;
        if(8!=pos){//8 doesn't have a bot, but others do
            swap(copy[pos],copy[bot]);
            ans.insert(copy);
        }
    }
    return ans;
}

void fill_edges(digraph &g){
    for(auto &e: g.V())
        for(auto &f: poss_moves(e))
            g.add_edge(e,f);
}

vector<string> solve_8_puzzle(const string & initial){
    string s = "123456789";
    digraph g;
    do{
        g.add_vertex(s);
    }while(next_permutation(s.begin(), s.end()));
    fill_edges(g);
    // BFS init
    std::queue<string> q;
    q.push(initial);
    unordered_map<string,string> parents;
    parents[initial] = initial;
    // BFS loop
    while (!q.empty()){
        string front = q.front();
        q.pop();
        for (auto n: g.adj(front)){
            if (!parents.count(n)){
                parents[n] = front;
                q.push(n);
             }
         }
     }
    vector<string> ans;
    if(!parents.count(s)) return ans;
    for(string r = s; r != initial; r = parents[r])
        ans.push_back(r);
    ans.push_back(initial);
    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    srand(time(0));

        for (int c = 1; c < 20; ++c)
        {
            string initial, final;
            initial = final = "123456789";

            random_shuffle(initial.begin(), initial.end());
            int inv(0);
            for (int i = 0; i < 9; ++i)
                for (int j = i+1; j < 9; ++j)
                {

                    if (initial[i] != '9' && (initial[i] > initial[j]))
                        ++inv;
                }
            vector<string> path = solve_8_puzzle(initial);

            if (inv % 2 == 0)
            {

            cout << "Solvable ..." << endl;
                for (size_t i = 0; i < path.size() - 1; ++i)
                    assert(valid(path[i], path[i+1]));
                assert(path[0] == initial && path[path.size()-1] == final);
            }
            else
        {
            cout << "Unsolvable ..." << endl;
                assert(path.size() == 0);
            }

     }

     cout << "Passed!" << endl;
     return 0;
}


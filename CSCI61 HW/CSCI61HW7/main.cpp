#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class word_coord{
public:
    string w;
    pair<int,int> begin;
    pair<int,int> end;
};
bool operator < (const string &l) const {
    return (l < l.w);
}

//functions we need:
//1. reads dictionary
set<string> create_d(){
    set<string> d;
    ifstream ds("words.txt");
    string w,x,y;
    while(ds >> w){
        if(w.size() >= 6)
            d.insert(w);
    }
    ds.close();
    return d;
}

int main(){
    vector<vector<char>> v;
    v.push_back(vector<char>());
    ifstream in("puzzle.txt");
    if(in.fail()){
        cout << "can't open file! ):" << endl;
        return 1;
    }
    string line;
    int nrows(0), ncols(0);
    //creates the puzzle and finds out the # of rows and columns
    if(getline(in,line)){
        ++nrows;
        for(auto &e: line)//loops through line, which is a vector. auto == char
            if(e != ' ')
                v[0].push_back(e);
        ncols = line.size();
    }
    while(getline(in, line)){
        vector<char> temp;
        for (auto &e : line)
            if (e != ' '){
                temp.push_back(e);
                v.push_back(temp);
            }
        ++nrows;
    }
    in.close();
    set<string> dictionary(create_d());
    set<word_coord> ans;

    for (int i(0); i < nrows; ++i)
        for (int j(0); j < ncols; ++j)
            for (int x(-1); x <= 1; ++x)
                for (int y(-1); y <= 1; ++y){
                    string w;
                    int xpos = i;
                    int ypos = j;
                    while (((xpos + x) >= 0) && ((ypos + y) >= 0) && ((xpos + x) < nrows) && ((j + ypos) < ncols) && ((x != 0) || (y != 0))){
                        xpos += x;
                        ypos += y;
                        w += v.at(xpos).at(ypos);
                        if(6 <= w.size())
                            for(auto &f: dictionary)
                                if(w == f){
                                    word_coord temp;
                                    temp.w = w;
                                    temp.begin.first = i;
                                    temp.begin.second = j;
                                    temp.end.first = xpos;
                                    temp.end.second = ypos;
                                    ans.insert(temp);
                                }
                    }
                }
    for(auto &g: ans)
        cout << g.w <<" ("<<g.begin.first<<", "<<g.begin.second<<") to ("<<g.end.first<<", ("<<g.end.second<<")"<<endl;
    return 0;
}

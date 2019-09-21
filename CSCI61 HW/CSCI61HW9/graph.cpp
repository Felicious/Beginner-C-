#include "graph.h"
#include <cassert>
#include <stack>
#include <list>

digraph::digraph(){
    _m = std::unordered_map<std::string, std::set<std::string>> ();
}

std::size_t digraph::n() const{
    return _m.size();
}


std::size_t digraph::m() const{
    std::size_t ans(0);
    for (auto p: _m){
        ans += p.second.size();
    }
    return ans;
}

std::set<std::string> digraph::V() const{
    std::set<std::string> ans;
    for (auto p: _m)
        ans.insert(p.first);
    return ans;
}

std::set<std::string> digraph::adj(const std::string &v) const{
    assert(_m.find(v)  != _m.end() );
    return (_m.find(v)->second);
}

bool digraph::is_edge(const std::string &a, const std::string &b) const{
    assert(_m.find(a) != _m.end() && _m.find(b) != _m.end());
    return (_m.find(a)->second.find(b) != _m.find(a)->second.end());

}

void digraph::add_vertex(const std::string &v){
    if (_m.find(v) != _m.end())
        return;
    _m[v] = std::set<std::string>();
}

void digraph::add_edge(const std::string & a, const std::string &b){
    assert(_m.find(a) != _m.end() && _m.find(b) != _m.end());
    if (is_edge(a, b))
        return;
    _m[a].insert(b);
}

std::ostream & operator << (std::ostream & os, const digraph & d){
    os << d.n() << " " << d.m() << std::endl;
    for (auto v: d.V())
        os << v << " ";
    os << std::endl;
    for (auto v: d.V())
        for (auto w: d.adj(v))
            os << v << " " << w << std::endl;

    return os;
}

std::istream & operator >>(std::istream & is, digraph & d){
    std::size_t n, m;
    d = digraph();
    is >> n >> m;
    for (std::size_t i = 0; i < n; ++i){
        std::string v;
        is >> v;
        d.add_vertex(v);
    }

    for (std::size_t i = 0; i < m; ++i){
        std::string a, b;
        is >> a >> b;
        d.add_edge(a, b);
    }
    return is;
}

// pre: none
// post: performs a depth first search on this digraph
void digraph::dfs() const{
    std::unordered_map<std::string, int> pre, post;
    std::unordered_map<std::string, std::string> parent;

    std::list<std::string> topological;

    int time(1);

    for (auto v : V()){ //V() is a function that returns the neighbors of
                        //a vertex
        if (pre.find(v) == pre.end()){ // not discovered yet
            //initial
            std::stack<std::string> st;
            st.push(v);
            while (!st.empty()){ //loop
                std::string top = st.top();
                if (pre.find(top) == pre.end()){ // not yet visited
                    pre[top] = time++; // record the time the "pre" was fulfilled
                    std::set<std::string> neighbors = adj(top); //now look at its
                                                                //neighbors
                    for (auto n = neighbors.rbegin(); n != neighbors.rend(); ++n){
                    //this is an iterator that visits the neighbors backwards;
                    //will visit 3 before 2, and iterating normally through a set
                    //brings you to 2 before 3
                        if (pre.find(*n) == pre.end()){//if the neighbor has not
                                                       //been visited?
                            st.push(*n); //push the neighbor onto the stacl
                            parent[*n] = top; //record its parent
                        }
                    }
                }
                else{ //visited (aka "pre" has been recorded)
                    if (post.find(top) == post.end()){
                        post[top] = time++;
                        topological.push_front(top);
                    }
                    st.pop();
                }
            }
        }
    }

    //print out all of the pre/post values for the graph
    for (auto e: pre){
        std::cout << e.first << ":" << e.second << " ; ";
    }
    std::cout << std::endl;
    for (auto e: post){
        std::cout << e.first << ":" << e.second << " ; ";
    }
    std::cout << std::endl;

    //printing out parents and figuring out whether the graph is a dag or not
    bool is_dag(true);
    for (auto v: V())
        for (auto w: adj(v)){
            if (pre[v] > post[w])
                std::cout << v << ", " << w << ": cross" << std::endl;
            else if (pre[v] > pre[w] && post[v] < post[w]){
                std::cout << v << ", " << w << ": back" << std::endl;
                is_dag = false;
            }
            else if (parent[w] == v)
                std::cout << v << ", " << w << ": tree" << std::endl;
            else
                std::cout << v << ", " << w << ": forward" << std::endl;
        }
    std::cout << "is_dag = " << is_dag << std::endl;

    //printing out the graph topologically
    if (is_dag){
        for (auto e: topological)
            std::cout << e << " ";
        std::cout << std::endl;
    }
}

#include "graph.h"
#include <cassert>
#include <queue>

graph::graph()
{
    _data = std::vector<std::set<std::size_t>>();
}

std::size_t graph::n() const
{
    return _data.size();
}

std::size_t graph::m() const
{
    std::size_t ans(0);

    for (auto s: _data)
        for (auto v: s)
            ++ans;

    return ans/2;
}

bool graph::is_edge(std::size_t i, std::size_t j) const
{
    assert(i < n() && j < n());
    return (_data[i].find(j) != _data[i].end());
}

std::set<std::size_t> graph::adj(std::size_t v) const
{
    assert(v < n());
    return _data[v];
}

void graph::add_vertex()
{
    _data.push_back(std::set<std::size_t>());
}

void graph::add_edge(std::size_t i, std::size_t j)
{
    assert(i < n() && j < n());
    _data[i].insert(j);
    _data[j].insert(i);
}

void graph::remove_edge(std::size_t i, std::size_t j)
{
    assert(i < n() && j < n());
    _data[i].erase(j);
    _data[j].erase(i);
}

bool graph::is_complete() const
{
    std::size_t  _n = n();
    std::size_t  _m = m();

    return (2*_m == _n*(_n-1));
}

std::ostream & operator << (std::ostream & os, const graph & g)
{
    os << g.n() << " " << g.m() << std::endl;
    for (std::size_t v = 0; v < g.n(); ++v)
    {
        for (auto w: g.adj(v))
            if (w > v)
                os << v << " " << w << std::endl;
    }

    return os;
}

std::istream & operator >> (std::istream & is, graph & g)
{
    std::size_t n, m;
    is >> n >> m;

    g = graph();
    for (std::size_t i = 0; i < n; ++i)
        g.add_vertex();

    for (std::size_t i = 0; i < m; ++i)
    {
        std::size_t a, b;
        is >> a >> b;
        g.add_edge(a, b);
    }

    return is;
}

bool graph::two_colorable() const{
    std::vector<std::size_t> colored(n(), 0);

    for (std::size_t v = 0; v < n(); ++v){
        if (!colored[v]){ // not yet colored, do BFS here

            // BFS init
            std::queue<std::size_t> q;
            q.push(v);
            colored[v] = 1; //one for white, 2 for black, 0 for uncolored

            // BFS loop
            while (!q.empty()){
                std::size_t front = q.front();
                q.pop();

                for (auto n: adj(front)){
                    //assigns color
                    if (colored[front] != colored[n]){
                        if(!colored[n]){ //if the neighbor is not colored
                            if(colored[front] == 1)
                                colored[n] = 2;
                            else
                                colored[n] = 1;
                        q.push(n);
                        }
                    }else{
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

class digraph
{
public:
    // pre: none
    // post: creates an empty digraph
    digraph();

    // pre: none
    // post: returns the number of vertices in this digraph
    std::size_t n() const;

    // pre: none
    // post: returns the number of edges in this digraph
    std::size_t m() const;

    // pre: none
    // post: returns the set of vertices in this digraph
    std::set<std::string> V() const;

    // pre: v is a vertex of this digraph
    // post: returns the set of vertices adjacent to v in this digraph
    std::set<std::string> adj(const std::string & v) const;

    // pre: a, b are vertices of this digraph
    // post: returns true if (a, b) is an edge of this digraph
    bool is_edge(const std::string &a, const std::string &b) const;

    // pre: none
    // post: add vertex v to this digraph; do nothing if v is already
    //       a vertex
    void add_vertex(const std::string &v);

    // pre: a, b are vertices of this digraph
    // post: edge (a, b) has been added to this digraph;
    //       do nothing if (a, b) is already an edge
    void add_edge(const std::string &a, const std::string &b);

    // pre: none
    // post: performs a depth first search on this digraph
    void dfs() const;

private:
    std::unordered_map<std::string, std::set<std::string>> _m;
};

std::ostream & operator << (std::ostream &, const digraph &);
std::istream & operator >> (std::istream &, digraph &);

#endif // GRAPH_H

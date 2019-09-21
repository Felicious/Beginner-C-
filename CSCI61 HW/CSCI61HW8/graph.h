#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>

// assumption: vertices in graphs are labeled 0, 1, ..., n-1
class graph
{
public:
    // pre: none
    // post: an empty graph has been created;
    graph();

    // pre: none
    // post: returns the number of vertices in this graph
    std::size_t n() const;

    // pre: none
    // post: returns the number of edges in this graph
    std::size_t m() const;

    // pre: none
    // post: returns the number of connected components of this graph
    std::size_t ncc() const;

    // pre: none
    // post: returns true if this graph is connected
    bool is_connected() const;

    // pre: i < n() && j < n()
    // post: returns true iff {i, j} is an edge of this graph
    bool is_edge(std::size_t i, std::size_t j) const;

    // pre: none
    // post: returns true iff this graph is complete
    bool is_complete() const;
    // pre: v < n()
    // post: returns the set of vertices adjacent to v
    std::set<std::size_t> adj(std::size_t v) const;

    // pre: none
    // post: a new vertex labeled n() has been added to this graph
    void add_vertex();

    // pre: i < n(), j < n()
    // post: edge {i, j} has been added to this graph
    //       if {i, j} is already an edge, do nothing
    void add_edge(std::size_t i, std::size_t j);

    // pre: i < n(), j < n()
    // post: edge {i, j} has been removed from this graph
    //       if {i, j} is not an edge, do nothing
    void remove_edge(std::size_t i, std::size_t j);

    // pre: none
    // post: returns true iff it is possible to assign the color B or W to each vertex
    //       so that no edge's endpoints have the same color.
    bool two_colorable() const;

private:
    std::vector<std::set<std::size_t>> _data;

    // class invariants:
    // 1. this graph has _data.size() vertices, labeled 0, ...,
    //    _data.size() - 1;
    // 2. _data[i] contains the vertices adjacent to i

};
// pre: none
// post: reads/write graph in the following format
//        n m
//        i1 j1
//        i2 j2
//         ...
//        im jm
//  where i_k < j_k
std::ostream & operator << (std::ostream & os, const graph & g);
std::istream & operator >> (std::istream & is, graph & g);

#endif // GRAPH_H

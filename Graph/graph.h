/*
 * By Jacob Doney
 * File: graph.h
 * This file contains all directives for graph.cpp
 */

#ifndef GRAPH_H
#define GRAPH_H

#define INF 10000
#define INVALID -1

#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using std::pair;

class Graph{

public:
    
    Graph(int);
    ~Graph();

    //bool isEmpty();
    //bool addVertices();
    bool addEdge(int, int, int);
    bool removeEdge(int, int);
    void breadthFirstSearch(int);
    void depthFirstSearch(int);
    void printAdj(int);

private:
    
    //Private Variables
    list<pair<int, int> > *adj;
    int verts;
    int count;
    
    //Private Function
    void dfsRecursion(int, bool*);
};


#endif /* GRAPH_H */

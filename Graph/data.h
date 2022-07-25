/****************
 * By Jacob Doney
 * FIle: data.h
 *************/

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
#include <vector>
#include <set>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::pair;

struct Data {
    int id;
    string information;
};

struct Edge {
    int vertex;
    int dest;
    int weight;
}

struct Node {
    Data data;
    Node* next;
    int val; 
    int cost;
};

#endif /* GRAPH_DATA_H */

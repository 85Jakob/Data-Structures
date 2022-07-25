/*
 * By Jacob Doney
 * File: graph.cpp
 * This file demonstrates a graph
 */

#include "graph.h"

Graph::Graph(int vertices){
    verts = vertices; 
    adj = new list<pair<int, int> >[verts];
}

Graph::~Graph(){
    delete[] adj;
}

/**********************
* removeEdge
**********************/
bool Graph::removeEdge(int vert, int vert2){
    bool removed = false;
    int location = 0;
    int vRemove = 0;
    if((verts > 0) && (vert > INVALID) && (vert2 > INVALID) && (vert != vert2)){
        for(auto i = adj[vert].begin(); i != adj[vert].end() && vRemove != vert2; i++){
            vRemove = (*i).first;
            if(vRemove == vert2){
                list<pair<int, int> >::iterator it;
                it = adj[vert].begin();
                advance(it, location);
                adj[vert].erase(it);
                removed = true;
            }
            location++; 
        }
    }

    return removed;
}

/**********************
* addEdge
**********************/
bool Graph::addEdge(int vert, int connect, int weight){
    bool added = false;
    bool inlist = false;
    int vIndex = 0;
    if(( verts > 0 ) && ( vert != connect ) && ( vert > INVALID ) && ( vert < verts ) && ( connect > INVALID ) && ( connect < verts )){
        //Verify that edge already exists
        for(auto i =  adj[vert].begin(); i != adj[vert].end() && vIndex != connect; i++){
            vIndex = (*i).first; 
            if(vIndex == connect){
                inlist = true;
            }
        }
        //Only add edge if it has a unique start and end point
        if(inlist == false){
            adj[vert].push_back(std::make_pair(connect, weight));
            count++;
            added = true;
        }
    }

    return added;
}

/**********************
* printAdj()
**********************/
void Graph::printAdj(int vert){
    if(verts > 0){
        for(auto i : adj[vert]){
            int vIndex = (i).first;
            int weight = (i).second;
            std::cout << vert << " -> ";
            std::cout << vIndex << " | Weight: " << weight << std::endl;
        }
    }
}

/**********************
* breadthFirstSearch
**********************/
void Graph::breadthFirstSearch(int start){
    if(verts > 0){
        vector<bool> visited(verts);
        for(int i = 0; i < verts; i++){
            visited[i] = false;
        }
        std::list<int> queue;
        visited[start] = true;
        queue.push_back(start);
        std::cout << "Node Visited" << "\tQueue (front to back)";
        while(!queue.empty()){
            start = queue.front();
            queue.pop_front();
            std::cout << std::endl;
            std::cout << start << "\t\t";
            for(auto i : adj[start]){
                int vIndex = (i).first;
                if(!visited[vIndex]){
                    std::cout << vIndex << " ";
                    visited[vIndex] = true;
                    queue.push_back(vIndex);
                }
            }
        }
        std::cout << std::endl;
    }
}

/***********************
* depthFirstSearch
***********************/
void Graph::depthFirstSearch(int start){
    if(verts > 0){
        bool *visited = new bool[verts];
        for(int i = 0; i < verts; i++){
            visited[i] = false;
        }
        std::cout << "Node Visited" << "\tStack (bottom to top)";
        dfsRecursion(start, visited);
        delete visited;
    }
}
/***********************
* PRIVATE 
* depthFirstSearch
***********************/
void Graph::dfsRecursion(int start, bool *visited){
    std::cout << std::endl;
    std::cout << start << "\t\t";
    visited[start] = true;
    for(auto i =  adj[start].begin(); i != adj[start].end(); i++){
        int vIndex = (*i).first;
        if(!visited[vIndex]){
            std::cout << vIndex << " ";
            dfsRecursion(vIndex, visited);
        }
    }
    std::cout << std::endl;
}


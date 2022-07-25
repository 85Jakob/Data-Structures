/*
 * By Jacob Doney
 * File: linkedlist.h
 * linkedlist.h contains all directives for linkedlist.cpp
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream> /* cout, endl */ 
#include <string>

class LinkedList{

public:
    
    LinkedList();
    ~LinkedList();
    
    bool addNode(int, std::string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int); 

private:
    
    Node *head;

    void addHead(Node*);
    void addTail(Node*, Node*);
    void addMid(Node*, Node*);

};    
#endif /* LINKEDLIST_H */

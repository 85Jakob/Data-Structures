/* 
 * By Jacob Doney
 * File hashtable.h
 * hashtable.h contains all directives for hashtable.cpp
 */

#ifndef HASHTABLE_HASHTABEL_H
#define HASHTABLE_HASHTABLE_H

#include <iostream> 
#include <string>
#include "linkedlist.h"
#include "data.h"

#define HASHTABLESIZE 15

class Hashtable{

public:

    Hashtable();
    ~Hashtable();

    bool insertEntry(int, std::string*);
    std::string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:
    
    int hash(int);
    
    int count;
    LinkedList *hashtable[HASHTABLESIZE];

};

#endif /* HASHTABLE_HASHTABLE_H */

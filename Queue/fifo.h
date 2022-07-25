
/*
* By Jacob Doney
* Question 1
* File: fifo.h
* fifo.h contains all directives for fifo.cpp
*/

#ifndef FIFO_H
#define FIFO_H

#define BOTTOM -1
#define NULLSTRING ""

#include "string"
using std::string;

// DATA STRUCT... NOT in a separate file as instruction 
// ask to turn in only 4 files
struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
};

// Fifo Class
class Fifo {

public:
    
    Fifo();
    ~Fifo();
    
    bool push(int, const std::string&);
    bool pull(Data*);
    bool peek(Data*);
    bool isEmpty();

private:

    Node *head;
    Node *tail;
    
    int top;
    void addTail(Node*, Node*);
};

#endif //FIFO_H

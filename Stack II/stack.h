/*
* By Jacob Doney
* Coding04
* File: stack.h
* stack.h contains all directives for stack.cpp
*/

#ifndef STACK_H
#define STACK_H

#define BOTTOM -1
#define MIN 2
#define NULLSTRING ""

#include "data.h"

class Stack {

public:

    Stack();
    Stack(int);
    ~Stack();
    
    bool push(int,const std::string&);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();

private:

    void setStackArray(int);

    int top;
    int size;
    Data **stack;

};

#endif //STACK_H

/******************
* By Jacob Doney
* Coding03
* File: stack.h
*
* stack.h contains all directives for stack.cpp
*****************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define DEFAULTSIZE 10
#define BOTTOM -1
#define MIN 0

class Stack{
private: 
    int top;
    int stackLen;
    int *stackArray;
    
    void setStackArray(int);

public: 
    Stack();
    Stack(int);
    ~Stack();

    bool push(int);
    int pop();
    bool isEmpty();
    int peek();
    
};
#endif //STACK_STACK_H

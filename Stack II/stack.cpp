/*
 * By Jacob Doney
 * Coding04
 * File: Stack.cpp
 * File contains functions to push and peek a Data object onto a stack 
 * as well as the ability to peek and check if the stack is empty. 
 */

#include "stack.h"

Stack::Stack(){
    setStackArray(MIN);
    top = BOTTOM;
}

Stack::Stack(int length){
    setStackArray(length);
    top = BOTTOM;
}

// Deconstructor
Stack::~Stack(){
    for(int i = 0; i < top + 1; i++){
        delete stack[i];
    }
    delete[] stack;
}

void Stack::setStackArray(int length){
    if(size < MIN){
        size = MIN;
    } else {
        size = length;
    }
    stack = new Data*[size];
}

bool Stack::push(int idIn, const std::string& info){
    bool added = false;
    if(top < size -1 && idIn > 0 && info != ""){
        stack[++top] = new Data;
        stack[top]->id = idIn;
        stack[top]->information = info;
        added = true;
    }
    return added;
}

bool Stack::pop(Data* poppedData){
    bool popped = false;
    if(top > BOTTOM){
        poppedData->id = stack[top]->id;
        poppedData->information = stack[top]->information;
        delete stack[top--];
        popped = true;
    } else {
       poppedData->id = BOTTOM;
       poppedData->information = NULLSTRING;
    }
    return popped;

}


bool Stack::peek(Data* poppedData){
    bool peeked = false;
    if(top > BOTTOM){
        poppedData->id = stack[top]->id;
        poppedData->information = stack[top]->information;
        peeked = true;
    } else {
        poppedData->id = BOTTOM;
        poppedData->information = NULLSTRING;
    }
    return peeked;
}

bool Stack::isEmpty(){
    return(top == BOTTOM);
}

/**********************
* By Jacob Doney
* Coding03
* File: stack.cpp
* Functions to demonstrate stack implementation useing an array.
**********************/

#include "stack.h"

// Constructors 
Stack::Stack(){
    setStackArray(DEFAULTSIZE);
    top = BOTTOM;
}
Stack::Stack(int size){
    setStackArray(size);
    top = BOTTOM;
}

// Destructor
Stack::~Stack(){
    delete[] stackArray;
}

/*******************
* SETTER FUNCTIONS
*******************/
void Stack::setStackArray(int size){
    if(size < MIN){
        stackLen = DEFAULTSIZE;
    } else {
        stackLen = size;
    }
    stackArray = new int[stackLen];
}

/******************
* CLASS FUNCTIONS
******************/

bool Stack::push(int element){
    bool added = false;
    if(top < stackLen - 1){
        stackArray[++top] = element;
        added = true;
    }
    return added;
}

int Stack::pop(){
    if(isEmpty()){
        throw 1;
    }
    return stackArray[top--];

}

bool Stack::isEmpty(){
    return(top == BOTTOM);
}

int Stack::peek(){
    if(isEmpty()){
        throw 1;
    }
    return stackArray[top];
}

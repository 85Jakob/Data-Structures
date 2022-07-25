/*
 * By Jacob Doney
 * Question 1
 * File: fifo.cpp
 * File contains functions to push and peek a Data object onto a stack 
 * as well as the ability to pull and check if the stack is empty. 
 */

#include "fifo.h"

Fifo::Fifo(){
    head = tail = NULL;
    top = BOTTOM;
}

Fifo::~Fifo(){
    Node * temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

bool Fifo::isEmpty(){
    return(top == BOTTOM);
}

bool Fifo::push(int newId, const std::string& info){
    bool added = false;
    if (newId > 0 && info != ""){
        Node *current = new Node;
        current->data.id = newId;
        current->data.data = info;
        current->next = NULL;
        top++;
        if(head == NULL){
            head = current;
        }
        else{
            tail->next = current;
        }
        tail = current;
        added = true;
    }
    return added;
}

bool Fifo::peek(Data* tempData){
    bool peeked = false;
    if(top > BOTTOM){
        tempData->id = tail->data.id;
        tempData->data = tail->data.data;
        peeked = true;
    } else {
        tempData->id = BOTTOM;
        tempData->data = NULLSTRING;
    }
    return peeked;
}

bool Fifo::pull(Data* pulledData){
    bool pulled = false;
    if(head != NULL){
       pulledData->data = head->data.data;
       pulledData->id = head->data.id;
       Node *current = head;
       if(head->next != 0){
           head = head->next;
       }
       delete current;
       top--;
       if(top == BOTTOM){
           head = tail = NULL;
       }
       pulled = true;
    } else {
       pulledData->id = BOTTOM;
       pulledData->data = NULLSTRING;
    }
    return pulled;
}

         



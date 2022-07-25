/* 
 * By Jacob Doney
 * File: hashtable.cpp
 * Contains all functions to demonstrate a hashtable using pointers and linked lists.
 * Functions included are insertEntry, getData, removeEntry, getCount, printTable.
 */

#include "hashtable.h"

/****************
* Constructor / Destructor
****************/
Hashtable::Hashtable(){
    count = 0;   
    for(int i = 0; i < HASHTABLESIZE; i++){
        hashtable[i] = nullptr;
    }
}

Hashtable::~Hashtable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
        if(hashtable[i]){
            delete hashtable[i];
        }
    }
}

/***************
* PRIVATE METHODS
***************/
int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}

/***************
* PUBLIC METHODS
***************/

/***************
* insertEntry()
* Parameters: int, string
* Returns: bool
* Creates a node or linked list and associates it to a location in the hashtable.
***************/
bool Hashtable::insertEntry(int newId, std::string* info){
    bool insert = false;
    if( newId > 0 && info->length() != 0){
        int position = hash(newId);
        if(!hashtable[position]){
            LinkedList *entry = new LinkedList;
            hashtable[position] = entry;
            insert = hashtable[position]->addNode(newId, info);
        }
        else{
            insert = hashtable[position]->addNode(newId, info);
        }
        if(insert){
            count++;
        }
    }
    
    return insert;
}

/***************
* getData()
* Parameters: int
* Returns: string
* Finds the entry with a matching id and returns the string associated with it,
***************/
std::string Hashtable::getData(int id){
    std::string tmpString = "";
    int position = hash(id);
    if( id > 0 && hashtable[position]){
        Data tmpData;
        hashtable[position]->getNode(id, &tmpData);
        tmpString = tmpData.data;
    }
    
    return tmpString;
}

/***************
* removeEntry()
* Parameters: int
* Returns: bool
* Removes the entry with a matching id to the number passed in.
***************/
bool Hashtable::removeEntry(int id){
    bool del = false;
    int position = hash(id);
    if( id > 0 && hashtable[position]){
        del = hashtable[position]->deleteNode(id);
        if(hashtable[position]->getCount() == 0){
            delete hashtable[position];
            hashtable[position] = nullptr;
        }
        if(del){
            count--;
        }
    }

    return del;
}

/***************
* getCount()
* Parameters: none
* Returns: int
* returns the number of entries in the hash table.
***************/
int Hashtable::getCount(){
    return count;
}

/***************
* printTable()
* Parameters: none
* Returns: none
* Prints the location of all entries.
***************/
void Hashtable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        if(hashtable[i]){
            std::cout<< "Entry " << i + 1 << ": ";
            hashtable[i]->printList(false);
        }
        else{
            std::cout << "Entry " << i + 1 << ": Empty";
        }
        std::cout << std::endl;
    }
}


/*
 * By Jacob Doney
 * File: linkedlist.cpp
 * This file is used to demonstrate a linked list and 
 * contains functions addNode, deleteNode, printList
 * getCount, clearList, and exists.
 */


#include "linkedlist.h"

/*************
* CONSTRUCTOR & DECONSTRUCTOR
*************/
LinkedList::LinkedList(){
    head = NULL;
}
LinkedList::~LinkedList(){
    clearList();
}

/**************
* PRIVATE METHODS
**************/
void LinkedList::addHead(Node *newNode){
   head->prev = newNode;
   newNode->next = head;
   newNode->prev = NULL;
   head = newNode;
}
void LinkedList::addTail(Node *position, Node *newNode){
    newNode->next = NULL;
    newNode->prev = position;
    position->next = newNode;
}
void LinkedList::addMid(Node *position, Node *newNode){
    newNode->next = position;
    newNode->prev = position->prev;
    position->prev->next = newNode;
    position->prev = newNode;
}

/**************
* PUBLIC METHODS
**************/

/**************
* addNode()
* parameters: int, string
* Returns: bool
* Creates a Node for a Data struct and adds it to the linked list.
* Returns true to indicate success.
**************/
bool LinkedList::addNode(int newId, std::string* info){
    bool added = false;
    // checks to see if valid data was passed to method
    if( newId > 0 && info->length() != 0){   
      Node *current;
      current = head;
      // if current is not null this finds where to add new node
      while(current && current->next != 0 && current->data.id < newId){
          current = current->next;
      }
      // creates a node and attaches it to linked list if head is NULL and newId is not in the list
      if(head == NULL || current->data.id != newId){
          Node *newNode;
          newNode = new Node;
          newNode->data.id = newId;
          newNode->data.data = *info;
          // add new tail if newId is greater than last id of the list     
          if(current && newId > current->data.id && current->next == 0){ 
              addTail(current, newNode);
          } 
          // add new head if newId is less than current head's id
          else if(current && current->prev == 0 && newId < current->data.id){
              addHead(newNode);
          }
          // add node to a middle slot
          else if(current){
              addMid(current, newNode);
          }
          // if current aka head is null assign newNode to head
          else{
              head = newNode;
              newNode->prev = NULL;
              newNode->next = NULL;
          }
 
          added = true;

      }//end if inner
    }// end if outer
      
    return added;
}

/**************
* deleteNode()
* Parameters: int
* Returns: bool
* Checks to see if int id that was passed in matches id in linked list.
* If a match is found deletes node and returns true.
**************/
bool LinkedList::deleteNode(int id){
    bool deleted = false;
    // seeks node to delete
    Node *current;
    current = head;
    while(current && current->next != 0 && current->data.id != id){
        current = current->next;
    }
    // deletes node if found
    if(current && current->data.id == id){
        // detaching head only if there is something to detach
        if(current ==  head){
            if(current->next != 0){
                head = current->next;
                current->next->prev = NULL;
            } else {
                head = NULL;
            }
        }
        // detaching tail
        else if(current->next == 0 && current->prev != 0){
            current->prev->next = NULL;
        }
        // detaching mid
        else if(current->next != 0 && current->prev != 0){
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        deleted = true;
    }

    return deleted;
}

/**************
* getNode()
* Parameters: int, Data*
* Returns: bool
* Takes an empty Data struct and an int id. 
* If id matches an id in the linklist, it fills Data object and returns true. 
**************/
bool LinkedList::getNode(int id, Data* tempData){
    bool found = false;
    Node *current;
    current = head;
    // seeking id
    while(current && current->next != 0 && current->data.id != id){
        current = current->next;
    }
    // if found assign data to pointer
    if(current && current->data.id == id){
        tempData->id = current->data.id;
        tempData->data = current->data.data;
        found = true;
    }
    else{
        tempData->id = -1;
        tempData->data = "";
    }

    return found;
}

/**************
* printList()
* parameters: bool
* returns: None
* Prints linked list. If bool in parameter is true prints list backwards.
**************/
void LinkedList::printList(bool backward){
    Node *current = head;
    if(backward == true){
        bool tail = false;
        while(current && !tail){
            if(current->next){
                current = current->next;
            } else {
                tail = true;
            }
        }
        while(current){
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->prev;
        }
    } else {
        while(current){
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }
    }
}

/**************
* getCount()
* Parameters: None
* Returns: int
* Counts the number of Nodes in the linkedlist and returns count. 
**************/
int LinkedList::getCount(){
    int count = 0;
    Node *current = head;
    while(current){
        current = current->next;
        count++;
    }
    return count;
}

/**************
* clearList()
* Parameters: None
* Returns: bool
* Deletes all allocated memory and sets head = NULL.
* Returns true when list is cleared. 
**************/
bool LinkedList::clearList(){
    bool cleared = false;
    Node *current = head;
    while(head != NULL){
        current = head;
        head = head->next;
        delete current;
        cleared = true;
    }
    return cleared;
    }

/**************
* exists()
* Parameters: int
* Return: bool
* Checks to see if an id is in the linked list.
* returns true if id is present.
**************/
bool LinkedList::exists(int id){
    bool exists;
    Node *current = head;
    while(current->next !=0 && current->data.id != id){
        current = current->next;
    }
    if(current && current->data.id == id){
        exists = true;
    }
    return exists;
} 

 

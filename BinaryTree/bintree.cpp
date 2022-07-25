/*
 * By Jacob Doney
 * Coding07
 * File: bintree.cpp
 * This file demonstrates a binary tree and contains functions clear, addNode, removeNode
 * getNode, contains, getHeight, displayPreOrder, displayPostOrder, displayInOrder, isEmpty, displayTree
 * getCount, and getRootData
 */

#include "bintree.h"

/**************
* CONSTRUCTOR & DECONSTRUCTOR
**************/
BinTree::BinTree(){
    root = NULL;
}

BinTree::~BinTree(){
    clear();
}

/***************************
* PUBLIC FUNCTIONS
***************************/

/***************
* isEmpty();
* Parameters: none
* Returns: bool
* returns true if binary tree is empty.
***************/
bool BinTree::isEmpty(){
    return (!root);
}

/***************
* getCount()
* Parameters: none
* Returns: int
* returns the number of entries in the binary tree.
***************/
int BinTree::getCount(){
    return count;
}

/***************
* getRootData()
* Parameters: Data*
* Returns: Bool
* Fills an empty Data struct with root's data. Returns true if data was retrieved.
***************/
bool BinTree::getRootData(Data* tempData){
    bool ret = false;
    if (root){
        tempData->id = root->data.id;
        tempData->information = root->data.information;
        ret = true;
    } else {
        tempData->id = -1;
        tempData->information = "";
    }

    return ret;
}

/**************
* addNode()
* Parameters: int, const string*
* Returns: bool
* Creates a DataNode and adds it to the Binary Tree. Returns true if added.
**************/
bool BinTree::addNode(int tempId, const std::string* info){
    bool added = false;
    if( tempId > 0 && *info != ""){
        DataNode *entry = new DataNode;
        entry->left = NULL;
        entry->right = NULL;
        entry->data.information = *info;
        entry->data.id = tempId;
        added = addNode(entry, &root);
        if(added){
            count++;
        }
    }

    return added;
}
        
/**************
* contains()
* Parameters: int
* Returns: bool
* Takes in an id and returns true if the binary tree contains the id.
**************/
bool BinTree::contains(int tempId){
    bool inTree = false;
    if(tempId > 0){
        inTree = contains(tempId, root);
    }

    return inTree;
}

/**************
* getNode()
* Parameters: Data* int
* Returns: bool
* Takes in an id and an empty Data struct. Returns true if it is in tree and fills struct. 
**************/
bool BinTree::getNode(Data* tempData, int tempId){
    bool inTree = false;
    if(tempId > 0){
        inTree = getNode(tempData, tempId, root);
    }
    if(!inTree){
        tempData->id = -1;
        tempData->information = "";
    }

    return inTree;
}

/**************
* clear()
* Parameters: None
* Returns: None
* Empties tree.
**************/
void BinTree::clear(){
    if(root){
        clear(root);
    }
}

/**************
* displayPreOrder()
* Parameters: None
* Returns: None
* Displays tree in pre-order
**************/
void BinTree::displayPreOrder(){
    if(root){
        displayPreOrder(root);
    }
}

/**************
* displayPostOrder()
* Parameters: None
* Returns: None
* Displays tree in post-order
**************/
void BinTree::displayPostOrder(){
    if(root){
        displayPostOrder(root);
    }
}

/**************
* displayInOrder()
* Parameters: None
* Returns: None
* Displays tree in order
**************/
void BinTree::displayInOrder(){
    if(root){
        displayInOrder(root);
    }
}

/**************
* getHeight()
* Parameters: None
* Returns: Int
* Returns the height of the tree
**************/
int BinTree::getHeight(){
    int height = 0;
    if(root){
        height = getHeight(root);
    }

    return height;
}

/**************
* removeNode()
* Parameters: Int
* Returns: bool
* Takes an Id and removes it's corespoding node
**************/
bool BinTree::removeNode(int tempId){
    bool removed = false;
    int tempCount = count;
    if(root && tempId > 0){
        root = removeNode(tempId, root);
        if(count < tempCount){
            removed = true;
        }
    }

    return removed;
}


/**************
* displayTree()
* Parameters: None
* Returns: None
* Prints out tree information
**************/
void BinTree::displayTree(){
    std::cout << "DISPLAY TREE" << std::endl;
    std::cout << "==============================================" << std::endl;
    if(isEmpty()){
        std::cout << "Tree is empty" << std::endl;
    } else {
        std::cout << "Tree is NOT empty" << std::endl;
    }
    std::cout << "Height " << getHeight() << std::endl;
    std::cout << "Node Count " << getCount() << std::endl;
    std::cout << std::endl;
    std::cout << "Pre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << std::endl;
    std::cout << "In-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << std::endl;
    std::cout << "Post-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << "==============================================" << std::endl;
}

/***************************
* PRIVATE FUNCTIONS
***************************/

/**************
* addNode()
* Parameters: DataNode*, DataNode**
* Returns: bool
* Creates a DataNode and adds it to the Binary Tree. Returns true if added.
**************/
bool BinTree::addNode(DataNode* newNode, DataNode** tempRoot){
    bool added = false;
    if (!(*tempRoot)){
        *tempRoot = newNode;
        added = true;
    }
    else if(newNode->data.id < (*tempRoot)->data.id){
            added = addNode(newNode, &(*tempRoot)->left);
    }
    else if(newNode->data.id > (*tempRoot)->data.id){
            added = addNode(newNode, &(*tempRoot)->right);
    }

    return added;
}

/**************
* contains()
* Parameters: int, DataNode*
* Returns: bool
* Takes in an id and pointer to root. Returns true if the binary tree contains the id.
**************/
bool BinTree::contains(int tempId, DataNode* tempRoot){
    bool inTree = false;
    if(tempRoot){
        if(tempId == tempRoot->data.id){
            inTree = true;
        }
        if(tempId < tempRoot->data.id){
            inTree = contains(tempId, tempRoot->left);
        }
        if(tempId > tempRoot->data.id){
            inTree = contains(tempId, tempRoot->right);
        }
    }

    return inTree;
}

/**************
* getNode()
* Parameters: Data* int DataNode*
* Returns: bool
* Takes in an id and an empty Data struct. Returns true if it is in tree and fills struct. 
**************/
bool BinTree::getNode(Data* tempData, int tempId, DataNode* tempRoot){
    bool inTree = false;
    if(tempRoot){
        if(tempId == tempRoot->data.id){
            tempData->id = tempRoot->data.id;
            tempData->information = tempRoot->data.information;
            inTree = true;
        }
        if(tempId < tempRoot->data.id){
            inTree = getNode(tempData, tempId, tempRoot->left);
        }
        if(tempId > tempRoot->data.id){
            inTree = getNode(tempData, tempId, tempRoot->right);
        }
    }
    return inTree;
}

/**************
* clear()
* Parameters: DataNode*
* Returns: None
* Empties tree.
**************/
void BinTree::clear(DataNode* tempRoot){
    if(tempRoot){
        clear(tempRoot->left);
        clear(tempRoot->right);
        tempRoot->left = NULL;
        tempRoot->right = NULL;
        delete tempRoot;
        count--;
    }
    root = NULL;
}

/**************
* displayPreOrder()
* Parameters: DataNode*
* Returns: None
* Displays tree in pre-order
**************/
void BinTree::displayPreOrder(DataNode* tempRoot){
    if(tempRoot){
        std::cout << tempRoot->data.id << " " << tempRoot->data.information << std::endl;
        if(tempRoot->left){
            displayPreOrder(tempRoot->left);
        }
        if(tempRoot->right){    
            displayPreOrder(tempRoot->right);
        }
    }
}

/**************
* displayPostOrder()
* Parameters: DataNode*
* Returns: None
* Displays tree in pre-order
**************/
void BinTree::displayPostOrder(DataNode* tempRoot){
    if(tempRoot){
        if(tempRoot->left){
            displayPostOrder(tempRoot->left);
        }
        if(tempRoot->right){    
            displayPostOrder(tempRoot->right);
        }
        std::cout << tempRoot->data.id << " " << tempRoot->data.information << std::endl;
    }
}

/**************
* displayInOrder()
* Parameters: DataNode* tempRoot
* Returns: None
* Displays tree in order
**************/
void BinTree::displayInOrder(DataNode* tempRoot){
    if(tempRoot){
        if(tempRoot->left){
            displayInOrder(tempRoot->left);
        }
        std::cout << tempRoot->data.id << " " << tempRoot->data.information << std::endl;
        if(tempRoot->right){    
            displayInOrder(tempRoot->right); 
        }
    }
}

/**************
* getHeight()
* Parameters: DataNode*
* Returns: Int
* Returns the height of the tree
**************/
int BinTree::getHeight(DataNode* tempRoot){
    int height = 0;
    int leftHeight = 0;
    int rightHeight = 0;
    if(tempRoot){
        if(tempRoot->left){
            leftHeight = getHeight(tempRoot->left);
        }
        if(tempRoot->right){
            rightHeight = getHeight(tempRoot->right);
        }
        height = (std::max(leftHeight, rightHeight) + 1);
    }

    return height;
}

/**************
* removeNode()
* Parameters: int, DataNode*
* Returns: DataNode*
* Takes an Id and removes it's corespoding node. Returns root pointer.
* MUST BE USED WITH minValueNode()
**************/
DataNode* BinTree::removeNode(int tempId, DataNode* tempRoot){
    if(tempRoot){
        if(tempRoot->left && tempId < tempRoot->data.id){
            tempRoot->left = removeNode(tempId, tempRoot->left);
        }
        else if(tempRoot->right && tempId > tempRoot->data.id){
            tempRoot->right = removeNode(tempId, tempRoot->right);
        }
        else if(tempId == tempRoot->data.id){
            DataNode* temp = new DataNode;
            if(!tempRoot->left){    
                temp = tempRoot->right;
                delete tempRoot;
                tempRoot = temp;
                count--;
            }
            else if(!tempRoot->right){
                temp = tempRoot->left;
                delete tempRoot;
                tempRoot = temp;
                count--;
            }
            else{
               temp = minValueNode(tempRoot->right);
               tempRoot->data.id = temp->data.id;
               tempRoot->data.information = temp->data.information;
               tempRoot->right = removeNode(temp->data.id, tempRoot->right);
            }
        }
    }

    return tempRoot;
}

/***************
* minValueNode()
* Parameters: DataNode*
* Returns: DataNode*
* Used with removeNode() to find the a replacement node for a node with two childs.
***************/
DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;
    while(current && current->left){
        current = current->left;
    }

    return current;
}

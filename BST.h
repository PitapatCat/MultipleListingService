/*
Nguyen Nhat Cong Le

lab number: final project
authors: Kevin Jin, Lance Carrido, Jaymen Luther, Nguyen Nhat Cong Le
description: The project is a house listing service providing the address, price, beds, baths, type, and area of houses in San Jose, with options to filter by address and price.
*/

#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "Queue.h"
#include <iostream>
#include <cctype>

template<typename T>
class BST {
private:
    BSTNode<T>* root;
    int size;
    int insertCnt;
    void deleteAllNodesHelper(BSTNode<T>*);
public:
    //constructor
    BST();
    ~BST() {
        deleteAllNodes();
    }
    
    /*
    Deletes all nodes in the BST.
    Pre: None
    Post: all nodes and data within nodes deleted
    Return: None
    */
    void deleteAllNodes();
    
    /*
    Add object to the tree
    Pre: pointer to T object
    Post: pointer to object T added to BST based off its value
    return: none
    */
    void insert(T*);
    
    /*
    Returns the insertCnt value.
    Pre: None
    Post: None
    Return: insertCnt - int value representing number of comparisons when inserting
    */
    int getInsertCnt() {
        return insertCnt;
    }
    
    /*
    Search for object in the tree
    Pre: pointer to T object
    Post: None
    Return: true if found, otherwise, return false
    */
    bool search(T*);
    
    /*
    Remove pointer from the BST
    Pre: pointer to T object
    Post: T object with contents pointed to by pointer removed from BST
    return: none
    */
    void remove(T*);
    
    /*
    Pass to ostream breath-first, pre-order, in-order, post-oder traversal
    Pre: ostream& out - object the traversals outputs are passed into
    Post: None
    return: none
    */
    void print(std::ostream&);
    
    /*
    Getter for size.
    Pre: None
    Post: None
    return: size - int representing nodes in the tree
    */
    int count() {
        return size;
    }

    /*
    Pass to ostream breath-first traversal.
    Pre: ostream& out - ostream object reference the breadth-first print is passed to
         BSTNode<T>* node - the node to start traversal
    Post: None
    return: None
    */
    void breadthFirst(std::ostream&, BSTNode<T>* node);
    
    /*
    Pass to ostream in-order traversal.
    Pre: ostream& out - ostream object reference the breadth-first print is passed to
         BSTNode<T>* node - the node to start traversal
    Post: None
    return: None
    */
    void printBySortedKey(std::ostream& out) {
        inOrder(out, root);
    }
    
    /*
    Pass to ostream in-order traversal.
    Pre: ostream& out - ostream object reference the breadth-first print is passed to
         BSTNode<T>* node - the node to start traversal
    Post: None
    return: None
    */
    void inOrder(std::ostream&, BSTNode<T>* node);
    
    /*
    Pass to ostream indented pre-order traversal.
    Pre: ostream& out - ostream object reference the breadth-first print is passed to
         BSTNode<T>* node - the node to start traversal
    Post: None
    return: None
    */
    void printIndentedTree(std::ostream& out) {
        preOrder(out, root, "\t");
    }
    
    /*
    Pass to ostream indented pre-order traversal.
    Pre: ostream& out - ostream object reference the breadth-first print is passed to
         BSTNode<T>* node - the node to start traversal
    Post: None
    return: None
    */
    void preOrder(std::ostream&, BSTNode<T>* node, std::string indent);
    
    /*
    Pass to ostream post-order traversal.
    Pre: ostream& out - ostream object reference the breadth-first print is passed to
         BSTNode<T>* node - the node to start traversal
    Post: None
    return: None
    */
    void postOrder(std::ostream&, BSTNode<T>* node);
    
    /*
    Traversal through objects between min and max printed to console.
    Pre: BSTNode<T>* node - the node to start traversal
         T min - object with minimum value
         T max - object with maximum value
    Post: objects between min and max printed
    return: None
    */
    void printInRange(BSTNode<T>* node, T min, T max);
    
    /*
    Wrapper function for 3 parameter printInRange.
    Pre: T min - object with minimum value
         T max - object with maximum value
    Post: objects between min and max printed
    return: None
    */
    void printInRange(T min, T max);
};
template<typename T>
BST<T>::BST() {
    root = nullptr;
    size = 0;
    insertCnt = 0;
}

template<typename T>
void BST<T>::printInRange(BSTNode<T>* node, T min, T max)
{
    if (node == nullptr)
        return;
    if (*node->getData() > min)
        printInRange(node->getLeftChild(), min, max);

    if (*node->getData() >= min && *node->getData() <= max)
        std::cout << *node->getData() << std::endl;

    if (*node->getData() < max)
        printInRange(node->getRightChild(), min, max);
}

template<typename T>
void BST<T>::printInRange(T min, T max)
{
    printInRange(root, min, max);
}

template<typename T>
void BST<T>::insert(T* data) {
    if (root != nullptr)
    {
        BSTNode<T>* curParent = nullptr;
        BSTNode<T>* current = root;
        
        while (current != nullptr)
        {
            if (*(current->getData()) <= *data)
            {
                curParent = current;
                current = current->getRightChild();
            }
            else // if (*(current->getData()) > *data)
            {
                curParent = current;
                current = current->getLeftChild();
            }
            insertCnt++;
        }
        
        BSTNode<T>* newNode = new BSTNode<T>();
        newNode->setData(data);
        
        if (*(curParent->getData()) < *data) {
            curParent->setRightChild(newNode);
        } else {
            curParent->setLeftChild(newNode);
        }
        insertCnt++;
        size++;
    }
    else {
        root = new BSTNode<T>();
        root->setData(data);
        size++;
    }
}

template<typename T>
void BST<T>::remove(T* data)
{
    if (root != nullptr)
    {
        BSTNode<T>* curParent = nullptr;
        BSTNode<T>* current = root;
        while (current != nullptr)
        {
            if (*(current->getData()) < *data)
            {
                curParent = current;
                current = current->getRightChild();
            }
            else if (*(current->getData()) > *data)
            {
                curParent = current;
                current = current->getLeftChild();
            }
            // the == operator in house is overloaded to compare address rather than price
            else if (*(current->getData()) == *data)
                break;
            else
                return;
        }
        if (current == nullptr)
            return;
        if (current->getLeftChild() == nullptr)
        {
            if (curParent != nullptr)
            {
                // TODO: if the address is the same, then delete; otherwise, return
                if (*curParent->getData() < *current->getData())
                    curParent->setRightChild(current->getRightChild());
                else
                    curParent->setLeftChild(current->getRightChild());
                delete current;
                size--;
            }
            else
            {
                BSTNode<T>* oldRoot = root;
                root = root->getRightChild();
                delete oldRoot;
                size--;
            }
        }
        else
        {
            BSTNode<T>* max = current->getLeftChild();
            BSTNode<T>* maxParent = current;
            while (max->getRightChild())
            {
                maxParent = max;
                max = max->getRightChild();
            }
            current->setData(max->getData());
            if (*max->getData() > *maxParent->getData())
                maxParent->setRightChild(max->getLeftChild());
            else
                maxParent->setLeftChild(max->getLeftChild());
            delete max;
            size--;
        }
    }
}

template<typename T>
void BST<T>::deleteAllNodesHelper(BSTNode<T>* node) {
    if (node != nullptr) {
        deleteAllNodesHelper(node->getLeftChild());
        deleteAllNodesHelper(node->getRightChild());
        delete node;
    }
}

template<typename T>
void BST<T>::deleteAllNodes() {
    deleteAllNodesHelper(root);
}

template<typename T>
bool BST<T>::search(T* data) {
    if (root != nullptr)
    {
        BSTNode<T>* current = root;
        while (current != nullptr)
        {
            if (*current->getData() < *data)
                current = current->getRightChild();
            else if (*current->getData() > *data)
                current = current->getLeftChild();
            else
                return true;
        }
    }
    return false;
}

template<typename T>
void BST<T>::inOrder(std::ostream& output, BSTNode<T>* node) {
    if (node != nullptr)
    {
        inOrder(output, node->getLeftChild());
        output << *node->getData() << std::endl;
        inOrder(output, node->getRightChild());
    }
}

template<typename T>
void BST<T>::preOrder(std::ostream& output, BSTNode<T>* node, std::string indent){
    if (node != nullptr)
    {
        output << *node->getData() << std::endl;
        std::string indentLeft = indent;
        if (node->getLeftChild() != nullptr)
        {
            indentLeft += '\t';
            output << indent;
        }
        preOrder(output, node->getLeftChild(), indentLeft);
        std::string indentRight = indent;
        if (node->getRightChild() != nullptr)
        {
            indentRight += '\t';
            output << indent;
        }
        preOrder(output, node->getRightChild(), indentRight);
    }
}

template<typename T>
void BST<T>::postOrder(std::ostream& output, BSTNode<T>* node) {
    if (node != nullptr)
    {
        postOrder(output, node->getLeftChild());
        postOrder(output, node->getRightChild());
        output << *node->getData() << std::endl;
    }
}

template<typename T>
void BST<T>::breadthFirst(std::ostream& output, BSTNode<T>* node){
    Queue<BSTNode<T>*> queue;
    while (node != nullptr)
    {
        output << *node->getData() << std::endl;
        if (node->getLeftChild())
            queue.enqueue(node->getLeftChild());
        if (node->getRightChild())
            queue.enqueue(node->getRightChild());
        if (queue.peekFront() != nullptr)
        {
            node = queue.peekFront();
            queue.dequeue();
        }
        else
            node = nullptr;
    }
}

template<typename T>
void BST<T>::print(std::ostream& output) {
    output <<"Breadth-first traversal: "<< std::endl;
    breadthFirst(output, root);
    output << std::endl;
    output << "Pre-order traversal: " << std::endl;
    preOrder(output, root,"\t");
    output << std::endl;
    output << "In-order traversal: " << std::endl;
    inOrder(output, root);
    output << std::endl;
    output << "Post-order traversal: " << std::endl;
    postOrder(output, root);
    output << std::endl;
}

#endif // !BST_H


/*
Kevin Jin

lab number: final project
authors: Kevin Jin, Lance Carrido, Jaymen Luther, Nguyen Nhat Cong Le
description: The project is a house listing service providing the address, price, beds, baths, type, and area of houses in San Jose, with options to filter by address and price.
*/

#ifndef QUEUE_H
#define Queue_h

#include "SinglyLinkedList.h"

template<class T>
class Queue : SinglyLinkedList<T> {
public:
    Queue() : SinglyLinkedList<T>() {}
    ~Queue();
    
    /*
    Add node containing data of type T to queue.
    Pre: data - data of type T to add
    Post: node containing specified data added to queue
    Return: None
    */
    void enqueue(const T data);
    
    /*
    Remove node from queue.
    Pre: None
    Post: node removed from queue
    Return: None
    */
    void dequeue();
    
    /*
    Retrieves data from start of queue
    Pre: None
    Post: None
    Return: data of type T returned
    */
    T peekFront() const;
    
    /*
    Retrieves data from back of queue
    Pre: None
    Post: None
    Return: data of type T returned
    */
    T peekRear() const;
    
    /*
    Remove all nodes from queue; clear queue.
    Pre: None
    Post: all nodes removed from queue
    Return: None
    */
    void clear();
    
    /*
    Prints data of all nodes within the queue.
    Pre: None
    Post: data of all nodes within queue printed
    Return: None
    */
    void printQueue();
};

template<class T>
Queue<T>::~Queue() {
    clear();
}

template<class T>
void Queue<T>::enqueue(const T data) {
    this->append(data);
}

template<class T>
void Queue<T>::dequeue() {
    this->removeStart();
}

template<class T>
T Queue<T>::peekFront() const {
    return this->getStart();
}

template<class T>
T Queue<T>::peekRear() const {
    return this->getEnd();
}

template<class T>
void Queue<T>::clear() {
    while (!this->isEmpty())
        this->removeStart();
}

template<class T>
void Queue<T>::printQueue() {
    this->printList();
}

#endif /* Queue_hpp */

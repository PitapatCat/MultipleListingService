/*
Nguyen Nhat Cong Le

lab number: final project
authors: Kevin Jin, Lance Carrido, Jaymen Luther, Nguyen Nhat Cong Le
description: The project is a house listing service providing the address, price, beds, baths, type, and area of houses in San Jose, with options to filter by address and price.
*/

#ifndef LINKNODE_H
#define LINKNODE_H

template<class T>
class LinkNode {
public:
    T data;
    LinkNode<T>* next;
    LinkNode();
};

template<class T>
LinkNode<T>::LinkNode() {
    next = nullptr;
}

#endif


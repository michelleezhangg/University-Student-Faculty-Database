/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* The template class for the GenStack class.
* A stack implemented using a Doubly Linked List.
* This file includes the header and the implementation for the GenStack class.
* Used for the RollBack class.
*/

#ifndef GENSTACK_H
#define GENSTACK_H

#include "LinkedList.h"

/* header */
template <class T>
class GenStack {
    public:
        GenStack(); // default constructor
        ~GenStack(); // destructor

        // core functions
        void push(T data);
        T pop();
        T peek();

        // auxiliary functions
        bool isEmpty();
        unsigned int getSize();

    private:
        DoublyLinkedList<T> *dl;
        unsigned int size;
};

/* implementation */
template <class T>
GenStack<T>::GenStack(){ // default constructor
    dl = new DoublyLinkedList<T>();
    size = 0;
}

template <class T>
GenStack<T>::~GenStack(){ // destructor
    delete dl;
}

/**
 * adds the element of data data onto the top of the stack.
 * @param data the element of data we want to push onto the stack.
 */
template <class T>
void GenStack<T>::push(T data){
    dl->insertBack(data);
    ++size;
}

/**
 * removes the top element of the stack and returns its value.
 * @return data the element of data we want to push onto the stack.
 */
template <class T>
T GenStack<T>::pop(){
    --size;
    T data = dl->removeBack();
    return data;
}

/** @return the top element's value in the stack. */
template <class T>
T GenStack<T>::peek(){
    return dl->getBackData();
}

/** @return true if the stack is empty and false otherwise. */
template <class T>
bool GenStack<T>::isEmpty(){
    return (size == 0);
}

/** @return size the size of the stack */
template <class T>
unsigned int GenStack<T>::getSize(){
    return size;
}

#endif
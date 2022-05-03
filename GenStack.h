/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* The template class for the GenStack class.
* A stack implemented using a Doubly Linked List.
* This file includes the header and the implementation for the GenStack class.
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

/*
* Adds the element of type T and data value data onto the top/rear of the stack.
* @param T data A type T representing the data we want to push into the stack.
*/
template <class T>
void GenStack<T>::push(T data){
    dl->insertBack(data);
    ++size;
}

/*
* Removes the top/rear element of the stack and returns its value.
* @return A type T representing the data we want to pop off the stack.
*/
template <class T>
T GenStack<T>::pop(){
    --size;
    T data = dl->removeBack();
    return data;
}

/*
* Returns the top/rear element's value of the stack.
* @return A type T representing the data of the top/rear element of the stack which is also the data of the node in the back of the Doubly Linked List.
*/
template <class T>
T GenStack<T>::peek(){
    return dl->getBackData();
}

/*
* @return A boolean representing if the stack is empty.
* true represents empty.
* false represents not empty.
*/
template <class T>
bool GenStack<T>::isEmpty(){
    return (size == 0);
}

/* @return unsigned int size An unsigned integer representing the size of the stack */
template <class T>
unsigned int GenStack<T>::getSize(){
    return size;
}

#endif
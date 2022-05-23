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

template<class T>
class GenStack{

    public:

        GenStack(); //default constrcutor
        ~GenStack(); //destructor

        //core functions
        void push(T data);
        T pop();
        T peek(); //aka top()

        //auxiliary functions
        bool isEmpty();
        int getSize();


    private:

        DoublyLinkedList<T> *linkedlist;
        unsigned int size;
};

/* implementation */
template<class T>
GenStack<T>::GenStack(){ // default constructor

    linkedlist = new DoublyLinkedList<T>();
    size = 0;
}

template<class T>
GenStack<T>::~GenStack(){ // destructor
    delete linkedlist;
}

/**
 * adds the element of data data onto the top of the stack.
 * @param data the element of data we want to push onto the stack.
 */
template<class T>
void GenStack<T>::push(T data){

    linkedlist->insertFront(data);
    size++;
}

/**
 * removes the top element of the stack and returns its value.
 * @return the element of data at the top of the stack.
 */
template<class T>
T GenStack<T>::pop(){

    size--;
    return linkedlist->removeBack();
}

/** @return the top element's value in the stack. */
template<class T>
T GenStack<T>::peek(){

    if (linkedlist->isEmpty()){
        throw runtime_error("Stack is Empty");

    } else {
        return linkedlist->back->data;
    }
}

/** @return true if the stack is empty and false otherwise. */
template<class T>
bool GenStack<T>::isEmpty(){

    return size==0;
}

/** @return size the size of the stack */
template<class T>
int GenStack<T>::getSize(){

    return size;
}

#endif

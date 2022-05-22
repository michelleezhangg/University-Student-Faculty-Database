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

        //aux functions
        bool isEmpty();
        int getSize();


    private:

        DoublyLinkedList<T> *linkedlist;
        unsigned int size;
};

template<class T>
GenStack<T>::GenStack(){

    linkedlist = new DoublyLinkedList<T>();
    size = 0;
}

template<class T>
GenStack<T>::~GenStack(){
    delete linkedlist;
}


template<class T>
void GenStack<T>::push(T data){

    linkedlist->insertFront(data);
    size++;
}

template<class T>
T GenStack<T>::pop(){

    size--;
    return linkedlist->removeBack();
}

template<class T>
T GenStack<T>::peek(){

    if (linkedlist->isEmpty()){
        throw runtime_error("Stack is Empty");

    } else {
        return linkedlist->back->data;
    }
}

template<class T>
bool GenStack<T>::isEmpty(){

    return size==0;
}

template<class T>
int GenStack<T>::getSize(){

    return size;
}

#endif

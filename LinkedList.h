/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is a DoublyLinked List.
* This file includes both the header and the implementation for both the ListNode class and the DoublyLinkedList class.
* Both classes are template classes.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

/* header for the ListNode class */
template<class T>
class ListNode{
    public:
        ListNode(); // default constructor
        ListNode(T data); // overloaded constructor
        ~ListNode(); // destructor

        ListNode<T> *next;
        ListNode<T> *prev;
        T data;
};

/* implementation for ListNode class */
template<class T>
ListNode<T>::ListNode(){} // default constructor

/**
 * overloaded constructor for the ListNode class.
 * @param d the data for the ListNode
 */
template<class T>
ListNode<T>::ListNode(T d){ // overloaded constructor
    data = d;
    next = NULL; // 0 nullptr
    prev = NULL;
}

template<class T>
ListNode<T>::~ListNode(){} // destructor

/* header for the DoublyLinkedList class  */
template<class T>
class DoublyLinkedList{
    private:
        unsigned int size;

    public:
        DoublyLinkedList(); // default constructor
        ~DoublyLinkedList(); // destructor

        // insert
        virtual void insertFront(T d);
        virtual void insertBack(T d);

        // remove
        virtual T removeFront();
        virtual T removeBack();
        virtual T removeNode(T value);

        // find
        virtual int find(T value);
    
        // auxiliary functions
        virtual bool isEmpty();
        virtual unsigned int getSize();
        void printList(bool isPrintLink);

        ListNode<T> *front;
        ListNode<T> *back;
};

/* implementation for DoublyLinkedList class */
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){ // default constructor
    front = NULL;
    back = NULL;
    size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){ // destructor
    ListNode<T> *node = front;
    ListNode<T> *nodeToDelete = front;
    while (node != NULL){
        nodeToDelete = node->next;
        delete node;
        node = nodeToDelete;
    }
}

/**
* inserts a List Node of data d, type T at the front of the Doubly Linked List.
* @param d the data of the List Node we want to insert.
*/
template<class T>
void DoublyLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        //it's not empty
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

/**
* inserts a List Node of data d at the back of the Doubly Linked List.
* @param d the data of the List Node we want to insert.
*/
template<class T>
void DoublyLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    } else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

/**
* removes the front element in the Doubly Linked List.
* @return T data the data of the List Node removed.
* throws an error if the list is empty (nothing can be removed from an empty list).
*/
template<class T>
T DoublyLinkedList<T>::removeFront(){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        //more than one node in the list
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

/**
* removes the back element in the Doubly Linked List.
* @return the data of the removed List Node.
* throws an error if the list is empty (nothing can be removed from an empty list).
*/
template<class T>
T DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    ListNode<T> *temp = back;

    if(back->prev == NULL){
        //only node in the list
        front = NULL;
    }
    else{
        //more than one node in the list
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

/**
* finds and returns the position of the value we want to find.
* @param value the value we want to find.
* @return pos the position of the value we want to find and -1 if that value cannot be found in the Doubly Linked List.
*/
template<class T>
int DoublyLinkedList<T>::find(T value){
    int pos = -1;
    ListNode<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr->data == value)
            break;

        curr = curr->next;
    }
    //checks if curr is NULL which signifies value not in Linked List
    if(curr == NULL)
        pos = -1;

    return pos;
}

/**
* removes a List Node with the data value value and returns its data.
* @param value A type T representing the data of the List Node we want to remove.
* @return the data of the List Node we removed and -1 if that data value cannot be found in the Doubly Linked List.
*/
template<class T>
T DoublyLinkedList<T>::removeNode(T value){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    // finding value

    ListNode<T> *curr = front;
    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL) // if value is not in list
            return T();
    }
    
    // remove value
    if(curr != front && curr != back){ // if in the middle of list
        //it's in between front and back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    if(curr == front){ // if front of the list
        front = curr->next;
        front->prev = NULL;
    }

    if(curr == back){ // if back of list
        back = curr->prev;
        back->next = NULL;
    }

    curr->next = NULL;
    curr->prev = NULL;
    T data = curr->data;
    --size;
    delete curr;

    return data;
}

/* @return unsigned int size An unsigned integer representing the size of the stack */
template<class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

/* @return A boolean representing whether the stack is empty or not. */
template<class T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

/** prints out the Doubly Linked Lists including the front, rear, and each of the nodes' prev and next pointers, and its data. */
template<class T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " <==> ";
       }
    }
    cout << endl;
}

#endif

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;


//added template class functionality to the file
template<class T>
class ListNode{
    public:
        ListNode(); 
        ListNode(T data);
        ~ListNode();

        ListNode<T> *next;
        ListNode<T> *prev;
        T data;
};

//implementation
template<class T>
ListNode<T>::ListNode(){}

template<class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL; // 0 nullptr
    prev = NULL;
}

template<class T>
ListNode<T>::~ListNode(){
    //research
}

///doublylinked list class
template<class T>
class DoublyLinkedList{
    private:
        unsigned int size;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        virtual void insertFront(T d);
        virtual void insertBack(T d);

        virtual T removeFront();
        virtual T removeBack();
        virtual T removeNode(T value);

        virtual int find(T value);
        virtual bool isEmpty();
        virtual unsigned int getSize();

        void printList(bool isPrintLink);

        ListNode<T> *front;
        ListNode<T> *back;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    //guess what??? build some character and research
    ListNode<T> *node = front;
    ListNode<T> *nodeToDelete = front;
    while (node != NULL){
        nodeToDelete = node->next;
        delete node;
        node = nodeToDelete;
    }
}

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

template<class T>
T DoublyLinkedList<T>::removeNode(T value){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    //we could leverage the find method

    ListNode<T> *curr = front;
    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL)
            return T();
    }
    //but if we make it here, we found the value
    //we found it , let's proceed to remove it

    if(curr != front && curr != back){
        //it's in between front and back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }

    if(curr == back){
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

template<class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

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
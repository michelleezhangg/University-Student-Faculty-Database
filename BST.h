/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* The template file implementing a BST.
* This will be used to serve as the structure for the database, one for students, one for faculty.
*/

#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

/* header for the TreeNode class */
template <class T>
class TreeNode{
    public:
        TreeNode(); // default constructor
        TreeNode(T key); // overloaded constructor
        virtual ~TreeNode(); // destructor

        T key; //key = data
        TreeNode<T> *left;
        TreeNode<T> *right;
};

/* implementation for the TreeNode class */
template <class T>
TreeNode<T>::TreeNode(){ // default constructor
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){ // overloaded constructor
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){ // destructor
    left = NULL;
    right = NULL;
}

/* header for the BST class. */
template <class T>
class BST{
    public:
        BST();
        virtual ~BST();

        void insert(T value);
        bool contains(T value); //search
        bool deleteNode(T k);
        bool isEmpty();
        void printNodes(); //prints the whole tree using recPrint
        int getSize();

        // functions based on ID
        bool idExists(int id); // returns true if the ID exists in the tree
        T getNode(int id); //returns the node given the id
        void printNode(int id); //if id exists

        T* getMin();
        T* getMax();
        TreeNode<T> *getSuccessor(TreeNode<T> *d); //d represents the node we are going to delete
        void recPrint(TreeNode<T> *node); // recursively prints the whole tree
        T calcSum(TreeNode<T> *node);
        TreeNode<T>* getRoot();

    private:
        TreeNode<T> *root;
        int size;
};

/* implementation for the BST class */
template <class T>
BST<T>::BST(){ // default constructor
    root = NULL;
}

template <class T>
BST<T>::~BST(){} // destructor

/** @return TreeNode root */
template <class T>
TreeNode<T>* BST<T>::getRoot(){
    return root;
}

/** 
 * prints out a tree recursively starting with the param node
 * @param node a TreeNode to start printing from (root)
 */
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL)
        return;

    cout << node->key << endl;
    
    recPrint(node->left);
    recPrint(node->right);
}

/**
 * calculates the sum of all of the node's keys
 * @param node  a TreeNode to start calculating from (root)
 */
template <class T>
T BST<T>::calcSum(TreeNode<T> *node){
    if(node == NULL)
        return 0;
    
    return (node->key + calcSum(node->left) + calcSum(node->right));
}

/** prints out all nodes of the database */
template <class T>
void BST<T>::printNodes(){
    recPrint(root);
}

/** prints the key of a node (student/faculty) given the ID */
template <class T>
void BST<T>::printNode(int id){
    TreeNode<T> *current = root;

    if (root == NULL){
        return;
    } else {

        while (current->key.id != id){

            if (current == NULL){

                return;
            } else if (id < current->key.id){
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
    cout << current->key;
}

/** @return the number of nodes in the tree */
template <class T>
int BST<T>::getSize(){
    return size;
}

/** @return true if the tree is empty and false otherwise */
template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

/**
 * returns whether an ID exists in the database or not
 * @param id the id to see if it exists in the database
 * @return true if the id exists in the database and false otherwise
 */
template <class T>
bool BST<T>::idExists(int id){
    TreeNode<T> *current = root;

    if (isEmpty())
        return false;
    
    else {
        while (current->key.id != id){
            if (current == NULL)
                return false;    

            else if (id < current->key.id)
                current = current->left;
            else
                current = current->right;  
        }          
    }

    return true;
}

/**
 * returns the key of a node from the tree given the ID
 * @param id the ID we want the key from
 */
template <class T>
T BST<T>::getNode(int id){
    TreeNode<T> *current = root;

    if (root == NULL)
        return T();

    else {
        while (current->key.id != id){
            if (current == NULL)
                return T();
                
            else if (id < current->key.id)
                current = current->left;
            else
                current = current->right;
        }
    }

    return current->key;
}

/**
 * returns the minimum key in the BST
 * @return the minimum key in the BST
 */
template <class T>
T* BST<T>::getMin(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return &(current->key);
}

/**
 * returns the maximum key in the BST
 * @return the maximum key in the BST
 */
template <class T>
T* BST<T>::getMax(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return &(current->key);
}

/**
 * inserts a node of key value into BST, maintains BST rules
 * @param value value of node wanting to be inserted
 */
template <class T>
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);
    
    if(isEmpty())
        root = node;

    else { // the tree not empty
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while(true){
            parent = current;
            
            if(value < current->key){ 
                // check left
                current = current->left;
                if(current == NULL){
                    // insert
                    parent->left = node;
                    break;
                }
            }
            
            else{
                // check right
                current = current->right;
                if(current == NULL){
                    // insert
                    parent->right = node;
                    break;
                }
            }
        }
    }
    size++;
}

/**
 * checks if a value exists in the BST
 * @param value the value to check
 * @return true if the value exists in the BST and false otherwise
 */
template <class T>
bool BST<T>::contains(T value){
    if(isEmpty())
        return false;

    TreeNode<T> *current = root;

    while(current->key != value){
        if(value < current->key)
            current = current->left;
        else
            current = current->right;

        if (current == NULL)
            return false;
    }
    return true;
}

/**
 * deletes a node of value k from the BST
 * @param k the key to delete
 * @return true if successfully delete and false otherwise
*/
template <class T>
bool BST<T>::deleteNode(T k){
    if (isEmpty())
        return false; // empty tree

    --size;
    // search for node
    TreeNode<T> *parent = NULL;
    TreeNode<T> *current = root;
    bool isLeftNode = true;

    while (current->key != k) {
        parent = current;

        if (k < current->key) {
            isLeftNode = true;
            current = current->left;
        } else {
            isLeftNode = false;
            current = current->right;
        }

        if (current == NULL)
            return false; // node not found
    }

    // deleting found node

    // case 1: node is a leaf node (no children)
    if (current->left == NULL && current->right == NULL) {
        if (current == root) // only root node in tree
            root = NULL;
        else if (isLeftNode) // node is left node
            parent->left = NULL;
        else // node is right node
            parent->right = NULL;
    }

    // case 2: node has one child
    else if (current->right == NULL) { // only has a left child
        if (current == root)
            root = current->left; // change child to root
        else if (isLeftNode)
            parent->left = current->left;
        else
            parent->right = current->left;
    }

    else if (current->right == NULL) { // only has a right child
        if (current == root)
            root = current->right; // change child to root
        else if (isLeftNode)
            parent->left = current->right;
        else
            parent->right = current->right;
    }

    // case 3: node has two children
    else {
        TreeNode<T> *successor = getSuccessor(current);

        if (current == root)
            root = successor;
        else if (isLeftNode)
            parent->left = successor;
        else
            parent->right = successor;

    }
    return true;
}

/** 
 * finds the successor of the parameter node
 * @return the successor of the parameter node
 */
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while (current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }

    return current;
}

#endif
/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees
*/

#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

/* header for the TreeNode class. */
template <class T>
class TreeNode {
    public:
        TreeNode(); // default constructor
        TreeNode(T key); // overloaded constructor
        virtual ~TreeNode(); // destructor

        T key; //key = data
        TreeNode<T> *left; // left child
        TreeNode<T> *right; // right child
};

/* implementation for the TreeNode class. */
template <class T>
TreeNode<T>::TreeNode() {
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k) {
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode() {
    left = NULL;
    right = NULL;
}

/* header for the BST class. */
template <class T>
class BST {
    public:
        BST(); // default constructor
        virtual ~BST(); // destructor

        void insert(T value);
        bool contains(T value); // search
        bool deleteNode(T k);
        bool isEmpty();

        T* getMin();
        T* getMax();
        TreeNode<T> *getSuccessor(TreeNode<T> *d); //d represents the node we are going to delete
        void printNodes();
        void recPrint(TreeNode<T> *node);
        T calcSum(TreeNode<T> *node);
        TreeNode<T>* getRoot();

        bool idExists(int id);
        void printNode(int id);
        T getNode(int id);
    private:
        TreeNode<T> *root;
};

/* implementation for the BST class. */
template <class T>
BST<T>::BST() { // default constructor
    root = NULL;
}

template <class T>
BST<T>::~BST() { // destructor
    delete root;
}

/** @return the root (TreeNode) of the BST */
template <class T>
TreeNode<T>* BST<T>::getRoot() {
    return root;
}

/** 
 * prints out the entire BST (uses recursion).
 * auxiliary function to help with function printNodes().
 */
template <class T>
void BST<T>::recPrint(TreeNode<T> *node) {
    if(node == NULL)
        return;

    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

/**
 * @return the sum of all of the nodes' keys in the BST. 
 * not needed in this assignment.
 */
template <class T>
T BST<T>::calcSum(TreeNode<T> *node) {
    if(node == NULL)
        return 0;
    
    return (node->key + calcSum(node->left) + calcSum(node->right));
}

/**
 * prints out all of the nodes of the BST from leftmost to rightmost.
 * uses the function recPrint() to help.
 */
template <class T>
void BST<T>::printNodes() {
    recPrint(root);
}

/**
 * tells whether the BST is empty or not.
 * @return true if the BST is empty (root is null).
 * @return false if the BST is not empty (root is not null).
 */
template <class T>
bool BST<T>::isEmpty() {
    return (root == NULL);
}

/**
 * outputs the minimum key value of the tree.
 * @return the key value of the minimum of the tree or the leftmost node of the tree.
 */
template <class T>
T* BST<T>::getMin() {
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return &(current->key);
}

/**
 * outputs the maximum key value of the tree.
 * @return the key value of the maximum of the tree or the rightmost node of the tree.
 */
template <class T>
T* BST<T>::getMax() {
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->right != NULL) {
        current = current->right;
    }
    return &(current->key);
}

/**
 * inserts a node of key value into the BST while maintaining the BST rules.
 * @param value The value that wants to be inserted into the BST.
 */
template <class T>
void BST<T>::insert(T value) {
    TreeNode<T> *node = new TreeNode<T>(value);
    
    if(isEmpty())
        root = node;
    else {
        //the tree is not empty
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while(true) {
            parent = current;
            
            if(value < current->key){
                //we go left
                current = current->left;
                if(current == NULL){
                    //we found the insertion point
                    parent->left = node;
                    break;
                }
            }
            else {
                //we go right
                current = current->right;
                if(current == NULL) {
                    //we found the insertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }
    
}

/**
 * checks if the BST contains the parameter (value).
 * @param value the value that we want to check if the BST contains.
 * @return true if the value exists in the BST.
 * @return false if the value does not exist in the BST.
 */
template <class T>
bool BST<T>::contains(T value) {
    if(isEmpty())
        return false;

    TreeNode<T> *current = root;

    while(current->key != value) {
        if(value < current->key)
            current = current->left;
        else
            current = current->right;

        if(current == NULL)
            return false;
    }
    return true;
}

/**
 * deletes a node of value k from the BST.
 * @param k the key value that we wish to delete from the BST.
 * @return true if the node is successfully deleted from the BST.
 * @return false if the node cannot be deleted from the BST.
 */
template <class T>
bool BST<T>::deleteNode(T k) {
    if (isEmpty())
        return false; // empty tree

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

        return true;
    }

}

template <class T>
/* d represents the node to be delete */
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {
}

/**
 * tells whether or not an ID exists in the database.
 * @param id an integer representing the ID that we wish to know whether it exists in the database or not.
 * @return true if the ID is found in the database (exists).
 * @return false if the ID is not found in the database (does not exist).
 */
template <class T>
bool BST<T>::idExists(int id) {
    TreeNode<T> *current = root;

    if (root == NULL)
        return false;
    
    else {
        while (current->key.id != id) {
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
 * prints out the node of the tree given the ID.
 * @param id an integer representing the ID that we wish to know
 */
template <class T>
T BST<T>::getNode(int id) {
    TreeNode<T> *current = root;

    if (root == NULL)
        return;
    
    else {
        while (current->key.id != id) {
            if (current == NULL)
                return;
            else if (id < current->key.id)
                current = current->left;
            else    
                current = current->right;
        }
    }
    return current->key;
}

#endif
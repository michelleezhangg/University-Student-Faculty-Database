#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T key);
        virtual ~TreeNode();

        T key; //key = data
        TreeNode<T> *left;
        TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
class BST{
    public:
        BST();
        virtual ~BST();

        void insert(T value);
        bool contains(T value);//search
        bool deleteNode(T k);
        bool isEmpty();

        bool idExists(int id); // returns true if the ID exists in the tree
        T getNode(int id); //returns the node given the id
        void printNode(int id); //if id exists

        void printNodes(); //prints the whole tree
        int getSize();

        T* getMin();
        T* getMax();

        TreeNode<T> *getSuccessor(TreeNode<T> *d); //d represents the node we are going to delete
        
        void recPrint(TreeNode<T> *node); //called to print nodes (recursively)
        
        T calcSum(TreeNode<T> *node);
        TreeNode<T>* getRoot();
        int size;

    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){
    //build some character
    //and do a little research
}

template <class T>
TreeNode<T>* BST<T>::getRoot(){
    return root;
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    
    if(node == NULL)
        return;

    cout << node->key << endl;
    
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
T BST<T>::calcSum(TreeNode<T> *node){
    if(node == NULL)
        return 0;
    
    return (node->key + calcSum(node->left) + calcSum(node->right));
}

template <class T>
void BST<T>::printNodes(){

    recPrint(root);
}

template <class T>
/*this function prints the entire tree*/
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

template <class T>
int BST<T>::getSize(){

    return size;

}

template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
bool BST<T>::idExists(int id){

    TreeNode<T> *current = root;

    if (root == NULL){

        return false;
    } else {

        while (current->key.id != id){

            if (id < current->key.id){

                current = current->left;
            } else {

                current = current->right;

            } if (current == NULL) {

                return false;                
            }
        }
    }
    return true;
}

template <class T>
T BST<T>::getNode(int id){
    TreeNode<T> *current = root;

    if (root == NULL){
        
        return T();

    } else {

        while (current->key.id != id){

            if (current == NULL){

                return T();
                
            } else if (id < current->key.id){
                current = current->left;

            } else {
                current = current->right;
            }
        }
    }
    return current->key;

}

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

template <class T>
void BST<T>::insert(T value){

    TreeNode<T> *node = new TreeNode<T>(value);
    
    if(root == NULL){
        root = node;

    } else{
        //the tree is not empty

        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while(true){
            parent = current;
            
            if(value < current->key){
                //we go left
                current = current->left;
                if(current == NULL){

                    //we found the insertion point
                    parent->left = node;
                    break;
                }
            } else{

                //we go right
                current = current->right;
                if(current == NULL){

                    cout << "7" <<  endl;
                    //we found the insertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }

    size++;
    
}

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

        if(current == NULL)
            return false;
    }
    return true;
}

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

template <class T>
/* d represents the node to be delete */
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
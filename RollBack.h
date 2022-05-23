/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the RollBack Class.
*/

#include <iostream>
#include "GenStack.h"
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

#ifndef ROLLBACK_H
#define ROLLBACK_H

class RollBack{

    public:

        RollBack(); // default constructor
        ~RollBack(); // destructor

       //manipulating the student tree
        bool studentAction(string action, Student *student);

        //manipulating the faculty tree
        bool facultyAction(string action, Faculty *faculty);

        // performs the action of undo
        bool undo(BST<Student>* studentBST, BST<Faculty>* facultyBST);

        void clear();

    private:

        GenStack<Student*> studentDBHistory;
        GenStack<Faculty*> facultyDBHistory;
        GenStack<string> reverseAction;

        int numUndos;


};

#endif

/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the RollBack Class.
*/

#ifndef ROLLBACK_H
#define ROLLBACK_H

#include "GenStack.h"
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

class RollBack {
    public:
        RollBack(); // default constructor
        ~RollBack(); // destructor

        bool studentAction(string a, Student *s);
        bool facultyAction(string a, Faculty *f);

        bool undo(BST<Student> *studentDB, BST<Faculty> *facultyDB);

    private:
        GenStack<Student*> studentDBHistory;
        GenStack<Faculty*> facultyDBHistory;
        GenStack<string> reverseAction;
        int numUndos;
};

#endif
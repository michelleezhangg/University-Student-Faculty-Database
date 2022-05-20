/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
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

        bool studentAction(Student *s, string a);
        bool facultyAction(Faculty *f, string a);

        void undo();
        void clear();

    private:
        GenStack<Student*> studentDBHistory;
        GenStack<Faculty*> facultyDBHistory;
        GenStack<string> reverseAction;
        int numUndos;
};

#endif
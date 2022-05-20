/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the RollBack Class.
*/

#include "RollBack.h"

RollBack::RollBack() { // default constructor
    studentDBHistory = GenStack<Student*>();
    facultyDBHistory = GenStack<Faculty*>();
    reverseAction = GenStack<string>();
    numUndos = 0;
}

RollBack::~RollBack() {} // destructor

/***/
bool RollBack::studentAction(Student *s, string a) {
    if (numUndos > 5)
        return false;
    
    ++numUndos;
    studentDBHistory.push(s);
    reverseAction.push(a);
    return true;
}

/***/
bool RollBack::facultyAction(Faculty *f, string a) {
    if (numUndos > 5)
        return false;
    
    facultyDBHistory.push(f);
    reverseAction.push(a);
    return true;
}

/***/
void RollBack::undo() {

}

/***/
void RollBack::clear() {

}
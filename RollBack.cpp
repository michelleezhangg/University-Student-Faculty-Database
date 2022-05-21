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

/**
 * 
 * @param s a Student committing the action (insert/delete)
 * @param a a string representing the action in two letters detailing insert or delete and student or faculty.
 * "is" represents insert student
 * "if" represents insert faculty
 * "ds" represents delete student
 * "df" represents delete faculty
 * @return true
 * @return false 
 */
bool RollBack::studentAction(Student *s, string a) {
    if (numUndos > 5)
        return false;
    
    ++numUndos;
    studentDBHistory.push(s);
    reverseAction.push(a);
    return true;
}

/**
 * 
 * @param f a Faculty committing the action (insert/delete)
 * @param a a string representing the action in two letters detailing insert or delete and student or faculty.
 * "is" represents insert student
 * "if" represents insert faculty
 * "ds" represents delete student
 * "df" represents delete faculty
 * @return true if 
 * @return false 
 */
bool RollBack::facultyAction(Faculty *f, string a) {
    if (numUndos > 5)
        return false;
    
    facultyDBHistory.push(f);
    reverseAction.push(a);
    return true;
}

/**
 * @brief 
 * 
 * @return true if the undo worked
 * @return false if the undo did not work
 */
bool RollBack::undo(BST<Student> *studentDB, BST<Faculty> *facultyDB) {
    if (numUndos > 0) {
        string action = reverseAction.pop();
        if (action[1] == 's') {
            Student *s = studentDBHistory.pop();

            if (action[0] == 'i') // delete the student to undo
                studentDB->deleteNode(*s);
            else if (action[0] == 'd') // insert the student to undo
                studentDB->insert(*s);

        } 
        
        else if (action[1] == 'f') {
            Faculty *f = facultyDBHistory.pop();

            if (action[0] == 'i') // delete the faculty to undo
                facultyDB->deleteNode(*f);

                //FIXME: solve advisor/advisee problem
                
            else if (action[0] == 'd') // insert the faculty to undo
                facultyDB->insert(*f);
        
        }
        --numUndos;
        cout << "num undos: " << numUndos << endl; // test
        return true;
    }
    return false;
}
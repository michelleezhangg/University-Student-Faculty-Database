/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
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
bool RollBack::studentAction(string a, Student *s) {
    if (numUndos > 5)
        return false;
    
    ++numUndos;
    reverseAction.push(a);
    studentDBHistory.push(s);
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
bool RollBack::facultyAction(string a, Faculty *f) {
    if (numUndos > 5)
        return false;
    
    reverseAction.push(a);
    facultyDBHistory.push(f);
    return true;
}

/**
 * @brief 
 * 
 * @return true if the undo worked
 * @return false if the undo did not work
 */
bool RollBack::undo(BST<Student> *studentDB, BST<Faculty> *facultyDB) {
    if (numUndos != 0) {
        string action = reverseAction.pop();

        Student *s;
        Faculty *f;

        if (action.find("student") != string::npos)// 
            s = studentDBHistory.pop();

        
        else if (action.find("faculty") != string::npos)
            f = facultyDBHistory.pop();

        if (action == "add student") {
            studentDB->deleteNode(*s);

            cout << "---------------------------------" << endl;
            cout << "successful undo" << endl;
            cout << "---------------------------------" << endl;
        }

        else if (action == "add faculty") {
            facultyDB->deleteNode(*f);

            cout << "---------------------------------" << endl;
            cout << "Successful undo" << endl;
            cout << "---------------------------------" << endl;
        }

        else if (action == "delete student") {
            studentDB->insert(*s);

            cout << "---------------------------------" << endl;
            cout << "Successful undo" << endl;
            cout << "---------------------------------" << endl;
        }

        else if (action == "delete faculty") {
            facultyDB->insert(*f);

            cout << "---------------------------------" << endl;
            cout << "Successful undo" << endl;
            cout << "---------------------------------" << endl;
        }

        else
            cout << endl << "ERROR" << endl;

        --numUndos;
        cout << "Number of undos left: " << numUndos << endl;
        return true;
    }
    
    return false;
}
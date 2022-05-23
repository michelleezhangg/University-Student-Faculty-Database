/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the RollBack Class.
*/

#include <iostream>
#include "RollBack.h"

using namespace std;

RollBack::RollBack(){ // default constructor

    numUndos = 0;

    GenStack<string> reverseAction = GenStack<string>();

    GenStack<Student*> studentDBHistory = GenStack<Student*>();
    GenStack<Faculty*> facultyDBHistory = GenStack<Faculty*>();

}

RollBack::~RollBack(){} // destructor

/**
 * adds a student's action to the action stack and the student stack.
 * @param s a Student committing the action (insert/delete)
 * @param a a string representing the action of the student.
 * @return true if the undo can be done.
 * @return false if the user ran out of undos.
 */
bool RollBack::studentAction(string action, Student *student){

    if(numUndos > 5){
        return false;
    }

    numUndos++;
    reverseAction.push(action);
    studentDBHistory.push(student);  

    return true;

}

/**
 * adds a faculty's action to the action stack and the faculty stack.
 * @param f a Faculty committing the action (insert/delete)
 * @param a a string representing the action of the faculty.
 * @return true if the undo can be done.
 * @return false if the user ran out of undos.
 */
bool RollBack::facultyAction(string action, Faculty *faculty){

    if(numUndos > 5){
        return false;
    }

    numUndos++;
    reverseAction.push(action);
    facultyDBHistory.push(faculty);  

    return true;

}


bool RollBack::undo(BST<Student>* studentBST, BST<Faculty>* facultyBST){

    if (numUndos != 0){

        string action = reverseAction.pop();

        Student* student;
        Faculty* faculty;

        // this means the action involved a student
        if (action.find("STUDENT") != string::npos){

            student = studentDBHistory.pop();
            
        } else if (action.find("FACULTY") != string::npos){

            faculty = facultyDBHistory.pop();
        }

        if (action == "ADD STUDENT"){

            studentBST->deleteNode(*student);

            cout << endl << "-----------------";
            cout << endl << "SUCCESSFUL UNDO" << endl;
            cout << "-----------------" << endl;

        } else if (action == "DELETE STUDENT"){

            studentBST->insert(*student);

            cout << endl << "-----------------";
            cout << endl << "SUCCESSFUL UNDO" << endl;
            cout << "-----------------" << endl;

        } else if (action == "ADD FACULTY"){

            facultyBST->deleteNode(*faculty);

            cout << endl << "-----------------";
            cout << endl << "SUCCESSFUL UNDO" << endl;
            cout << "-----------------" << endl;

        } else if (action == "DELETE FACULTY"){

            facultyBST->insert(*faculty);

            cout << endl << "-----------------";
            cout << endl << "SUCCESSFUL UNDO" << endl;
            cout << "-----------------" << endl;

        } else {

            cout << endl << "ERROR" << endl;

        }
        numUndos--;
        cout << endl << "Number of undos Left: "<< numUndos << endl;
        return true;
    }
    return false;
}



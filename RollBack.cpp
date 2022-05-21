#include <iostream>
#include "RollBack.h"

using namespace std;

RollBack::RollBack(){

    numUndos = 0;

    studentDBHistory = GenStack<Student*>();
    facultyDBHistory = GenStack<Faculty*>();

}

RollBack::~RollBack(){}

bool RollBack::studentAction(string action, Student *student){

    if(numUndos > 5){
        return false;
    }

    ++numUndos;
    reverseAction.push(action);
    studentDBHistory.push(student);  

    return true;

}

bool RollBack::facultyAction(string action, Faculty *faculty){

    if(numUndos > 5){
        return false;
    }

    ++numUndos;
    reverseAction.push(action);
    facultyDBHistory.push(faculty);  

    return true;

}

bool RollBack::undo(BST<Student>* studentBST, BST<Faculty>* facultyBST){

    if (numUndos > 0){

        string action = reverseAction.pop();
        cout << action << endl;

        Student* student;
        Faculty* faculty;

        // this means the action involved a student
        if (action[1] == 's'){
            student = studentDBHistory.pop();

            if (action[0] == 'i'){

                studentBST->deleteNode(*student);

            } else if (action[0] == 'd'){

                studentBST->insert(*student);
            }

        } else if (action[2] == 'f'){
            faculty = facultyDBHistory.pop();

            if (action[0] == 'i'){
                facultyBST->deleteNode(*faculty);

            } else if (action[1] == 'd'){
                facultyBST->insert(*faculty);

            }

        }
        numUndos--;
        cout << "Number of undos Left: "<< numUndos << endl;
        return true;
    }
    return false;
}



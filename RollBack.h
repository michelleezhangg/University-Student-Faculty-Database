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

        RollBack();
        ~RollBack();

       //manipulating the student tree
        bool studentAction(string action, Student *student);

        //manipulating the faculty tree
        bool facultyAction(string action, Faculty *faculty);

        bool undo(BST<Student>* studentBST, BST<Faculty>* facultyBST);

        void clear();

    private:

        GenStack<Student*> studentDBHistory;
        GenStack<Faculty*> facultyDBHistory;
        GenStack<string> reverseAction;

        int numUndos;


};

#endif
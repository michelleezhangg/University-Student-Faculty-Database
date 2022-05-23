/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Database Class.
*/

#ifndef DB_H
#define DB_H

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "Serialization.h"
#include "RollBack.h"

class DB{

    public:

        DB(); // default constructor
        ~DB(); // destructor

        void simulate(); // core function
    
        // auxiliary functions
        void readFiles();
        int printOptions();

        void printAllStudentInfo(); // option 1
        void printAllFacultyInfo(); // option 2
        void printSpecificStudent(); // option 3
        void printSpecificFaculty(); // option 4
        void printFacultyAdvisor(); // option 5
        void printFacultyAdvisees(); // option 6
        void addNewStudent(); // option 7
        void deleteStudent(); // option 8
        void addNewFaculty(); // option 9
        void deleteFaculty(); // option 10
        void changeStudentAdvisor(); // option 11
        void removeAdvisee(); // option 12
        void Undo(); // option 13
        void Exit(); // option 14





    private:

        BST<Student> *masterStudent;
        BST<Faculty> *masterFaculty;

        RollBack *rb;
        Serialization *s;



};

#endif

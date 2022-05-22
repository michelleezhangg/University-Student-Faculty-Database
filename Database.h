/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Database Class.
*/

#ifndef DATABASE_H
#define  DATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "RollBack.h"
#include "Serialization.h"

class Database {
    public:
        Database(); // default constructor
        ~Database(); // destructor

        void simulate(); // core function

        // auxiliary functions
        void readFiles();
        int printMenu();

        void printAllStudents();                // option 1
        void printAllFaculty();                 // option 2
        void printStudentInfo();                // option 3
        void printFacultyInfo();                // option 4
        void printAdvisorInfo();                // option 5
        void printAdviseesInfo();               // option 6
        void addNewStudent();                   // option 7
        void deleteStudent();                   // option 8
        void addNewFaculty();                   // option 9
        void deleteFaculty();                   // option 10
        void changeAdvisor();                   // option 11
        void removeAdvisee();                   // option 12
        void rollBack();                        // option 13
        void exitProgram();                            // option 14

    private:
        BST<Student> *masterStudent;
        BST<Faculty> *masterFaculty;
        RollBack *rb;
        Serialization *s;
};

#endif
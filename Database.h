/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Database Class.
*/

#ifndef DATABASE_H
#define  DATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "Serialization.h"

class Database {
    public:
        Database(); // default constructor
        ~Database(); // destructor

        void run(); // core function

        // auxiliary functions
        int printMenu();

        void printAllStudents();                // option 1
        void printAllFaculty();                 // option 2
        void printStudentInfo();                // option 3
        void printFacultyInfo();                // option 4
        void printFacultyInfoFromStudent();     // option 5
        void printFacultyAdviseesInfo();        // option 6
        void addNewStudent();                   // option 7
        void deleteStudent();                   // option 8
        void addNewFaculty();                   // option 9
        void deleteFaculty();                   // option 10
        void changeStudentAdvisors();           // option 11
        void removeFacultyAdvisees();           // option 12
        void rollBack();                        // option 13
        void exit();                            // option 14

    private:
        BST<Student> *masterStudent;
        BST<Faculty> *masterFaculty;
};

#endif
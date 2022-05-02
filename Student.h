/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Student class.
*/

#ifndef STUDENT_H // header guard
#define STUDENT_H

#include "StudentRecords.h"

class Student {
    public:
        Student(); // default constructor
        ~Student(); // destructor

        // overloading operators
        bool operator == (Student *s);
        bool operator != (Student *s);
        bool operator > (Student *s);
        bool operator < (Student *s);

        StudentRecords *sr;

    private:
};

#endif
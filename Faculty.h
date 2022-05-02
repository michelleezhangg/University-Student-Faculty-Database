/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Faculty Class.
*/

#ifndef FACULTY_H // header guard
#define FACULTY_H

#include "FacultyRecords.h"

class Faculty {
    public:
        Faculty(); // default constructor
        ~Faculty(); // destructor

        // overloading operators
        bool operator == (Faculty *f);
        bool operator != (Faculty *f);
        bool operator > (Faculty *f);
        bool operator < (Faculty *f);

        FacultyRecords *fr;

    private:
};

#endif
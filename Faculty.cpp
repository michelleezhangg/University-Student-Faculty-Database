/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Faculty Class.
*/

#include "Faculty.h"

Faculty::Faculty() { // default constructor
    fr = new FacultyRecords();
}

Faculty::~Faculty() { // destructor
    delete fr;
}

// overloaded operator
bool Faculty::operator == (Faculty *f) {
    return this->fr->getID() == f->fr->getID();
}

bool Faculty::operator != (Faculty *f) {
    return this->fr->getID() != f->fr->getID();
}

bool Faculty::operator > (Faculty *f) {
    return this->fr->getID() > f->fr->getID();
}

bool Faculty::operator < (Faculty *f) {
    return this->fr->getID() < f->fr->getID();
}
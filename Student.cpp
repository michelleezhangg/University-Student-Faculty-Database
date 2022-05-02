/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Student Class.
*/

#include "Student.h"

Student::Student() { // default constructor
    sr = new StudentRecords();
}

Student::~Student() { // destructor
    delete sr;
}

// overloaded operator
bool Student::operator == (Student *s) {
    return this->sr->getID() == s->sr->getID();
}

bool Student::operator != (Student *s) {
    return this->sr->getID() != s->sr->getID();
}

bool Student::operator > (Student *s) {
    return this->sr->getID() > s->sr->getID();
}

bool Student::operator < (Student *s) {
    return this->sr->getID() < s->sr->getID();
}
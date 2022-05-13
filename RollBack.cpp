/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the RollBack Class.
*/

#include "RollBack.h"

RollBack::RollBack() { // default constructor
    studentDBHistory = new GenStack <BST<Student> >();
    facultyDBHistory = new GenStack <BST<Faculty> >();
}

RollBack::~RollBack() { // destructor
    delete studentDBHistory;
    delete facultyDBHistory;
}
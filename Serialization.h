/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Serialization Class.
*/

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <exception>

#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Serialization {
    public:
        Serialization(); // default constructor
        ~Serialization(); // destructor

        // read files
        void readStudentFile(BST<Student> *sdb);
        void readFacultyFile(BST<Faculty> *fdb);

        // write students/faculties
        void populateStudentDB(BST<Student> *sdb);
        void populateFacultyDB(BST<Faculty> *fdb);

        // write files
        void writeStudentFile(TreeNode<Student> *s, BST<Student> *sdb);
        void writeFacultyFile(TreeNode<Faculty> *f, BST<Faculty> *fdb);

        // serialize
        void serialize(BST<Student> *sdb, BST<Faculty> *fdb);
};

#endif
/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Serialization Class.
*/

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
        void readStudentFile(BST<Student> *studentDB);
        void readFacultyFile(BST<Faculty> *facultyDB);

        // write files
        void writeStudentFile(TreeNode<Student> *s, BST<Student> *studentDB);
        void writeFacultyFile(TreeNode<Faculty> *f, BST<Faculty> *facultyDB);

        // serialize (core funcion)
        void serialize(BST<Student> *studentDB, BST<Faculty> *facultyDB);
};

#endif
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
#include <exception>
using namespace std;

class Serialization {
    public:
        Serialization(); // default constructor
        ~Serialization(); // destructor

        // read files
        void readStudentFile();
        void readFacultyFile();

        // write files
        void writeStudentFile();
        void writeFacultyFile();

        // serialize
        void serialize();
};

#endif
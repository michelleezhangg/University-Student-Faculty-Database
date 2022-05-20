/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Serialization Class.
*/

#include "Serialization.h"

Serialization::Serialization() { // default constructor

}

Serialization::~Serialization() { // destructor

}

/* reading files */
void Serialization::readStudentFile() {
    ifstream ReadFile("studentTable.txt");

    if (ReadFile.is_open())
        cout << "can open" << endl; // will continue

    ReadFile.close();
}

void Serialization::readFacultyFile() {
    ifstream ReadFile("facultyTable.txt");

    if (ReadFile.is_open())
        cout << "can open" << endl; // will continue

    ReadFile.close();
}

/* writing files */
void Serialization::writeStudentFile() {

}

void Serialization::writeFacultyFile() {

}

/* serialize */
void Serialization::serialize() {

}
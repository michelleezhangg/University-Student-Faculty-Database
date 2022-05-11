/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Person class.
* This is the base class for the Student Class and the Faculty Class.
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        Person(); // default constructor
        ~Person(); // destructor

        // overloaded operators
        bool operator == (Person &p);
        bool operator != (Person &p);
        bool operator > (Person &p);
        bool operator < (Person &p);

        // attributes
        int id;
        string name;
        string level;
};

#endif
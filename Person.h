/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
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
    
        // attributes
        string name;
        int id;
        string level;

        // overloaded operators
        bool operator == (Person &person);
        bool operator != (Person &person);
        bool operator > (Person &person);
        bool operator < (Person &person);

};

#endif

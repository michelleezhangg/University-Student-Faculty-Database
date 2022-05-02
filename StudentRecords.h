/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the StudentRecords class.
*/

#ifndef STUDENTRECORDS_H // header guard
#define STUDENTRECORDS_H

#include <iostream>
#include <string>
using namespace std;

class StudentRecords {
    public:
        StudentRecords(); // default constructor
        StudentRecords(int id, string name, string level, string major, double gpa, int advisorID); // overloaded constructor
        ~StudentRecords(); // destructor

        // accessor
        int getID();
        string getName();
        string getLevel();
        string getMajor();
        double getGPA();
        int getAdvisorID();

        // mutators
        void setID(int id);
        void setName(string name);
        void setLevel(string level);
        void setMajor(string major);
        void setGPA(double gpa);
        void setAdvisorID(int advisorID);

    private:
        int id;
        string name;
        string level;
        string major;
        double gpa;
        int advisorID;
};

#endif
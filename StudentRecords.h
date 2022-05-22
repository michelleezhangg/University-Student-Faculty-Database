/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the StudentRecords class.
*/

#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include <iostream>
#include <string>
using namespace std;

class StudentRecords {
    public:
        StudentRecords(); // default constructor
        StudentRecords(int i, string n, string l, string m, double g, int a); // overloaded constructor
        ~StudentRecords(); // destructor

        // accessor
        int getID();
        string getName();
        string getLevel();
        string getMajor();
        double getGPA();
        int getAdvisorID();

        // mutators
        void setID(int i);
        void setName(string n);
        void setLevel(string l);
        void setMajor(string m);
        void setGPA(double g);
        void setAdvisorID(int a);

    private:
        int id;
        string name;
        string level;
        string major;
        double gpa;
        int advisorID;
};

#endif
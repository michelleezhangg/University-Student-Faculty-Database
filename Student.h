/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Student class.
* This class inherits from Person Class.
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "StudentRecords.h"

class Student : public Person {

    public:

        Student(); // default constructor
        Student(string name, int id, string level, string major, double gpa, int advisorID); // overloaded constructor
        ~Student(); // destructor

        // accessors
        string getName();
        int getID();
        string getLevel();
        string getMajor();
        int getGPA();
        int getAdvisorID();

        // mutators
        void setName(string sName);
        void setID(int sID);
        void setLevel(string sLevel);
        void setMajor(string sMajor);
        void setGPA(double sGPA);
        void setAdvisorID(int sAdvisorID);

        // other functions
        string getStudentInfo();
        friend ostream& operator << (ostream &os, const Student &s);

        // attributes
        string major;
        double gpa;
        int advisorID;
        StudentRecords *studentRecord;

};

#endif

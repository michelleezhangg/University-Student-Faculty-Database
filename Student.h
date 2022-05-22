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
        Student(int i, string n, string l, string m, double g, int a); // overloaded constructor
        ~Student(); // destructor

        // accessors
        string getMajor();
        double getGPA();
        int getAdvisorID();
        StudentRecords getStudentRecords();

        // mutators
        void setMajor(string m);
        void setGPA(double g);
        void setAdvisorID(int a);
        void setStudentRecords(StudentRecords *student_records);

        // other functions
        string getStudentInfo();
        friend ostream& operator << (ostream &os, const Student &s);

        string major;
        double gpa;
        int advisorID;
        StudentRecords *sr;
};

#endif
/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Faculty Class.
* This class inherits from Person Class.
*/

#ifndef FACULTY_H // header guard
#define FACULTY_H

#include "Person.h"
#include "FacultyRecords.h"

class Faculty : public Person {
    public:
        Faculty(); // default constructor
        Faculty(int i, string n, string l, string d); // overloaded constructor
        ~Faculty(); // destructor

        // accessors
        string getDepartment();
        vector<int> getAdviseeIDs();
        int getNumAdvisees();

        // mutators
        void setDepartment(string d);
        void setNumAdvisees(int na);
        void setAdviseesIDs(vector<int> *sid);

        // functions
        void addAdvisee(int id);
        void removeAdvisee(int id);

        string getFacultyInfo();
        string getAdviseesIDs();
        friend ostream& operator << (ostream &os, const Faculty &f);

        // attributes
        string department;
        int numAdvisees;
        vector<int> *studentIDs;
        FacultyRecords *fr;
};

#endif
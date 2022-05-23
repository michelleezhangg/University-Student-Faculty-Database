/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the Faculty Class.
* This class inherits from Person Class.
*/

#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include "FacultyRecords.h"

#include <vector>

class Faculty : public Person {

    public:

        Faculty(); // default constructor
        Faculty(string name, int id, string level, string department); // overloaded constructor
        ~Faculty();

        // accessors
        string getName();
        int getID();
        string getLevel();
        string getDepartment();
        vector<int> getAdviseeIDs();
        int getNumAdvisees();

        // mutators
        void setName(string fName);
        void setID(int fID);
        void setLevel(string fLevel);
        void setDepartment(string fDepartment);
        void setAdviseeID(vector<int> *aIDs);
        void setNumAdvisees(int na);

        // functions
        void addAdvisee(int id);
        void removeAdvisee(int id);

        string getAdviseeID();
        string getFacultyInfo();
        friend ostream& operator << (ostream &os, const Faculty &f);

        // attributes
        string department;
        int numAdvisees;
        vector<int> *adviseeIDs;
        FacultyRecords *facultyRecord;


};

#endif

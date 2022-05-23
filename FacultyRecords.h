/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the header file for the FacultyRecords class.
*/

#ifndef FACULTYRECORDS_H
#define FACULTYRECORDS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FacultyRecords {

    public:

        FacultyRecords(); // default constructor
        FacultyRecords(string facultyName, int facultyID, string facultyLevel, string facultyDepartment, vector<int> *facultyAdviseeIDs); // overloaded constructor
        ~FacultyRecords(); // destructor

        // accessors
        int getFacultyID();
        vector<int> getFacultyAdviseeIDs();
        string getFacultyName();
        string getFacultyLevel();
        string getFacultyDepartment();

        // mutators
        void setFacultyID(int fID);
        void setFacultyAdviseeIDs(vector<int> *fAdviseeIDs);
        void setFacultyName(string fName);
        void setFacultyLevel(string fLevel);
        void setFacultyDepartment(string fDepartment);

    private:

        string facultyName;
        int facultyID;
        string facultyLevel;
        string facultyDepartment;
        vector<int> *facultyAdviseeIDs;


};

#endif

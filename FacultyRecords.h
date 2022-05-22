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
        FacultyRecords(int i, string n, string l, string d, vector<int> *sid); // overloaded constructor
        ~FacultyRecords(); // destructor

        // accessors
        int getID();
        string getName();
        string getLevel();
        string getDepartment();
        vector<int> getStudentIDs();

        // mutators
        void setID(int id);
        void setName(string name);
        void setLevel(string level);
        void setDepartment(string department);
        void setStudentIDs(vector<int> *sid);

    private:
        int id;
        string name;
        string level;
        string department;
        vector<int> *studentIDs;
};

#endif
#ifndef FACULTYRECORDS_H
#define FACULTYRECORDS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FacultyRecords {

    public:

        FacultyRecords();
        FacultyRecords(string facultyName, int facultyID, string facultyLevel, string facultyDepartment, vector<int> *facultyAdviseeIDs);
        ~FacultyRecords();

        //getters
        int getFacultyID();
        vector<int> getFacultyAdviseeIDs();
        string getFacultyName();
        string getFacultyLevel();
        string getFacultyDepartment();

        //setters
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
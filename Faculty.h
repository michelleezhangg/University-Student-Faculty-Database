#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include "FacultyRecords.h"

#include <vector>

class Faculty : public Person {

    public:

        Faculty();
        Faculty(string name, int id, string level, string department);
        ~Faculty();

        //getters
        string getName();
        int getID();
        string getLevel();
        string getDepartment();
        vector<int> getAdviseeIDs();
        int getNumAdvisees();

        //setters
        void setName(string fName);
        void setID(int fID);
        void setLevel(string fLevel);
        void setDepartment(string fDepartment);
        void setAdviseeID(vector<int> *aIDs);
        void setNumAdvisees(int na);

        void addAdvisee(int id);
        void removeAdvisee(int id);

        string getAdviseeID();
        string getFacultyInfo();
        friend ostream& operator << (ostream &os, const Faculty &f);

        string department;
        int numAdvisees;
        vector<int> *adviseeIDs;

        FacultyRecords *facultyRecord;


};

#endif
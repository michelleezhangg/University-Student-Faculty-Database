#ifndef FACULTYRECORDS_H // header guard
#define FACULTYRECORDS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FacultyRecords {
    public:
        FacultyRecords(); // default constructor
        FacultyRecords(int id, string name, string level, string department); // overloaded constructor
        ~FacultyRecords(); // destructor

        // accessors
        int getID();
        string getName();
        string getLevel();
        string getDepartment();

        // mutators
        void setID(int id);
        void setName(string name);
        void setLevel(string level);
        void setDepartment(string department);

    private:
        int id;
        string name;
        string level;
        string department;
        vector<int> *studentIDs;
};

#endif
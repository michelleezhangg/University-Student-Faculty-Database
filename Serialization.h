#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <exception>

#include "RollBack.h"
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Serialization {

    public:
        Serialization(); // default constructor
        ~Serialization(); // destructor

        void writeToStudentFile(TreeNode<Student> *student, BST<Student> *masterStudent);
        void writeToFacultyFile(TreeNode<Faculty> *faculty, BST<Faculty> *masterFaculty);

        void readToStudentDB(BST<Student> *studentDB);
        void readToFacultyDB(BST<Faculty> *facultyDB);

        // serialize
        void serialize(BST<Student> *studentDB, BST<Faculty> *facultyDB);

};

#endif
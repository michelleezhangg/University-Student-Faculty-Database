#ifndef DATABASE_H
#define  DATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"

class Database {
    public:
        Database(); // default constructor
        ~Database(); // destructor
    private:
        BST<Student> *studentDB;
        BST<Faculty> *facultyDB;
};

#endif
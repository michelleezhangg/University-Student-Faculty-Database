#ifndef ROLLBACK_H
#define ROLLBACK_H

#include "GenStack.h"
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

class RollBack {
    public:
        RollBack(); // default constructor
        ~RollBack(); // destructor

    private:
        GenStack< BST<Student> > *studentDBHistory;
        GenStack< BST<Faculty> > *facultyDBHistory;
};

#endif
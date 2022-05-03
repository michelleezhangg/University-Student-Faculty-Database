#include "RollBack.h"

RollBack::RollBack() { // default constructor
    studentDBHistory = new GenStack < BST<Student> >();
    facultyDBHistory = new GenStack < BST<Faculty> >();
}
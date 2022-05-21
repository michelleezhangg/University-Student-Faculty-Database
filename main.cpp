/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This file contains the main method for Assignment 6.
*/

#include "Database.h"

int main(int argc, char** argv) {
    Database *db = new Database();
    db->run();

    delete db;
    return 0;
}
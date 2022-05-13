#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

class FileProcessor {
    public:
        FileProcessor(); // default constructor
        ~FileProcessor(); // destructor

        bool filesExist();
        void readFiles(BST<Student> *students, BST<Faculty> *faculty);
};

#endif
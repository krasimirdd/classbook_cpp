//
// Created by kdimitrov on 11/9/2019.
//

#ifndef STUDENTS_UTIL_H
#define STUDENTS_UTIL_H


#include <string>
#include <iostream>

class Util {
public:
    void toFile(const std::string& info);

    int menu();

    bool isValid(int arg);

};


#endif //STUDENTS_UTIL_H

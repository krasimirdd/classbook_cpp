//
// Created by kdimitrov on 11/9/2019.
//

#ifndef STUDENTS_STUDENT_H
#define STUDENTS_STUDENT_H

#include <string>
#include <iostream>
#include "CMakeFiles/Grades.h"

using namespace std;

class Student {
    string name;
    string faculty_name;
    string faculty_id;
    string group;
    Grades grades;
public:
    Student();

    ~Student();

    void setName();

    string getName() { return name; }

    void setFactultyName();

    string getFactultyName() { return faculty_name; }

    void setFactultyId();

    string getFacultyId() { return faculty_id; }

    void setGroup();

    string getGroup() { return group; }

    void setGrades();

    Grades getGrades() { return grades; }

    string getInfo();

};

#endif //STUDENTS_STUDENT_H

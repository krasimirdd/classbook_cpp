//
// Created by kdimitrov on 11/9/2019.
//

#ifndef STUDENTS_GRADES_H
#define STUDENTS_GRADES_H

class Grades {

    int grades_1[5] = {};
    int grades_2[5] = {};
public:
    Grades(int array_1[], int array_2[]);

    Grades();

    ~Grades();

    void setGrades(int array_1[], int array_2[]);

    int *getGrades(int term);

    double getAverageRate(int term);

    int getMax(int term);

    int getMin(int term);

    std::string getStatistics(int term);

//    auto func(int term) -> int (*)[5];
};

#endif //STUDENTS_GRADES_H

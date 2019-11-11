//
// Created by kdimitrov on 11/9/2019.
//

#include <string>
#include "Grades.h"

Grades::Grades(int array_1[], int array_2[]) {
    setGrades(array_1, array_2);
}

Grades::Grades() = default;

Grades::~Grades() = default;

void Grades::setGrades(int array_1[], int array_2[]) {
    memcpy(grades_1, array_1, 5 * sizeof(int));
    memcpy(grades_2, array_2, 5 * sizeof(int));
}

double Grades::getAverageRate(int term) {
    int *array_ptr = getGrades(term);
    int curr = 0;

    for (int i = 0; i < 5; i++) {
        int el = *(array_ptr + i);
        curr += el;
    }

    return curr / 5.000;
}

int Grades::getMax(int term) {
    int *array_ptr = getGrades(term);
    int max = INT_MIN;
    for (int i = 0; i < 5; i++) {
        int el = *(array_ptr + i);
        if (el > max) {
            max = el;
        }
    }
    return max;
}

int Grades::getMin(int term) {
    int *array_ptr = getGrades(term);
    int min = INT_MAX;
    for (int i = 0; i < 5; i++) {
        int el = *(array_ptr + i);
        if (el < min) {
            min = el;
        }
    }
    return min;
}

std::string Grades::getStatistics(int term) {
    std::string result;
    result += "Average: " + std::to_string(getAverageRate(term)) + "\n";
    result += "Min: " + std::to_string(getMin(term)) + "\n";
    result += "Max: " + std::to_string(getMax(term)) + "\n";

    return result;
}

//auto Grades::func(int term) -> int (*)[5] {
//    if (term == 1) {
//        return &grades_1;
//    } else if (term == 2) {
//        return &grades_2;
//    }
//}

int *Grades::getGrades(int term) {
    if (term == 1) {
        int *ptr = grades_1;
        return ptr;
    } else if (term == 2) {
        int *ptr = grades_2;
        return ptr;
    } else {
        return nullptr;
    }
}

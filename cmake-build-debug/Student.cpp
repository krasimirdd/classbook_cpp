//
// Created by kdimitrov on 11/9/2019.
//

#include "Student.h"

Student::~Student() = default;

Student::Student() {
    setName();
    setFactultyName();
    setFactultyId();
    setGroup();
    setGrades();
}

void Student::setGrades() {
    cout << "Grades 1st term: " << "\n";
    int input_1[5];
    int grade;
    int i = 0;
    for (; i < 5; i++) {
        cout << "grade : ";
        cin >> grade;
        if (grade > 1 && grade < 7) {
            input_1[i] = grade;
        } else {
            cout << "INVALID INPUT" << endl;
            i--;
        }
    }

    cout << "Grades 2nd term: " << "\n";
    int input_2[5];
    i = 0;
    for (; i < 5; i++) {
        cout << "grade : ";
        cin >> grade;
        if (grade > 1 && grade < 7) {
            input_2[i] = grade;
        } else {
            cout << "INVALID INPUT" << endl;
            i--;
        }
    }
    grades = Grades(input_1, input_2);
}

void Student::setGroup() {
    cout << "Group: ";
    cin >> group;
}

void Student::setFactultyId() {
    cout << "Faculty number: ";
    cin >> faculty_id;
}

void Student::setFactultyName() {
    cout << "Faculty name: ";
    cin >> faculty_name;
}

void Student::setName() {
    cout << "Student Name: ";
    cin >> name;
}


string Student::getInfo() {
    string result;

    result += "\nName: " + getName() + "\n";
    result += "Faculty: " + getFactultyName() + "\n";
    result += "FacultyNumber: " + getFacultyId() + "\n";
    result += "Group: " + getGroup() + "\n";
    result += "1st term : \n";
    result += "\t" + grades.getStatistics(1);
    result += "2nd term : \n";
    result += "\t" + grades.getStatistics(2);

    return result;
}
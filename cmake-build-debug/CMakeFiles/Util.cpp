//
// Created by kdimitrov on 11/9/2019.
//


#include <string>
#include <fstream>
#include "Util.h"

void Util::toFile(const std::string& info) {
    std::ofstream outfile("test.txt");

    outfile << info << std::flush;

    outfile.close();
}

int Util::menu() {
    int option;
    std::cout << "Choose an option" << std::endl;
    std::cout << "1. Add students" << std::endl;
    std::cout << "2. Statistics for all groups" << std::endl;
    std::cout << "3. Statistics for specific group" << std::endl;
    std::cout << "4. Grades of all students" << std::endl;
    std::cout << "5. Grades of students for specific group" << std::endl;
    std::cout << "6. exit" << std::endl;

    std::cin >> option;
    return option;
}

bool Util::isValid(int arg) {
    return arg == 1 || arg == 2 || arg == 3 || arg == 4 || arg == 5;
}

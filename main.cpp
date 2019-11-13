#include <iostream>
#include <list>
#include <algorithm>
#include "cmake-build-debug/Student.h"
#include "cmake-build-debug/CMakeFiles/Util.h"

void calculateValues(const string &group, int term, Student &student, int &max, int &min);

string extractResult(double max, double min, const string &group, int term);

int main() {
    std::cout << "Welcome!" << std::endl;

    int option = Util::menu();
    list<Student> storage;
    list<string> groups;

    do {

        if (option == 1) {

            cout << "How many students will add? [max 10]\n" << endl;
            int count;
            cin >> count;
            for (int i = 0; i < count && count < 11; i++) {
                cout << "\n\n Add entry \n \n" << endl;
                auto *student = new Student();
                storage.emplace_front(*student);
                groups.push_front(student->getGroup());
            }

        } else if (option == 2) {

            cout << "For average rate of every group enter term [1 | 2]" << endl;
            string result;
            int term;
            cin >> term;
            if (term != 1 && term != 2) {
                return 22;
            }
            groups.unique();

            result += "\n------------------------------- \naverage rate of every group for term " + to_string(term) +
                      " : \n";
            for (const string &group : groups) {

                double total_success_for_group = 0;
                int students_count_in_group = 0;

                for (Student &student : storage) {
                    if (student.getGroup() == group) {
                        total_success_for_group += student.getGrades().getAverageRate(term);
                        students_count_in_group++;
                    }
                }
                result +=
                        "\tGroup " + group + " - " + to_string(total_success_for_group / students_count_in_group) +
                        "\n";
            }

            Util::toFile(result);
            cout << result;

        } else if (option == 3) {

            cout << "For MIN and MAX rate enter group number and term [1 | 2]" << endl;
            string result_3;
            string group;
            int term;
            cin >> group;
            cin >> term;

            if (term != 1 && term != 2) {
                return 22;
            }
            list<Student> temp_storage_3;

            double avg_max = 1;
            double avg_min = 7;
            int end = storage.size();
            for (int j = 0; j < end; j++) {
                Student thiz = storage.back();

                temp_storage_3.emplace_back(thiz);
                storage.pop_back();

                double curr_avr;
                if (thiz.getGroup() == group) {
                    curr_avr = thiz.getGrades().getAverageRate(term);
                    if (curr_avr >= avg_max) {
                        avg_max = curr_avr;
                    }
                    if (curr_avr <= avg_min) {
                        avg_min = curr_avr;
                    }
                }
            }

            result_3 = extractResult(avg_max, avg_min, group, term);
            cout << result_3;
            Util::toFile(result_3);

            storage.assign(temp_storage_3.begin(), temp_storage_3.end());
            temp_storage_3.erase(temp_storage_3.begin(), temp_storage_3.end());

        } else if (option == 4) {

            list<Student> temp_storage_4;
            int students_count = storage.size();
            for (int j = 0; j < students_count; j++) {
                Student thiz = storage.back();

                temp_storage_4.emplace_back(thiz);
                storage.pop_back();

                cout << thiz.getInfo();
                cout << "----------------------------------------------" << endl;
                Util::toFile(thiz.getInfo());
            }
            storage.assign(temp_storage_4.begin(), temp_storage_4.end());
            temp_storage_4.erase(temp_storage_4.begin(), temp_storage_4.end());


        } else if (option == 5) {

            cout << "Enter group number and term [1 | 2]" << endl;
            string result_5;
            string group;
            int term;
            cin >> group;
            cin >> term;
            if (term != 1 && term != 2) {
                return 22;
            }
            groups.unique();
            if ((std::find(groups.begin(), groups.end(), group) != groups.end())) {

                result_5 += "Information for group for term " + to_string(term) +" : \n";
                for (const string &gr : groups) {
                    if (group == gr) {
                        result_5 += "\tGroup " + gr + ": \n";

                        for (Student &std : storage) {
                            if (std.getGroup() == gr) {
                                result_5 += std.getInfo();
                            }
                        }
                    }
                }

                cout << result_5;
                Util::toFile(result_5);
            } else {
                cout << "Error! Could not find such a group in the records\n\n";
            }

        } else if (option == 6) {
            cout << "\n ---------- HAVE A NICE DAY ---------\n";
            return 0;

        } else {

            cout << "Invalid option!" << endl;

        }

        option = Util::menu();
    } while (true);
}

string extractResult(double max, double min, const string &group, int term) {
    string result;
    result = "";
    result += "Max success rate for group " + group + " for semester " + to_string(term) + " is " +
              to_string(max) + "\n";
    result += "Min success rate for group " + group + " for semester " + to_string(term) + " is " +
              to_string(min) + "\n";
    result += "----------------------------------------------\n";
    return result;
}

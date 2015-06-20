//
// Created by pan on 15-4-28.
//

#ifndef CANDCPP_SOURCE_FILE_H
#define CANDCPP_SOURCE_FILE_H

#include <string>

using namespace std;

class Employee{
private:
    string name;
    int level;
public:
    Employee(char * name, const int level): name(name), level(level){};
    string getName();
    int getLevel();
    void setLevel(int);
    int calcSalary();
};
#endif //CANDCPP_SOURCE_FILE_H


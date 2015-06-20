//
// Created by pan on 15-4-28.
//

#include "main.h"
#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;



class Sale : Employee{};



int main(){
    Employee employee("Stone", 8);
    Sale sale("RicterZ", 9);
    cout << "Name:" << sale.getName() << endl;
    cout << "Rank:" << sale.getLevel() << endl;
    cout << "Salary" << sale.calcSalary() << endl;
    cout << "Name:" << employee.getName() << endl;
    cout << "Rank:" << employee.getLevel() << endl;
    cout << "Salary:" << employee.calcSalary() << endl;
    return 0;
};
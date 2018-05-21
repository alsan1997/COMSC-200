// Lab 5a, Date.h, Date.cpp, Employee.h, and Employee.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <string>
using std::string;

#include "Date.h"

class Employee
{
public:
  Employee(const string&, const string&,
    const Date&, const Date&);
  void print() const;
  ~Employee(); // provided to confirm destruction
private:
  string firstName; // composition: member object
  string lastName; // composition: member object
  const Date birthDate; // composition: member object
  const Date hireDate; // composition: member object
}; // end class employee

#endif // EMPLOYEE_H_INCLUDED

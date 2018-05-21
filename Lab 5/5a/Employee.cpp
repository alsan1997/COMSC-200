// Lab 5a, Date.h, Date.cpp, Employee.h, and Employee.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::endl;
using std::cout;

#include <string>
using std::string;

#include "Employee.h" // Employee class definition

#include "Date.h" // Date class definition

// constructor uses member initializer list to pass initializer
// values to constructors of member objects
Employee::Employee(const string& first, const string& last,
  const Date& dateOfBirth, const Date& dateOfHire)
  : firstName(first), // initialize firstname
    lastName(last), // initialize lastname
    birthDate(dateOfBirth), // initialize birthdate
    hireDate(dateOfHire) // initialize hiredate
{
  // output Employee object to show when constructor is called
  cout << "Employee object constructor: "
    << firstName << ' ' << lastName << endl;
} // end Employee constructor

// print Employee object
void Employee::print() const
{
  cout << lastName << ", " << firstName << " Hired: ";
  hireDate.print();
  cout << " Birthday: ";
  birthDate.print();
  cout << endl;
} // end function print

// output Employee object to show when its destructor is called
Employee::~Employee()
{
  cout << "Employee object destructor: "
    << lastName << ", " << firstName << endl;
} // end ~Employee destructor

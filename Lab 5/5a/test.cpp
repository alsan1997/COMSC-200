// Lab 5a, Date.h, Date.cpp, Employee.h, and Employee.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"
#include "Employee.h"

void outputIO();

int main()
{
  outputIO();
  Date birth(7, 24, 1949);
  Date hire(3, 12, 1988);
  Employee manager("Bob", "Blue", birth, hire);

  cout << endl;
  manager.print();

  cout << "\nTest Date constructor with invalid values:\n";
  Date lastDayOff(14, 35, 1994);
  cout << endl;
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 5a, Date.h, Date.cpp, Employee.h, and Employee.cpp\n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

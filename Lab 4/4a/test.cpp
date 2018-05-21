// Lab 4a, Time.h and Time.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

void outputIO();

int main()
{
  // call identifying output
  outputIO();

  Time t;

  t.printUniversal();
  cout << endl;
  t.printStandard();


}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 4a, Time.h and Time.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

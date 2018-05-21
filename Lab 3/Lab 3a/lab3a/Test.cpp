#include <iostream>
using std::cout;
using std::endl;

#include "SalesPerson.h"

void outputIO();

int main()
{
  // call identifying output
  outputIO();

  SalesPerson t;

  t.getSalesFromUser();
  t.printAnnualSales();

}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 3a, SalesPerson.h and SalesPerson.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

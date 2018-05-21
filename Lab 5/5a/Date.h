// Lab 5a, Date.h, Date.cpp, Employee.h, and Employee.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
public:
  static const int monthsPerYear = 12; // number of months in a year
  Date(int = 1, int = 1, int = 1900); // default constructor
  void print() const; // print date in mm/dd/yy format
  ~Date(); // provided to confirm destruction order
private:
  int month; // 1-12 (Jan-Dec)
  int day; // 1-31 (based on month)
  int year; // any year

  // utility function to check if day is proper for month and year
  int checkDay(int) const;
}; // end class date

#endif // DATE_H_INCLUDED

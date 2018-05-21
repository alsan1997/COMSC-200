// Lab 10a, Date.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
using std::ostream;

class Date
{
  private:
    int month;
    int day;
    int year;
static const int days[]; // arrays of days per month
    void helpIncrement(); // utility function for incrementing date
  public:
    Date(int m = 1, int = 1, int y = 1900); // default constructor
    void setDate(int, int, int); // set month, day, year
    Date& operator++(); // prefix increment operator
    Date operator++(int); // postfix increment operator
    const Date& operator+=(int); // add days, modify object
    static bool leapYear(int); // is date in a leap year?
    bool endOfMonth(int) const; // is date at the end of month?
    friend ostream& operator<<(ostream&, const Date&);



}; // end class date

#endif // DATE_H_INCLUDED

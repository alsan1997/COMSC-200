// Lab 2a, MyTime.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;

class Times
{
public:
  Times(); // constructor
  void setTimes(int, int, int); // set hour minutes & second
  void printUniversal(); // print time in universal-time format
  void printStandard(); // print time in standard-time format
private:
  int hour; // 0-23 (24-hour clock format)
  int minute; // 0-59
  int second; // 0-59
}; // end class Times

// Time constructor initializes each data member to zero
// Ensures all Time objects start in a consistent state.

Times::Times()
{
  hour = minute = second = 0;
} // end Time constructor

// Set new time value using universal time; ensure that
// the data remains consistent by setting invalid values to zero
void Times::setTimes(int h, int m, int s)
{
  hour = (h>=0 && h < 24) ? h : 0; // validate hour;
  minute = (m>=0 && m < 60) ? m : 0; // validate minute;
  second = (s>=0 && s < 60) ? s : 0; // validate second;
}

// print time in universal-time format (HH::MM::SS)
void Times::printUniversal()
{
  cout << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute << ":" << setw(2) << second;
} // end function printUniversal

// print Time in standard-time format (HH::MM:SS AM OR PM)
void Times::printStandard()
{
  cout << ((hour == 0 || hour == 12) ? 12 : hour %  12) << ":"
    << setfill('0') << setw(2) << minute << ":" << setw(2)
    << second << (hour < 12 ? " AM" : " PM");
} // end function printStandard

void outputIO();

int main()
{
  Times t; // instantiate object t of class Times

  // call identifying output
  outputIO();

  // output Time object t's initial values
  cout << "The initial universal time is ";
  t.printUniversal(); // 00:00:00
  cout << "\nThe initial standard time is ";
  t.printStandard(); // 12:00:00 AM

  t.setTimes(13,27,6); // change time

  // output Time object t's new values
  cout << "\n\nUniversal time after setTime is ";
  t.printUniversal(); // 13:27:06
  cout << "\nStandard time after setTime is ";
  t.printStandard(); // 1:27:06 PM

  t.setTimes(99,99,99); // attempt invalid settings

  // output t's values after specifying invalid values
  cout << "\n\nAfter attempting invalid settings:"
    << "\nUniversal time: ";
  t.printUniversal(); // 00:00:00
  cout << "\nStandard time: ";
  t.printStandard(); // 12:00:00 AM
  cout << endl;
} // end main

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 2a, MyTime.cpp\n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

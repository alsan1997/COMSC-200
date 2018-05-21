// Lab 4a, Time.h and Time.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time
{
public:
  Time(int = 0, int = 0, int = 0); // default constructor

  // set functions
  void setTime(int, int, int); // set time
  void setHour(int); // set hour
  void setMinute(int); // set minute
  void setSecond(int); // set second

  // get functions (normally declared const)
  int getHour() const {return hour;} // return hour
  int getMinute() const; // return minute
  int getSecond() const; // return second

  // print functions (normally declared const)
  void printUniversal() const; // print universal time
  void printStandard() const; // print standard time

private:
  int hour; // 0-23 (24-hour clock format)
  int minute; // 0-59
  int second; // 0-59
}; // end class Time
#endif // TIME_H_INCLUDED

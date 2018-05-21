// Lab 6a, Time.h and Time.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Time.h"

Time::Time(int hr, int mins, int sec)
{
  setTime(hr, mins, sec);
} // end Time constructor

// set values of hour, minute, and second
Time &Time::setTime(int h, int m, int s) // note Time & return
{
  setHour(h);
  setMinute(m);
  setSecond(s);
  return *this; // enables cascading
} // end function setTime

// set hour value
Time &Time::setHour(int h) // note Time & return
{
  hour = (h >= 0 && h < 24) ? h : 0; // validate hour
  return *this; // enables cascading
}

// set minute value
Time &Time::setMinute(int m) // note Time & return
{
  minute = (m >= 0 && m < 60) ? m : 0; // validate minute
  return *this; // enables cascading
}

// set second value
Time &Time::setSecond(int s) // note Time & return
{
  second = (s >= 0 && s < 60) ? s : 0; // validate second
  return *this; // enables cascading
}

// get Hour value
int Time::getHour() const
{
  return hour;
} // end function getHour

// get minute value
int Time::getMinute() const
{
  return minute;
} // end function getMinute

// get second value
int Time::getSecond() const
{
  return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
  cout << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute << ":" << setw(2) << second;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
  cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
    << ":" << setfill('0') << setw(2) << minute
    << ":" << setw(2) << second << (hour < 12 ? "AM " : " PM");
} // end function printStandard

// Lab 8a, PhoneNumber.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef PHONENUMBER_H_INCLUDED
#define PHONENUMBER_H_INCLUDED

#include <iostream>
using std::ostream;
using std::istream;

#include <string>
using std::string;

class PhoneNumber
{
  private:
    string areaCode; // 3-digit area code
    string exchange; // 3-digit exchange
    string line; // 4-digit line
  public:
  friend ostream& operator<<(ostream&, const PhoneNumber&);
  friend istream& operator>>(istream&, PhoneNumber&);
}; // end class PhoneNumber

#endif // PHONENUMBER_H_INCLUDED

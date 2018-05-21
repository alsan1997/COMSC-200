// Lab 9a, Array.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>
using std::ostream;
using std::istream;

class Array
{
  private:
    int sizee; // pointer-based array size
    int *ptr; // pointer to first element of pointer based-array
  public:
    Array(int=10); // default constructor
    Array(const Array&); // copy constructor
    ~Array(); // destructor
    int getSize() const; // return size

    const Array& operator=(const Array&); // assignment operator
    bool operator==(const Array&) const; // equality operator

    // inequality operator; returns opposite of == operator
    bool operator != (const Array& right) const
    {
      return ! (*this == right); // invokes Array::operator==
    } // end function operator !=

    // subscript operator for non-const objects returns modifiable lvalue
    int& operator[] (int);

    // subscript operator for const objects returns rvalue
    int operator[](int) const;
    friend ostream& operator<<(ostream&, const Array&);
    friend istream& operator>>(istream&, Array&);
}; // end class Array

#endif // ARRAY_H_INCLUDED

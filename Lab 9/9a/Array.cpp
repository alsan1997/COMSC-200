// Lab 9a, Array.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::ostream;
using std::istream;
using std::endl;
using std::cerr;

#include <iomanip>
using std::setw;

#include <cstdlib>

#include "Array.h"

Array::Array(int arraySize)
{
  sizee = (arraySize > 0 ? arraySize : 10); // validate arraySize
  ptr = new int[sizee]; // create space for pointer-based array

  for(int i = 0; i < sizee; i++)
    ptr[i] = 0; // set pointer-based array element

} // end Array default constructor

 // copy constructor for class Array;
 // must receive a reference to prevent infinite recursion
Array::Array(const Array& arrayToCopy):
sizee(arrayToCopy.sizee)
{
  ptr = new int[sizee]; // create space for pointer-based array

  for(int i = 0; i < sizee; i++)
    ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor

// destructor for class Array
Array::~Array()
{
  delete[] ptr;  // release pointer-based array space
}

// return number of elements of Array
int Array::getSize() const
{
  return sizee; // number of elements in Array
} // end function getSize

// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
const Array& Array::operator=(const Array& right)
{
  if(&right != this) // avoid self-assignment
  {
    // for Arrays of different sizes, deallocate original
    // left-sided array, then allocate new left-side array
    if(sizee != right.sizee)
    {
      delete[] ptr;  // release space
      sizee = right.sizee; // resize this object
      ptr = new int [sizee]; // create space for array copy
    } // end inner if

    for(int i = 0; i < sizee; i++)
      ptr[i] = right.ptr[i]; // copy array into object
  } // end outer if

  return *this; // enables x = y = z, for example
} // end function operator=

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==(const Array& right) const
{
  if(sizee != right.sizee)
    return false; // arrays of different number of elements

  for(int i = 0; i < sizee; i++)
    if(ptr[i] != right.ptr[i]) return false; // Arrays contents are not equal

  return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int& Array::operator[](int subscript)
{
  // check for subscript out-of-range error
  if(subscript < 0 || subscript >= sizee)
  {
    cerr << "\nError: Subscript " << subscript
      << " out of range" << endl;
    exit(1); // terminate program; subscript out of range
  } // end if

  return ptr[subscript];
} // end function operator[]

// overloaded subscript operator for const Arrays;
// const reference return creates an rvalue
int Array::operator[](int subscript) const
{
  // check for subscript out-of-range error
  if(subscript < 0 || subscript >= sizee)
  {
    cerr << "\nError: Subscript " << subscript
      << " out of range" << endl;
    exit(1); // terminate program; subscript out of range
  } // end if

  return ptr[subscript];
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
istream& operator>>(istream& input, Array& a)
{
  for(int i = 0; i < a.sizee; i++)
    input >> a.ptr[i];

  return input; // enables cin >> x >> y
} // end function operator>>

// overloaded output operator for class Array
ostream& operator<<(ostream& output, const Array& a)
{
  int i;

  // output private ptr-based array
  for(i = 0; i < a.sizee; i++)
  {
    output << setw(2) << a.ptr[i];

    if((i + 1) % 4 == 0 ) // 4 numbers per row of output
        output << endl;
  } // end for

  if(i % 4 != 0 ) // end last line of output
    output << endl;

  return output; // enables cout << x << y;
} // end function operator<<




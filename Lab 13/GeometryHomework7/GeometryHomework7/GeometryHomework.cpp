// Lab 13, GeometryHomework.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "stdafx.h"

#include "GeometryHomework.h"

#include <iostream>
using std::endl;

#include <iomanip>
using std::setprecision;

#include <cmath>

#include <cstdlib>

const double PI = 4 * atan(1.0);

Shape::Shape(const char* const token[]):
a1(token[1] != 0 ? atof(token[1]) : 0),
b2(token[2] != 0 ? atof(token[2]) : 0),
c3(token[3] != 0 ? atof(token[3]) : 0){}

// newly defined output stream manipulators
ostream& reset(ostream& out) // requires iostream, using ostream
{
  out.unsetf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(6); // requires iostream and iomanip, using setprecision
  return out;
}

ostream& set(ostream& out) // requires iostream, using ostream
{
  out.setf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(2); // requires iostream and iomanip, using setprecision
  return out;
}

// overloaded stream insertion operator
ostream& operator<<(ostream& out, const Shape* sh)
{
  sh->output(out);
  return out;
}

void Square::output(ostream& out) const
{
  // Set area & perimeter to virtual void output(ostream&) const = 0;2 decimal place
  out << set;

  // Output area and perimeter
  out << "Area=" << a1 * a1;
  out << ", Perimeter=" << 4 * a1;

  // Set decimal place to default
  out << reset;
}

void comsc::Rectangle::output(ostream& out) const
{
  // Set area & perimeter to 2 decimal place
  out << set;

  // Output area and perimeter
  out << "Area=" << a1 * b2;
  out << ", Perimeter=" << (2 * a1) + (2 * b2);

  // Set decimal place to default
  out << reset;
}

void Circle::output(ostream& out) const
{
  // Set area & perimeter to 2 decimal place
  out << set;

  // Output area and perimeter
  out << "Area=" << PI * a1 * a1;
  out << ", Perimeter=" << PI * (2 * a1);

  // Set decimal place to default
  out << reset;
}

void Cube::output(ostream& out) const
{
  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << "Surface Area=" << 6 * (a1 * a1);
  out << ", Volume=" << a1 * a1 * a1;
 
  // Set decimal place to default
  out << reset;
}

void Prism::output(ostream& out) const
{
  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << "Surface Area=" << (2 * b2 * c3) + (2 * b2 * a1) +
    (2 * c3 * a1);
  out << ", Volume=" << (a1 * b2 * c3);

  // Set decimal place to default
  out << reset;
}

void Cylinder::output(ostream& out) const
{
  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << "Surface Area=" << (2 * PI * a1 * a1) +
    (PI * b2 * (2 * a1));
  out << ", Volume=" << (PI * a1 * a1 * b2);

  // Set decimal place to default
  out << reset;
}

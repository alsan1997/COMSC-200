// Lab 13, GeometryHomework.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef GEOMETRYHOMEWORK_H_INCLUDED
#define GEOMETRYHOMEWORK_H_INCLUDED

#include <iostream>
using std::ostream;
using std::ios;

#include <sstream>
using std::ostringstream;

#include <string>
using std::string;

// abstract class, Polymorphism method
class Shape
{
public:
  virtual void output(ostream&) const = 0;
  virtual ~Shape(){}
  Shape(const char* const[]);
protected:
  const double a1;
  const double b2;
  const double c3;
};
ostream& operator<<(ostream&, const Shape*);

struct Square : public Shape
{
  Square(const char* const token[]):Shape(token){} // inheriting side from Shape(grandparents)
  void output(ostream&) const;
};

namespace comsc
{
  struct Rectangle : public Shape
  {
    Rectangle(const char* const token[]):Shape(token){} // inheriting length and width from Shape(grandparents)
    void output(ostream&) const;
  };
}

struct Circle : public Shape
{
  Circle(const char* const token[]):Shape(token){} // inheriting radius from Shape(grandparents)
  void output(ostream&) const;
};

struct Cube : public Square
{
  Cube(const char* const token[]):Square(token){} // inheriting side from Square(parents)
  void output(ostream&) const;
};

struct Prism : public comsc::Rectangle
{
  Prism(const char* const token[]):comsc::Rectangle(token){} // inheriting length, height and width from Rectangle(parents)
  void output(ostream&) const;
};

struct Cylinder : public Circle
{
  Cylinder(const char* const token[]):Circle(token){} // inheriting radius and height from Circle(parents)
  void output(ostream&) const;
};

#endif // GEOMETRYHOMEWORK_H_INCLUDED

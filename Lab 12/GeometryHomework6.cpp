// Lab 12, GeometryHomework6.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

// libraries
#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstring>
using std::strcmp;

#include <iomanip>
using std::setprecision;

#include <cstdlib>

#include <cmath>

#include<vector>
using std::vector;

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 4 * atan(1.0);

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

struct Square : public Shape
{
  Square(const char* const token[]):Shape(token){} // inheriting side from Shape(grandparents)
  void output(ostream&) const;
};

void Square::output(ostream& out) const
{
  out << "SQUARE side=" << a1;

  // Set area & perimeter to virtual void output(ostream&) const = 0;2 decimal place
  out << set;

  // Output area and perimeter
  out << " area=" << a1 * a1;
  out << " perimeter=" << 4 * a1;
  out << endl;

  // Set decimal place to default
  out << reset;
}

struct Rectangle : public Shape
{
  Rectangle(const char* const token[]):Shape(token){} // inheriting length and width from Shape(grandparents)
  void output(ostream&) const;
};

void Rectangle::output(ostream& out) const
{
  out << "RECTANGLE length=" << a1 << " width=" << b2;

  // Set area & perimeter to 2 decimal place
  out << set;

  // Output area and perimeter
  out << " area=" << a1 * b2;
  out << " perimeter=" << (2 * a1) + (2 * b2);
  out << endl;

  // Set decimal place to default
  out << reset;
}

struct Circle : public Shape
{
public:
  Circle(const char* const token[]):Shape(token){} // inheriting radius from Shape(grandparents)
  void output(ostream&) const;
};

void Circle::output(ostream& out) const
{
  out << "CIRCLE radius=" << a1;

  // Set area & perimeter to 2 decimal place
  out << set;

  // Output area and perimeter
  out << " area=" << PI * a1 * a1;
  out << " perimeter=" << PI * (2 * a1);
  out << endl;

  // Set decimal place to default
  out << reset;
}

struct Cube : public Square
{
public:
  Cube(const char* const token[]):Square(token){} // inheriting side from Square(parents)
  void output(ostream&) const;
};

void Cube::output(ostream& out) const
{
  out << "CUBE side=" << a1;

  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << " surface area=" << 6 * (a1 * a1);
  out << " volume=" << a1 * a1 * a1;
  out << endl;

  // Set decimal place to default
  out << reset;
}

struct Prism : public Rectangle
{
  Prism(const char* const token[]):Rectangle(token){} // inheriting length, height and width from Rectangle(parents)
  void output(ostream&) const;
};

void Prism::output(ostream& out) const
{
  out << "PRISM length=" << a1 << " width=" << b2
    << " height=" << c3;

  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << " surface area=" << (2 * b2 * c3) + (2 * b2 * a1) +
    (2 * c3 * a1);
  out << " volume=" << (a1 * b2 * c3);
  out << endl;

  // Set decimal place to default
  out << reset;
}

struct Cylinder : public Circle
{
  Cylinder(const char* const token[]):Circle(token){} // inheriting radius and height from Circle(parents)
  void output(ostream&) const;
};

void Cylinder::output(ostream& out) const
{
  out << "CYLINDER radius=" << a1 << " height=" << b2;

  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << " surface area=" << (2 * PI * a1 * a1) +
    (PI * b2 * (2 * a1));
  out << " volume=" << (PI * a1 * a1 * b2);
  out << endl;

  // Set decimal place to default
  out << reset;
}

void outputIO();

int main()
{
  // create a file-reading object
  ifstream fin;

  // vector Shape*
  vector<const Shape*> shapes;

  // Call identifying output
  outputIO();

  fin.open("geo.txt"); // open a file
  if (!fin.good())
    return 1; // exit if file not found

  // read each line of the file
  while (!fin.eof())
  {
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);

    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index

    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }

      // If token[0] == SQUARE
      if(strcmp(token[0], "SQUARE") == 0)
      {
        // dynamic memory allocation
        const Square* const s = new Square(token);

        // insert data s to vector<Shape*> shapes
        shapes.push_back(s);
      }

      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        // dynamic memory allocation
        const Rectangle* const r = new Rectangle(token);

        // insert data r to vector<Shape*> shapes
        shapes.push_back(r);

      }

      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        // dynamic memory allocation
        const Circle* const c = new Circle(token);

        // insert data c to vector<Shape*> shapes
        shapes.push_back(c);
      }

      else if(strcmp(token[0], "CUBE") == 0)
      {
        // dynamic memory allocation
        const Cube* const cu = new Cube(token);

        // insert data cu to vector<Shape*> shapes
        shapes.push_back(cu);
      }

      else if(strcmp(token[0], "PRISM") == 0)
      {
        // dynamic memory allocation
        const Prism* const p = new Prism(token);

        // insert data p to vector<Shape*> shapes
        shapes.push_back(p);
      }

      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        // dynamic memory allocation
        const Cylinder* const cl = new Cylinder(token);

        // insert data cl to vector<Shape*> shapes
        shapes.push_back(cl);
      }

      // else token[0] is not above choice, output saying invalid object
      else
        cout << token[0] << " is an invalid object" << endl;
    }
  }

  // close file
  fin.close();

  // traversing loop then output it using vector
  // before, could use if statements or switch
  vector<const Shape*>::const_iterator it; // const iterator (read only pointer)
  for(it = shapes.begin(); it != shapes.end(); it++)
  {
    cout << *it;
  }

  // deallocation loop using vector
  // before, could use if statements or switch
  for(it = shapes.begin(); it != shapes.end(); it++)
  {
    delete (*it);
  }
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 12, GeometryHomework6.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

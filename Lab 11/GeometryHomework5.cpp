// Lab 11, GeometryHomework5.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

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

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";
const double PI = 4 * atan(1.0);

class Square
{
public:
  void outputSquare(ostream&) const;
  Square(const char* const []);
protected:
  const double side;
};

class Rectangle
{
public:
  void outputRect(ostream&) const;
  Rectangle(const char* const[]);
protected:
  const double length;
  const double width;
};

class Circle
{
public:
  void outputCircle(ostream&) const;
  Circle(const char* const[]);
protected:
  const double radius;
};

class Cube : public Square
{
public:
  Cube(const char* const token[]):Square(token){} // inheriting side from Square
  void outputCube(ostream&) const;
};

class Prism : public Rectangle
{
public:
  Prism(const char* const token[]):Rectangle(token), // inheriting length and width from Rectangle
  height(token[3] != 0 ? atof(token[3]) : 0){}
  void outputPrism(ostream&) const;
private:
  const double height;
};

class Cylinder : public Circle
{
public:
  Cylinder(const char* const token[]):Circle(token), // inheriting radius from Rectangle
  height(token[2] != 0 ? atof(token[2]) : 0){}
  void outputCylinder(ostream&) const;
private:
  const double height;
};

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

// check if token[1] exist
Square::Square(const char* const token[]):
side(token[1] != 0 ? atof(token[1]) : 0){}

void Square::outputSquare(ostream& out) const
{
  out << "SQUARE side=" << side;

  // Set area & perimeter to 2 decimal place
  out << set;

  // Output area and perimeter
  out << " area=" << side * side;
  out << " perimeter=" << 4 * side;
  out << endl;

  // Set decimal place to default
  out << reset;
}

// check if token[1], token[2] exist
Rectangle::Rectangle(const char* const token[]):
length(token[1] != 0 ? atof(token[1]) : 0),
width(token[2] != 0 ? atof(token[2]) : 0){}

void Rectangle::outputRect(ostream& out) const
{
  out << "RECTANGLE length=" << length << " width=" << width;

  // Set area & perimeter to 2 decimal place
  out << set;

  // Output area and perimeter
  out << " area=" << width * length;
  out << " perimeter=" << (2 * width) + (2 * length);
  out << endl;

  // Set decimal place to default
  out << reset;
}

// check if token[1] exist
Circle::Circle(const char* const token[]):
radius(token[1] == 0 ? 0 : atof(token[1])){}

void Circle::outputCircle(ostream& out) const
{
  out << "CIRCLE radius=" << radius;

  // Set area & perimeter to 2 decimal place
  out << set;

  // Output area and perimeter
  out << " area=" << PI * radius * radius;
  out << " perimeter=" << PI * (2 * radius);
  out << endl;

  // Set decimal place to default
  out << reset;
}


void Cube::outputCube(ostream& out) const
{
  out << "CUBE side=" << side;

  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << " surface area=" << 6 * (side * side);
  out << " volume=" << side * side * side;
  out << endl;

  // Set decimal place to default
  out << reset;
}

void Prism::outputPrism(ostream& out) const
{
  out << "PRISM length=" << length << " width=" << width
    << " height=" << height;

  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << " surface area=" << (2 * width * height) + (2 * width * length) +
    (2 * height * length);
  out << " volume=" << (height * length * width);
  out << endl;

  // Set decimal place to default
  out << reset;
}

void Cylinder::outputCylinder(ostream& out) const
{
  out << "CYLINDER radius=" << radius << " height=" << height;

  // Set surface area & volume to 2 decimal place
  out << set;

  // Output surface area & volume
  out << " surface area=" << (2 * PI * radius * radius) +
    (PI * height * (2 * radius));
  out << " volume=" << (PI * radius * radius * height);
  out << endl;

  // Set decimal place to default
  out << reset;
}

void outputIO();

int main()
{
  // create a file-reading object
  ifstream fin;

  const void* shapes[100];
  int shapeID[100];
  int num = 0;

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

        // insert data s to shapes[] and shapeID[]
        shapes[num] = s;
        shapeID[num] = 1;
        ++num;
      }

      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        // dynamic memory allocation
        const Rectangle* const r = new Rectangle(token);

        // insert data r to shapes[] and shapeID[]
        shapes[num] = r;
        shapeID[num] = 2;
        ++num;
      }

      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        // dynamic memory allocation
        const Circle* const c = new Circle(token);

        // insert ddata c to shapes[] and shapeID[]
        shapes[num] = c;
        shapeID[num] = 3;
        ++num;
      }

      else if(strcmp(token[0], "CUBE") == 0)
      {
        // dynamic memory allocation
        const Cube* const cu = new Cube(token);

        // insert data cu to shapes[] and shapeID[]
        shapes[num] = cu;
        shapeID[num] = 4;
        ++num;
      }

      else if(strcmp(token[0], "PRISM") == 0)
      {
        // dynamic memory allocation
        const Prism* const p = new Prism(token);

        // insert data p to shapes[] and shapeID[]
        shapes[num] = p;
        shapeID[num] = 5;
        ++num;
      }

      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        // dynamic memory allocation
        const Cylinder* const cl = new Cylinder(token);

        // insert data cl to shapes[] and shapeID[]
        shapes[num] = cl;
        shapeID[num] = 6;
        ++num;
      }

      // else token[0] is not above choice, output saying invalid object
      else
        cout << token[0] << " is an invalid object" << endl;
    }
  }

  // close file
  fin.close();

  // traversing loop then output it
  for(int x = 0; x < num; x++)
  {
    if(shapeID[x] == 1 )
      ((Square*)shapes[x])->outputSquare(cout);

    if(shapeID[x] == 2)
      ((Rectangle*)shapes[x])->outputRect(cout);

    if(shapeID[x] == 3)
      ((Circle*)shapes[x])->outputCircle(cout);

    if(shapeID[x] == 4)
      ((Cube*)shapes[x])->outputCube(cout);

    if(shapeID[x] == 5)
      ((Prism*)shapes[x])->outputPrism(cout);

    if(shapeID[x] == 6)
      ((Cylinder*)shapes[x])->outputCylinder(cout);
  }

  // deallocation loop
  for(int y = 0; y < num; y++)
  {
    if(shapeID[y] == 1)
      delete ((Square*)shapes[y]);

    if(shapeID[y] == 2)
      delete ((Rectangle*)shapes[y]);

    if(shapeID[y] == 3)
      delete ((Circle*)shapes[y]);

    if(shapeID[y] == 4)
      delete ((Cube*)shapes[y]);

    if(shapeID[y] == 5)
      delete ((Prism*)shapes[y]);

    if(shapeID[y] == 6)
      delete ((Cylinder*)shapes[y]);
  }
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 11, GeometryHomework5.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

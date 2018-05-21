// Lab 2b, GeometryHomework2.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

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
  void output();
  Square(const char* []);
private:
  double side;
};

class Rectangle
{
public:
  Rectangle(const char* []);
  void output();
private:
  double length;
  double width;
};

class Circle
{
public:
  Circle(const char* []);
  void output();
private:
  double radius;
};

class Cube
{
public:
  void output();
  Cube(const char* []);
private:
  double side;
};

class Prism
{
public:
  void output();
  Prism(const char* []);
private:
  double length;
  double width;
  double height;
};

class Cylinder
{
public:
  void output();
  Cylinder(const char*[]);
private:
  double radius;
  double height;
};

Square::Square(const char* token[])
{
  // check if token[1]
  side = token[1] != 0 ? atof(token[1]) : 0;
}

void Square::output()
{
  cout << "SQUARE side=" << side;

  // Set area & perimeter to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output area and perimeter
  cout << " area=" << side * side;
  cout << " perimeter=" << 4 * side;
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

Rectangle::Rectangle(const char* token[])
{
  // check if token[1]
  length = token[1] != 0 ? atof(token[1]) : 0;

  // check if token[2]
  width = token[2] != 0 ? atof(token[2]) : 0;
}

void Rectangle::output()
{
  cout << "RECTANGLE length=" << length << " width=" << width;

  // Set area & perimeter to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output area and perimeter
  cout << " area=" << width * length;
  cout << " perimeter=" << (2 * width) + (2 * length);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

Circle::Circle(const char* token[])
{
  // check if token[1] exist
  radius = token[1] == 0 ? 0 : atof(token[1]);
}

void Circle::output()
{
  cout << "CIRCLE radius=" << radius;

  // Set area & perimeter to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output area and perimeter
  cout << " area=" << PI * radius * radius;
  cout << " perimeter=" << PI * (2 * radius);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

Cube::Cube(const char* token[])
{
  // check if token[1] exist
  side = token[1] == 0 ? 0 : atof(token[1]);
}

void Cube::output()
{
  cout << "CUBE side=" << side;

  // Set surface area & volume to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output surface area & volume
  cout << " surface area=" << 6 * (side * side);
  cout << " volume=" << side * side * side;
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}


Prism::Prism(const char* token[])
{
  // check if token[1]
  length = token[1] != 0 ? atof(token[1]) : 0;

  // check if token[2]
  width = token[2] != 0 ? atof(token[2]) : 0;

  // check if token[3]
  height = token[3] != 0 ? atof(token[3]) : 0;
}

void Prism::output()
{
  cout << "PRISM length=" << length << " width=" << width
    << " height=" << height;

  // Set surface area & volume to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output surface area & volume
  cout << " surface area=" << (2 * width * height) + (2 * width * length) +
    (2 * height * length);
  cout << " volume=" << (height * length * width);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

Cylinder::Cylinder(const char* token[])
{
  // check if token[1]
  radius = token[1] != 0 ? atof(token[1]) : 0;

  // check if token[2]
  height = token[2] != 0 ? atof(token[2]) : 0;
}

void Cylinder::output()
{
  cout << "CYLINDER radius=" << radius << " height=" << height;

  // Set surface area & volume to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output surface area & volume
  cout << " surface area=" << (2 * PI * radius * radius) +
    (PI * height * (2 * radius));
  cout << " volume=" << (PI * radius * radius * height);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputIO();

int main()
{
  // create a file-reading object
  ifstream fin;

  void* shapes[100];
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
        Square* s = new Square(token);

        // insert data s to shapes[] and shapeID[]
        shapes[num] = s;
        shapeID[num] = 1;
        ++num;
      }

      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        // dynamic memory allocation
        Rectangle* r = new Rectangle(token);

        // insert data r to shapes[] and shapeID[]
        shapes[num] = r;
        shapeID[num] = 2;
        ++num;
      }

      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        // dynamic memory allocation
        Circle* c = new Circle(token);

        // insert ddata c to shapes[] and shapeID[]
        shapes[num] = c;
        shapeID[num] = 3;
        ++num;
      }

      else if(strcmp(token[0], "CUBE") == 0)
      {
        // dynamic memory allocation
        Cube* cu = new Cube(token);

        // insert data cu to shapes[] and shapeID[]
        shapes[num] = cu;
        shapeID[num] = 4;
        ++num;
      }

      else if(strcmp(token[0], "PRISM") == 0)
      {
        // dynamic memory allocation
        Prism* p = new Prism(token);

        // insert data p to shapes[] and shapeID[]
        shapes[num] = p;
        shapeID[num] = 5;
        ++num;
      }

      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        // dynamic memory allocation
        Cylinder* cl = new Cylinder(token);

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
      ((Square*)shapes[x])->output();

    if(shapeID[x] == 2)
      ((Rectangle*)shapes[x])->output();

    if(shapeID[x] == 3)
      ((Circle*)shapes[x])->output();

    if(shapeID[x] == 4)
      ((Cube*)shapes[x])->output();

    if(shapeID[x] == 5)
      ((Prism*)shapes[x])->output();

    if(shapeID[x] == 6)
      ((Cylinder*)shapes[x])->output();
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
  cout << "Lab 2b, GeometryHomework2.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

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

struct Square
{
  double side;
};

struct Rectangle
{
  double length;
  double width;
};

struct Circle
{
  double radius;
};

struct Cube
{
  double side;
};

struct Prism
{
  double length;
  double width;
  double height;
};

struct Cylinder
{
  double radius;
  double height;
};

void outputIO();
void outputSquare(Square*);
void outputRectangle(Rectangle*);
void outputCircle(Circle*);
void outputCube(Cube*);
void outputPrism(Prism*);
void outputCylinder(Cylinder*);

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
        Square* s = new Square;

        // check if token[1] exist, then put to pointer s
        if(token[1] == NULL)
          s->side = 0;
        else
          s->side = atof(token[1]);

        // insert data s to shapes[] and shapeID[]
        shapes[num] = s;
        shapeID[num] = 1;
        ++num;
      }

      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        // dynamic memory allocation
        Rectangle* r = new Rectangle;

        // check if token[1] exist, then put to pointer r
        if(token[1] == NULL)
          r->length = 0;
        else
          r->length = atof(token[1]);

        // check if token[1] exist, then put to pointer r
        if(token[2] == NULL)
          r->width = 0;
        else
          r->width = atof(token[2]);

        // insert data r to shapes[] and shapeID[]
        shapes[num] = r;
        shapeID[num] = 2;
        ++num;
      }

      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        // dynamic memory allocation
        Circle* c = new Circle;

        // check if token[1] exist, then put to pointer c
        if(token[1] == NULL)
          c->radius = 0;
        else
          c->radius = atof(token[1]);

        // insert ddata c to shapes[] and shapeID[]
        shapes[num] = c;
        shapeID[num] = 3;
        ++num;
      }

      else if(strcmp(token[0], "CUBE") == 0)
      {
        // dynamic memory allocation
        Cube* cu = new Cube;

        // check if token[1] exist, then put to pointer cu
        if(token[1] == NULL)
          cu->side = 0;
        else
          cu->side = atof(token[1]);

        // insert ddata c to shapes[] and shapeID[]
        shapes[num] = cu;
        shapeID[num] = 4;
        ++num;
      }

      else if(strcmp(token[0], "PRISM") == 0)
      {
        // dynamic memory allocation
        Prism* p = new Prism;

        // check if token[1] exist, then put to pointer p
        if(token[1] == NULL)
          p->length = 0;
        else
          p->length = atof(token[1]);

        // check if token[2] exist, then put to pointer p
        if(token[2] == NULL)
         p->width = 0;
        else
          p->width = atof(token[2]);

        // check if token[3] exist, then put to pointer p
        if(token[3] == NULL)
          p->height = 0;
        else
          p->height = atof(token[3]);

        shapes[num] = p;
        shapeID[num] = 5;
        ++num;
      }

      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        // dynamic memory allocation
        Cylinder* cl = new Cylinder;

        // check if token[1] exist, then put to pointer cl
        if(token[1] == NULL)
          cl->radius = 0;
        else
          cl->radius = atof(token[1]);

        // check if token[2] exist, then put to pointer cl
        if(token[2] == NULL)
          cl->height = 0;
        else
          cl->height = atof(token[2]);

        // insert data r to shapes[] and shapeID[]
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
      outputSquare((Square*)shapes[x]);

    if(shapeID[x] == 2)
      outputRectangle((Rectangle*)shapes[x]);

    if(shapeID[x] == 3)
      outputCircle((Circle*)shapes[x]);

    if(shapeID[x] == 4)
      outputCube((Cube*)shapes[x]);

    if(shapeID[x] == 5)
      outputPrism((Prism*)shapes[x]);

    if(shapeID[x] == 6)
      outputCylinder((Cylinder*)shapes[x]);
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

void outputSquare(Square* s)
{
  cout << "SQUARE side=" << s->side;

  // Set area & perimeter to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output area and perimeter
  cout << " area=" << s->side * s->side;
  cout << " perimeter=" << 4 * s->side;
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputRectangle(Rectangle* r)
{
  cout << "RECTANGLE length=" << r->length << " width=" << r->width;

  // Set area & perimeter to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output area and perimeter
  cout << " area=" << r->width * r->length;
  cout << " perimeter=" << (2 * r->width) + (2 * r->length);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputCircle(Circle* c)
{
  cout << "CIRCLE radius=" << c->radius;

  // Set area & perimeter to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output area and perimeter
  cout << " area=" << PI * c->radius * c->radius;
  cout << " perimeter=" << PI * (2 * c->radius);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputCube(Cube* cu)
{
  cout << "CUBE side=" << cu->side;

  // Set surface area & volume to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output surface area & volume
  cout << " surface area=" << 6 * (cu->side * cu->side);
  cout << " volume=" << cu->side * cu->side * cu->side;
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputPrism(Prism* p)
{
  cout << "PRISM length=" << p->length << " width=" << p->width
    << " height=" << p->height;

  // Set surface area & volume to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output surface area & volume
  cout << " surface area=" << (2 * p->width * p->height) + (2 * p->width * p->length) +
    (2 * p->height * p->length);
  cout << " volume=" << (p->height * p->length * p->width);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

void outputCylinder(Cylinder* cl)
{
  cout << "CYLINDER radius=" << cl->radius << " height=" << cl->height;

  // Set surface area & volume to 2 decimal place
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Output surface area & volume
  cout << " surface area=" << (2 * PI * cl->radius * cl->radius) +
    (PI * cl->height * (2 * cl->radius));
  cout << " volume=" << (PI * cl->radius * cl->radius * cl->height);
  cout << endl;

  // Set decimal place to default
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
}

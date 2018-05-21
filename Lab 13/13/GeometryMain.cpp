// Lab 13, GeometryHomework.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

// libraries
#include "GeometryHomework.h"

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

#include<vector>
using std::vector;

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

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
  for(int x = 0; x < shapes.size(); x++)
  {
    shapes[x]->output(cout);
  }

  // deallocation loop using vector
  // before, could use if statements or switch
  for(int y = 0; y < shapes.size(); y++)
  {
    delete shapes[y];
  }
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 13, GeometryHomework.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

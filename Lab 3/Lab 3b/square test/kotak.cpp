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
  Square(const char*[]);
  void output();
private:
  double side;
};

Square::Square(const char* token[])
{
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
  }

  // deallocation loop
  for(int y = 0; y < num; y++)
  {
    if(shapeID[y] == 1)
      delete ((Square*)shapes[y]);
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

// Lab 1b, GeometryHomework1.cpp
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

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

void outputMe();

int main()
{
  double pi = 3.14;
  double side;
  double length;
  double width;
  double height;
  double radius;

  // create a file-reading object
  ifstream fin;
  ofstream fout;

  // Call identifying output
  outputMe();

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
        // Output SQUARE
        cout << token[0];

        // Check if atof(token[1]) != 0 then, print it. Else equal 0
        if(token[1] != NULL)
        {
          side = atof(token[1]);
          cout << " side=" << side;
        }
        else
        {
          side = 0;
          cout << " side=" << '0';
        }

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

      // If token[0] == RECTANGLE
      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        // Output RECTANGLE
        cout << token[0];

        // Check if token[1] and token[2] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
        {
          length = atof(token[1]);
          cout << " length=" << length;
        }
        else
        {
          length = 0;
          cout << " length=" << length;
        }

        if(token[2] != NULL)
        {
          width = atof(token[2]);
          cout << " width=" << width;
        }
        else
        {
          width = 0;
          cout << " width=" << width;
        }

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

      // If token[0] == CIRCLE
      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        // Output CIRCLE
        cout << token[0];

        // Check if token[1] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
        {
          radius = atof(token[1]);
          cout << " radius=" << radius;
        }
        else
        {
          radius = 0;
          cout << " radius=" << radius;
        }

        // Set area & perimeter to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output area and perimeter
        cout << " area=" << pi * radius * radius;
        cout << " perimeter=" << pi * (2 * radius);
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
      }

      // If token[0] == CUBE
      else if(strcmp(token[0], "CUBE") == 0)
      {
        // Output CUBE
        cout << token[0];

        // Check if token[1] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
        {
          side = atof(token[1]);
          cout << " side=" << side;
        }
        else
        {
          side = 0;
          cout << " side=" << side;
        }

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

      // If token[0] == PRISM
      else if(strcmp(token[0], "PRISM") == 0)
      {
        // Output PRISM
        cout << token[0];

        // Check if token[1], token[2] and token[3] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
        {
          length = atof(token[1]);
          cout << " length=" << length;
        }
        else
        {
          length = 0;
          cout << " length=" << length;
        }

        if(token[2] != NULL)
        {
          width = atof(token[2]);
          cout << " width=" << width;
        }
        else
        {
          width = 0;
          cout << " width=" << width;
        }

        if(token[3] != NULL)
        {
          height = atof(token[3]);
          cout << " height=" << height;
        }
        else
        {
          height = 0;
          cout << " height=" << height;
        }

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

      // If token[0] == CYLINDER
      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        // Output CYLINDER
        cout << token[0];

        // Check if token[1] and token[2] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
        {
          radius = atof(token[1]);
          cout << " radius=" << radius;
        }
        else
        {
          radius = 0;
          cout << " radius=" << radius;
        }

        if(token[2] != NULL)
        {
          height = atof(token[2]);
          cout << " height=" << height;
        }
        else
        {
          height = 0;
          cout << " height=" << height;
        }

        // Set surface area & volume to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output surface area & volume
        cout << " surface area=" << (2 * pi * radius * radius) +
          (pi * height * (2 * radius));
        cout << " volume=" << (pi * radius * radius * height);
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
      }

      // If token[0] != choice, output saying invalid object
      else
      {
        cout << token[0] << " is an invalid shape" << endl;
      }
    }
  }

  fin.close();
}

void outputMe()
{
  // Print my name and this assignment's title
  cout << "Lab 1b, GeometryHomework1.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}
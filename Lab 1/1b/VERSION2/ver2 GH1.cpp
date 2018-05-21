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
    const double pi = 3.14;

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
    }

    // process (print) the tokens
    for (int i = 0; i < n; i++) // n = #of tokens
    {
      // If token[0] == SQUARE
      if(strcmp(token[0], "SQUARE") == 0)
      {
        // Output SQUARE
        cout << token[0];

        // Check if atof(token[1]) != 0 then, print it. Else equal 0
        if(token[1] != NULL)
          cout << " side=" << token[1];
        else
          cout << " side=" << '0';

        // Set area & perimeter to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output area and perimeter
        cout << " area=" << atof(token[1]) * atof(token[1]);
        cout << " perimeter=" << 4 * atof(token[1]);
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        break;
      }

      // If token[0] == RECTANGLE
      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        // Output RECTANGLE
        cout << token[0];

        // Check if token[1] and token[2] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
          cout << " length=" << token[1];
        else
          cout << " length=" << '0';

        if(token[2] != NULL)
          cout << " width=" << token[2];
        else
          cout << " width=" << '0';

        // Set area & perimeter to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output area and perimeter
        cout << " area=" << atof(token[2]) * atof(token[1]);
        cout << " perimeter=" << (2 * atof(token[2])) + (2 * atof(token[1]));
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        break;
      }

      // If token[0] == CIRCLE
      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        // Output CIRCLE
        cout << token[0];

        // Check if token[1] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
          cout << " radius=" << token[1];
        else
          cout << " radius=" << '0';

        // Set area & perimeter to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output area and perimeter
        cout << " area=" << pi * atof(token[1]) * atof(token[1]);
        cout << " perimeter=" << pi * (2 * atof(token[1]));
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        break;
      }

      // If token[0] == CUBE
      else if(strcmp(token[0], "CUBE") == 0)
      {
        // Output CUBE
        cout << token[0];

        // Check if token[1] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
          cout << " side=" << token[1];
        else
          cout << " side=" << '0';

        // Set surface area & volume to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output surface area & volume
        cout << " surface area=" << 6 * (atof(token[1]) * atof(token[1]));
        cout << " volume=" << atof(token[1]) * atof(token[1]) * atof(token[1]);
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        break;
      }

      // If token[0] == PRISM
      else if(strcmp(token[0], "PRISM") == 0)
      {
        // Output PRISM
        cout << token[0];

        // Check if token[1], token[2] and token[3] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
          cout << " length=" << token[1];
        else
          cout << " length=" << '0';

        if(token[2] != NULL)
          cout << " width=" << token[2];
        else
          cout << " width=" << '0';

        if(token[3] != NULL)
          cout << " height=" << token[3];
        else
          cout << " height=" << '0';

        // Set surface area & volume to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output surface area & volume
        cout << " surface area=" << (2 * atof(token[2]) * atof(token[1])) + (2 * atof(token[2]) * atof(token[3])) +
          (2 * atof(token[1]) * atof(token[3]));
        cout << " volume=" << (atof(token[2]) * atof(token[1]) * atof(token[3]));
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        break;
      }

      // If token[0] == CYLINDER
      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        // Output CYLINDER
        cout << token[0];

        // Check if token[1] and token[2] != 0 then, print it. Else equal 0
        if(token[1] != NULL)
          cout << " radius=" << token[1];
        else
          cout << " radius=" << '0';

        if(token[2] != NULL)
          cout << " height=" << token[2];
        else
          cout << " height=" << '0';

        // Set surface area & volume to 2 decimal place
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        // Output surface area & volume
        cout << " surface area=" << (2 * pi * atof(token[1]) * atof(token[1])) +
          (pi * atof(token[2]) * (atof(token[1]) + atof(token[1])));
        cout << " volume=" << (pi * atof(token[1]) * atof(token[1]) * atof(token[2]));
        cout << endl;

        // Set decimal place to default
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        break;
      }

      // If token[0] != choice, output saying invalid object
      else
      {
        cout << token[0] << " is an invalid object" << endl;
        break;
      }
    }
  }
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


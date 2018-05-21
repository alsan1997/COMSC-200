// Lab 7b, MyStrings.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

void outputIO();

int main()
{
  string string1("noon is 12 pm; midnight is not.");
  int location;

  outputIO();

  // find "is" at location 5 and 24
  cout << "Original string:\n" << string1
    << "\n\n(find) \"is\" was found at: " << string1.find("is")
    << "\n(rfind) \"is\" was found at: " << string1.rfind("is");

  // find 'o' at location 1
  location = string1.find_first_of("misop");
  cout << endl << location << endl;
  cout << "\n\n(find_first_of) found '" << string1[location]
    << "' from the group \"misop\" at: " << location;

  // find 'o' at location 29
  location = string1.find_last_of("nisop");
  cout << "\n\n(find_last_of) found '" << string1[location]
    << "' from the group \"misop\" at: " << location;

  // find '1' at location 8
  location = string1.find_first_not_of("noi spm");
  cout << "\n\n(find_first_not_of) '" << string1[location]
    << "' is not contained in \"noi spm\" and was found at: "
    << location;

  // find '.' at location 12
  location = string1.find_first_not_of(";noi spm");
  cout << "\n\n(find_first_not_of) '" << string1[location]
    << "' is not contained in \"12noi spm\" and was "
    << "found at: " << location << endl;

  // search for characters not in string 1
  location = string1.find_first_not_of("12noispgm;dth .");
  cout << "\nfind_first_not_of(\"noon is 12 pm; midnight is not.\")"
    << " returned: " << location << endl;
} // end main

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 7a, MyStrings.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

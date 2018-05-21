// Lab 1a, MyGrade.txt and MyGrade.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

void outputMe();

int main()
{
  char buf[100];
  int total; // sum of grades enter by user
  int gradeCounter; // number of the grade to be entered next
  int grade; // grade value entered by user
  int average; // average of grades

  // initialization phase
  total = 0; // initialize total
  gradeCounter = 1; // initialize gradeCounter

  // Call identifying output
  outputMe();

  // processing phase
  while(gradeCounter <= 10) // loop 10 times
  {
    cout << "Enter grade: "; // prompt for input
    cin >> buf; // input grade
    cin.ignore(1000, 10);
    grade = atoi(buf);

    total = total + grade; // add grade to total
    gradeCounter = gradeCounter + 1; // increment gradeCounter by 1
  } // end while

  // termination phase
  average = total / 10;

  // display total and average of grades
  cout << "\nTotal of all grades is " << total << endl;
  cout << "Class average is " << average << endl;
} // end main

void outputMe()
{
  // Print my name and this assignment's title
  cout << "Lab 1a, MyGrade.txt and MyGrade.cpp" << endl;
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

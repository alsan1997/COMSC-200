#include <iostream>
using std::cin;
using std::endl;
using std::cout;

#include "PhoneNumber.h"

int main()
{
  PhoneNumber phone;

  cout << "Enter phone number in the form (123) 456-7890:" << endl;
  cin >> phone;

   cout << "The phone number entered was: ";
   cout << phone << endl;
}

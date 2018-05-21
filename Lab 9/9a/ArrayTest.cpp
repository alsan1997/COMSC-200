#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include "Array.h"

int main()
{
  Array integers1(7);
  Array integers2;

  cout << "Size of Array integers1 is "
    << integers1.getSize()
    << "\nArray after initialization:\n" << integers1;

  cout << "\nSize of Array integers2 is "
    << integers2.getSize()
    << "\nArray after initialization:\n" << integers2;

  cout << "\nEnter 17 integers:\n";
  cin >> integers1 >> integers2;

  cout << "\nAfter input, the Arrays contain:\n"
    << "integers1:\n" << integers1
    << "integers2:\n" << integers2;

  cout << "\nEvaluating: integers1 != integers2" << endl;
  if(integers1 != integers2)
    cout << "integers1 and integers2 are not equal" << endl;

  // copy to integers3 array
  Array integers3(integers1);

  cout << "\nSize of Array integers3 is "
    << integers3.getSize()
    << "\nArray after initialization:\n" << integers3;

  cout << "\nAssigning integers2 to integers1:" << endl;
  integers1 = integers2;

  cout << "integers1:\n" << integers1
    << "integers2:\n" << integers2;

  cout << "\nEvaluating: integers1 == integers2" << endl;
  if(integers1 == integers2)
    cout << "integers1 and integers2 are equal" << endl;

  // use overloaded subscript operator to create rvalue
  cout << "\nintegers1[5] is " << integers1[5];

  // use overloaded subscript operator to create lvalue
  cout << "\n\nAssigning 1000 to integers1[5]" << endl;
  integers1[5] = 1000;
  cout << "integers1:\n" << integers1;

  // attempt to use out of range subscript
  cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
  integers1[15] = 1000; // ERROR: out of range
}

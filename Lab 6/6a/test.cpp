#include <iostream>
using std::endl;
using std::cout;

#include "Time.h"

int main()
{
  Time t;

  t.setHour(18).setMinute(30).setSecond(22);

  cout << "Universal time: ";
  t.printUniversal();

  cout << "\nStandard time: ";
  t.printStandard();

  cout << "\n\nNew Standard time: ";

  t.setTime(20, 20, 20).printStandard();
  cout << endl;
}

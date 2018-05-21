// Lab 16, ElevatorSimulation6.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>

#include <ctime>

#include <cmath>

#include "Building.h"
#include "Elevator.h"
#include "Floor.h"

void outputIO();
int getArrivalsForThisSecond(double);

int main()
{
  // call outputIO
  outputIO();

  srand(time(0)); rand(); // requires cstdlib and ctime
  Building building;

  double averageRiderArrivalRate = 0.1;
  int arrivals;
  int i = 0;

  // cout << building << endl;

  while(true)
  {
    if(!(i % 10))
    {
      cout << "Press ENTER to continue, X-ENTER to quit...\n";
      if (cin.get() > 31) break;
    }

    arrivals = getArrivalsForThisSecond(averageRiderArrivalRate);
    cout << building.step(arrivals) << endl;
    i++;
  }

  cout << "DONE: All riders should be gone, and all elevators idle\n";
}

int getArrivalsForThisSecond(double averageRiderArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageRiderArrivalRate); // for n=0 -- requires cmath (exp = 2.7182818)
  for(double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib AND srand in main
      (randomValue -= probOfnArrivals) > 0.0;
       probOfnArrivals *= averageRiderArrivalRate / ++arrivals);
  return arrivals;
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 16, ElevatorSimulation6.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

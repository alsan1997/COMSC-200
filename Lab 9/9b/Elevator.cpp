// Lab 9b, Elevator.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Elevator.h"

#include <iostream>
using std::ostream;
using std::endl;
using std::cout;

#include <cstdlib>

// static definiton
int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = 2;

// Elevator constructor and initializer list
Elevator::Elevator(const int cap, const int sp, const Floor& floor):
ID(elevatorID), capacity(cap), speed(sp), toFloor(0)
{
  bool x = true;

  elevatorID++; // increment static ID
  doorOpen = x; // set doorOpen to true
  location = floor.getLocation(); // get location of floor
  direction = IDLE; // set direction to IDLE
}

// operator<< function
ostream& operator<<(ostream& out, const Elevator& el)
{
  // cout information of location, direction and doorStatus
  out << "Location: " << el.location;
  out << ", Direction: ";
  if(el.direction == 0) out << "IDLE";
  if(el.direction == 1) out << "UP";
  if(el.direction == 2) out << "DOWN";

  if(el.doorOpen == true) out << ", Doors: Open";
  else out << ", Doors: Close";

  return out; // return ostream
}

bool Elevator::isNearDestination() const // true if distance to destination is less than OR EQUAL TO the speed
{
  bool x;
  int Dest = toFloor->getLocation(); // destination
  int distance = abs(Dest - location); // store difference of destination to location

  if(distance <= speed) x = true;
  else
    x = false;

  return x;
}

void Elevator::moveToDestinationFloor() // set location to that of destination floor (if there is one)
{
  if(toFloor != 0)
    location = toFloor->getLocation();
}

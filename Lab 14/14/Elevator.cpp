// Lab 14, Elevator.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Elevator.h"
#include "Rider.h"
#include "Floor.h"

#include <iostream>
using std::ostream;
using std::endl;
using std::cout;

#include <cstdlib>

#include <vector>
using std::vector;

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

vector<Rider> Elevator::removeRidersForDestinationFloor() // remove riders from vector whose destination is reached
{
  // create empty vector for removed riders to be used as return value
  vector<Rider> removed;

  // if elevator has any riders
  if(rider.size() != 0)
  {
    // create an empty vector for riders who remain on elevator
    vector<Rider> remaining;

    // traverse vector of current riders
    for(int i = 0; i < rider.size(); i++)
    {
      if(&rider[i].getDestination() == toFloor) // if a rider's destination floor is same as elevator's destination
        removed.push_back(rider[i]);// add rider to vector of removed riders

      // else, add rider to vector of remaining riders
      else
        remaining.push_back(rider[i]);
    }

    // reassign elevator rider vector to vector of remaining riders
    rider = remaining;
  }

  // return vector of removed riders
  return removed;
}

void Elevator::addRiders(const vector<Rider>& r) // copy riders from parameter vector to riders vector
{
  // traverse the parameter vector
  for(int i = 0; i < r.size(); i++)
  {
    if(rider.size() != capacity) // if there is still room on the elevator
        rider.push_back(r[i]); // add the rider to the elevator's rider vector
  }
}

void Elevator::setDestinationBasedOnRiders() // reset toFloor based on riders' destinations
{
  if(rider.empty())// if there are no riders on the elevator
  return; // exit the function

  // set elevator's destination to the zeroth Rider's destination
  toFloor = &rider[0].getDestination();

  // traverse the vector of elevator riders
  for(int i = 0; i < rider.size(); i++)
  {
    int distRider;
    int distEle;

    // get the absolute value of the distance from the elevator to the rider's destination floor
    distRider = abs(location - rider[i].getDestination().getLocation());

    // get the absolute value of the distance from the elevator to the elevator's destination floor
    distEle = abs(location - toFloor->getLocation());

    // if closer to the rider's destination than to the elevator's destination
    if(distRider < distEle)
      toFloor = &rider[i].getDestination();// set elevator's destination to the rider's destination
  }
}

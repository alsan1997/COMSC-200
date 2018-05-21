// Lab 14, Floor.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Floor.h"
#include "Rider.h"

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;
using std::endl;

void Floor::addNewRider(const Rider& rider)
{
  // if added rider's destination is greater than the floor's location
  if(rider.getDestination().getLocation() > location)
    upRiders.push_back(rider);// add rider to the upRiders vector
  else // else
    downRiders.push_back(rider);// add rider to the downRiders vector
}

vector<Rider> Floor::removeUpRiders(int max) // max = #of unused spaces on elevator
{
  // create an empty vector for riders to be removed
  vector<Rider> removed;

  if(hasUpRiders() == true) // if there are any up riders...
  {
    // create an empty vector for riders to remain on the floor
    vector<Rider> remaining;

    // traverse the upRiders vector
    for(int i = 0; i < upRiders.size(); i++)
    {
      if(max != 0) // if there are still spaces left on the elevator...
        removed.push_back(upRiders[i]); // add an upRider to the vector of riders to be removed
      else // else
        remaining.push_back(upRiders[i]); // add an upRider to the vector of riders to remain on the floor
    }

    // replace the upRiders vector with the vector of remaining riders
    upRiders = remaining;
  }

  // return the vector of removed riders
  return removed;
}

vector<Rider> Floor::removeDownRiders(int max) // like removeUpRiders, but using the downRiders vector
{
  // create an empty vector for riders to be removed
  vector<Rider> removed;

  if(hasDownRiders() == true) // if there are any down riders...
  {
    // create an empty vector for riders to remain on the floor
    vector<Rider> remaining;

    // traverse the downRiders vector
    for(int i = 0; i < downRiders.size(); i++)
    {
      if(max != 0) // if there are still spaces left on the elevator...
        removed.push_back(downRiders[i]); // add an downRider to the vector of riders to be removed
      else // else
        remaining.push_back(downRiders[i]); // add an downRider to the vector of riders to remain on the floor
    }

    // replace the downRiders vector with the vector of remaining riders
    downRiders = remaining;
  }

  // return the vector of removed riders
  return removed;
}


bool Floor::isPreferredDirectionUp() const
{
  // if there are no downRiders, return true
  if(downRiders.size() == 0) return true;

  // if there are no upRiders, return false
  if(upRiders.size() == 0) return false;

  // if the ID of the first upRider (upRider[0]) is less than that of the first downRider...
  if(upRiders[0] < downRiders[0]) return true;// return true

  return false; // return false
}

ostream& operator<<(ostream& out, const Floor& floor)
{
  out << "Name: " << floor.getName()
    << ", Location: " << floor.getLocation()
    << ", UpRiders: " << floor.getUpRiderCount()
    << ", DownRiders: " << floor.getDownRiderCount() << endl;

  return out;
}



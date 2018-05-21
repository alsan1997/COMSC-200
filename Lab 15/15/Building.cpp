// Lab 15, Building.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Building.h"
#include "Floor.h"
#include "Elevator.h"

#include <iostream>
using std::endl;
using std::ostream;
using std::cout;

#include <cmath>
#include <cstdlib>

// constructor
Building::Building()
{
  // time in seconds
  time = 0;

  // create five floors
  Floor* f1 = new Floor(0, "Ground");
  f.push_back(f1);

  Floor* f2 = new Floor(120, "First Floor");
  f.push_back(f2);

  Floor* f3 = new Floor(240, "Second Floor");
  f.push_back(f3);

  Floor* f4 = new Floor(-120, "Basement 1");
  f.push_back(f4);

  Floor* f5 = new Floor(-240, "Basement 2");
  f.push_back(f5);

  // create two elevators
  Elevator* e1 = new Elevator(12, 5, *f1);
  e.push_back(e1);

  Elevator* e2 = new Elevator(12, 5, *f1);
  e.push_back(e2);
}

// destructor
Building::~Building()
{
  for(int i = 0; i < getFloorCount(); i++)
    delete f[i];

  for(int i = 0; i < getElevatorCount(); i++)
    delete e[i];
}

void getDifferentInts(int max, int& a, int& b)
{
  do
  {
    a = rand() % max; // range is 0 to (max-1)
    b = rand() % max; // range is 0 to (max-1)
  } while (a == b); // try again if they are the same
}

Building& Building::step(int riders)
{
  // POSSIBLE RIDER ACTION [1]
  // add rider(s) in this time step (The number of riders to be added is sent to
  // this function in the parameter list, and is greater or equal to 0.) [1]
  for(int i = 0; i < riders; i++)
  {
    // create a rider with randomly selected from- and to-floors (where from- and to- are not the same!) [1]
    int a, b;
    getDifferentInts(getFloorCount(), a , b);

    // tell the from-floor to add this rider [1]
    Rider r(*f[b]);
    f[a]->addNewRider(r);
  }

  // ELEVATOR ACTIONS [3]
  // tell each elevator to perform an action [3]
  for(int i = 0; i < getElevatorCount(); i++)
  {
    // if elevator door is closed (move up or down) [3]
    if(!e[i]->isDoorOpen())
    {
      // if not near enough to destination to reach it in this time step, continue moving [3]
      if(!e[i]->isNearDestination())
      {
        // if elevator direction is up, move up [3]
        if(e[i]->isDirectionUp()) e[i]->moveUp();

        // otherwise, move down [3]
        else e[i]->moveDown();
      }

      // otherwise it's near enough to destination to reach it in this time step... [4]
      else
      {
        // tell elevator to move to its destination floor [4]
        e[i]->moveToDestinationFloor();

        // tell elevator to open its door [4]
        e[i]->openDoor();

        // tell elevator to remove riders for its destination floor -- ignore returned vector of removed riders [4]
        e[i]->removeRidersForDestinationFloor();

        // get a non-const pointer to the elevator's destination floor (using const_cast) [5] HINT: lecture topic 9
        Floor* DestinationFloor = const_cast<Floor*>(&(e[i]->getDestination()));

        // if elevator is empty, choose a direction based on longest-waiting rider,
        // (the one with the smallest ID) on the floor: [5]
        if(e[i]->hasRiders() == false)
        {
          // if the floor's chosen direction is up [5], tell elevator to set its direction to up [5]
          if(DestinationFloor->isPreferredDirectionUp()) e[i]->setDirectionUp();

          // otherwise [5], tell elevator to set its direction to down [5]
          else e[i]->setDirectionDown();
        }

        // if there is space in the elevator after letting off riders, board new ones [6]
        if(e[i]->getAvailableSpace() != 0)
        {
          // if elevator direction is up, board up-riders (if any)... [6]
          if(e[i]->isDirectionUp())
            e[i]->addRiders(DestinationFloor->removeUpRiders(e[i]->getAvailableSpace()));

          // otherwise, board down-riders (if any) [6]
          else
            e[i]->addRiders(DestinationFloor->removeDownRiders(e[i]->getAvailableSpace()));
        }

        // reassess elevator destination based on its riders [8]
        e[i]->setDestinationBasedOnRiders();
      }
    }

    // otherwise (then it already let off riders, or is in its initial state) [7]
    else
    {
      // if elevator has any riders (then they just boarded in the previous time step) [7]
      if(e[i]->hasRiders())
        e[i]->closeDoor(); // tell elevator to close its door [7]
      else // otherwise [9]
        e[i]->setIdle(); // tell elevator to go idle [9]
    }
  }

  // FLOOR ACTIONS [2]
  // check each floor (for waiting riders) [2]
  for(int i = 0; i < getFloorCount(); i++)
  {
    // if there are no riders waiting on this floor, continue with next floor [2]
    if(!f[i]->hasRidersWaiting()) continue;

    // look at each elevator to see if it needs to be sent here [2]
    for(int j = 0; j < getElevatorCount(); j++)
    {
      // get elevator's relative location (negative if elevator is below floor) [2]
      int loc = (e[j]->getLocation()) - (f[i]->getLocation());

      // if this elevator's idle... [2]
      if(e[j]->isIdle())
      {
        // if elevator is above the floor, set elevator direction to down [2]
        if(loc > 0) e[j]->setDirectionDown();

        // otherwise if it's below, set elevator direction to up [2]
        else e[j]->setDirectionUp();

        // set elevator's destination to this floor [2]
        e[j]->setDestination(f[i]);

        // tell elevator to close its door [2]
        e[j]->closeDoor();
      }

      // else if there are riders on this floor waiting to go up, and the elevator is going up... [10]
      if(f[i]->hasUpRiders() && e[j]->isDirectionUp())
      {
        // get distance from elevator's destination floor to this floor
        //(positive if elevator destination is above this floor) [10]
        int distance = (e[j]->getDestination().getLocation()) - (f[i]->getLocation());

        // if elevator is below floor and elevator destination is above this floor [10]
        if(e[j]->getLocation() < f[i]->getLocation() && distance > 0)
          e[j]->setDestination(f[i]); // set elevator's destination to this floor [10]
      }

      // else if there are riders on this floor waiting to go down, and the elevator is going down... [10]
      if(f[i]->hasDownRiders() && e[j]->isDirectionDown())
      {
        // get distance from elevator's destination floor to this floor
        // (negative if elevator destination is below this floor) [10]
        int distance = (e[j]->getDestination().getLocation() - f[i]->getLocation());

        // if elevator setDestinationBasedOnRiders() is above floor and elevator destination is below this floor [10]
        if(e[j]->getLocation() > f[i]->getLocation() && distance < 0)
          e[j]->setDestination(f[i]); // set elevator's destination to this floor [10]
      }
    }
  }

  time++; // increment time
  return *this;
}

ostream& operator<<(ostream& out, const Building& b)
{
  out << "Time: " << b.time << ", Name: Aldo Sanjoto, ID: 1463659" << endl;

  out << "=====ELEVATOR=====" << endl;
  for(int i = 0; i < b.getElevatorCount(); i++)
  {

    out << *(b.e[i]) << endl;
  }

  out << "=====FLOOR=====" << endl;
  for(int i = 0; i < b.getFloorCount(); i++)
  {
    if(!b.f[i]->hasRidersWaiting()) continue;

    out << *(b.f[i]) << endl;
  }

  return out;
}

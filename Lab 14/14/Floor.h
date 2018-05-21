// Lab 14, Floor.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED

#include "Rider.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

class Floor
{
  const string NAME; // name of floor, for example: Mezzanine
  const int location; // inches above ground level
  vector<Rider> upRiders; // affected by addNewRider, removeUpRiders,...
  vector<Rider> downRiders; // ...and removeDownRiders functions

  public:
  // name and location (inches above ground) of floor
  Floor(const int n, const char* const floorname): location(n), NAME(floorname){}

  // inline functions
  int getLocation() const {return location;}
  bool hasRidersWaiting() const {return ((upRiders.size() != 0) || (downRiders.size() != 0));}
  bool hasUpRiders() const {return (upRiders.size() != 0);}
  bool hasDownRiders() const {return (downRiders.size() != 0);}
  int getUpRiderCount() const {return (upRiders.size());}
  int getDownRiderCount() const {return (downRiders.size());}
  string getName() const {return NAME;}

  // non-inline functions
  bool isPreferredDirectionUp() const; // based on Rider with smallest ID
  void addNewRider(const Rider&); // add to up- or down-vector
  vector<Rider> removeUpRiders(int); // int is max #of riders...
  vector<Rider> removeDownRiders(int); //...to move onto elevator

  // just in case you prefer to use "if (...== *toFloor)"
  //  in Elevator::removeRidersForDestinationFloor(), instead of "...== toFloor)"
  bool operator==(const Floor& floor) const {return NAME == floor.NAME;}

  friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};

#endif // FLOOR_H_INCLUDED

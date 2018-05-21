// Lab 8b, Rider.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef RIDER_H_INCLUDED
#define RIDER_H_INCLUDED

#include "Floor.h"

class Floor;

class Rider
{
  // data members
  private:
    const Floor* const floor;
    static int ID;
    const int riderID;
  public:
    Rider(const Floor&); // constructor
    bool operator==(const Rider&) const; // operator== function
    bool operator<(const Rider&) const; // operator< function
    const Floor& getDestination() const {return *floor;} // return value of int floor
};

#endif // RIDER_H_INCLUDED

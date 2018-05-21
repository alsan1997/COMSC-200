// Lab 15, Rider.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Rider.h"

// static integer definition
int Rider::ID = 0;

// constructor
Rider::Rider(const Floor& x):floor(&x),riderID(ID)
{
  ID++;
}

// operator== function
bool Rider::operator==(const Rider& riders) const
{
  bool x = false;

  if(riderID == riders.riderID) x = true;

  return x;
}

// operator< function
bool Rider::operator<(const Rider& riders) const
{
  bool x = false;

  if(riderID < riders.riderID) x = true;

  return x;
}

Rider& Rider::operator=(const Rider& rider)
{
  if (this == &rider) return *this;

  // assigning const member and const pointer const
  ID = rider.ID;
  const_cast<int&>(riderID) = rider.riderID;
  const_cast<const Floor*&>(floor) = rider.floor;

  return *this; // mutable self reference
}


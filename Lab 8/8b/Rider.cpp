// Lab 8b, Rider.cpp
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

// Lab 15, Building.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

class Elevator;
class Floor;

class Building
{
  private:
    int time;
    vector<Floor*> f;
    vector<Elevator*> e;

  public:
    Building(); // default constructor
    ~Building(); // destructor

    // inline functions
    int getFloorCount() const {return f.size();} // return #of floors in the vector of Floor*'s
    int getElevatorCount() const {return e.size();} // return #of elevators in the vector of Elevator*'s
    const Floor& getFloor(int index) const {return *f[index];} // return a reference to the "indexth" floor
    const Elevator& getElevator(int index) const {return *e[index];} // return a reference to the "indexth" elevator

    Building& step(int);
    friend ostream& operator<<(ostream&, const Building&);
};


#endif // BUILDING_H_INCLUDED

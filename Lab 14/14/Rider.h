// Lab 14, Rider.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef RIDER_H_INCLUDED
#define RIDER_H_INCLUDED

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
    Rider& operator=(const Rider&);
};

#endif // RIDER_H_INCLUDED

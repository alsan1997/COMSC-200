// Lab 8b, Floor.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED

class Floor
{
  private:
    const int floor;
  public:
    const int getLocation() const{return floor;} // getLocation function
    Floor(const int dest):floor(dest){} // constructor
};

#endif // FLOOR_H_INCLUDED

// Lab 5b, ShortestRoute1.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Leg
{
private:
  const char* const starts;
  const char* const ends;
  const double distance;
public:
  Leg(const char* const, const char* const, const double);
  friend void outputLeg(ostream&, const Leg&);
};

Leg::Leg(const char* const s, const char* const e, const double d):
  starts(s), ends(e), distance(d){}

void outputLeg(ostream&, const Leg& data)
{
  cout << data.starts << " to " << data.ends << ", " << data.distance << " miles" << endl;
}

void outputIO();

int main()
{
  outputIO();

  Leg a("San Francisco", "San Jose", 48.1);
  Leg b("San Jose", "Concord", 54.8);
  Leg c("Concord", "Pleasant Hill", 3.4);
  Leg d("Pleasant Hill", "Oakland", 18.8);
  Leg e("Oakland", "Sacramento", 81.3);

  outputLeg(cout, a);
  outputLeg(cout, b);
  outputLeg(cout, c);
  outputLeg(cout, d);
  outputLeg(cout, e);
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 5b, ShortestRoute1.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

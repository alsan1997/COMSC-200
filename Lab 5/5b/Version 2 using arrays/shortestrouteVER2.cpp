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

  const char* const cities[] = {"San Francisco", "New York", "Boston", "Alameda", "Otawa", "Florida"};

  const double distances[] = {65, 434.2, 4324.5, 97.3, 21.2};

  Leg a(cities[0], cities[1], distances[0]);
  Leg b(cities[1], cities[2], distances[1]);
  Leg c(cities[2], cities[3], distances[2]);
  Leg d(cities[3], cities[4], distances[3]);
  Leg e(cities[4], cities[5], distances[4]);

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

// Lab 6b, ShortestRoute2.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

// call class Route definiton
class Route;

// class Leg
class Leg
{
private:
  const char* const starts;
  const char* const ends;
  const double distance;
public:
  Leg(const char* const, const char* const, const double);
  friend void outputLeg(ostream&, const Leg&);
  friend void outputRoute(ostream&, const Route&);
};

// Leg constructor initializer
Leg::Leg(const char* const s, const char* const e, const double d):
  starts(s), ends(e), distance(d){}

// Class Route
class Route
{
private:
  int n;
  const Leg** l;
public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  Route(const Route&);
  friend void outputRoute(ostream&, const Route&);
  ~Route(){delete[] l;}
};

Route::Route(const Leg& first)
{
  n = 1;
  l = new const Leg* [n]; // memory address
  l[0] = &first; // memory address
}

Route::Route(const Route& r, const Leg& first)
{
  n = r.n + 1;
  l = new const Leg* [n];

  for(int i = 0; i < r.n; i++)
    l[i] = r.l[i];

  l[r.n] = &first;
}

Route::Route(const Route& r)
{
  n = r.n;
  l = new const Leg*[n];

  for(int i = 0; i < n; i++)
    l[i] = r.l[i];
}

void outputRoute(ostream&, const Route& r)
{
  double totalDistance = 0;
  cout << (r.l[0])->starts;

  for(int i = 0; i < r.n; i++)
  {
    cout << " to " << (r.l[i])->ends;
    totalDistance = totalDistance + (r.l[i])->distance;
  }

  cout << ", " << totalDistance << " miles" << endl;

}

void outputLeg(ostream&, const Leg& data)
{
  cout << data.starts << " to " << data.ends << ", " << data.distance << " miles" << endl;
}

void outputIO();

int main()
{
  outputIO();

  // initialize 5 leg
  Leg a("San Francisco", "San Jose", 48.1);
  Leg b("San Jose", "Concord", 54.8);
  Leg c("Concord", "Pleasant Hill", 3.4);
  Leg d("Pleasant Hill", "Oakland", 18.8);
  Leg e("Oakland", "Sacramento", 81.3);

  // outputLeg call
  outputLeg(cout, a);
  outputLeg(cout, b);
  outputLeg(cout, c);
  outputLeg(cout, d);
  outputLeg(cout, e);

  cout << endl;

  Route ra(a);
  Route rb(ra, b);
  Route rc(rb, c);
  Route rd(rc, d);
  Route re(rd, e);

  { // start local scope
    const Route rCopy = ra;
    outputRoute(cout, rCopy);
  } // end local scope

  // outputRoute call
  outputRoute(cout, ra);
  outputRoute(cout, rb);
  outputRoute(cout, rc);
  outputRoute(cout, rd);
  outputRoute(cout, re);
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 6b, ShortestRoute2.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

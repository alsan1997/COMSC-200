// Lab 7b, ShortestRoute3.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

// call class Route definiton
class Route;

// class Leg
class Leg
{
private:
  const string starts;
  const string ends;
  const double distance;
public:
  Leg(const string, const string, const double);
  friend void outputLeg(ostream&, const Leg&);
  friend void outputRoute(ostream&, const Route&);
  friend class Route;
};

// Leg constructor initializer
Leg::Leg(const string s, const string e, const double d):
  starts(s), ends(e), distance(d){}

// Class Route
class Route
{
private:
  const int n;
  const Leg** const l;
  const double rdistance;
public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  Route(const Route&);
  ~Route(); // destructor
  bool isGreaterThan(const Route&) const;
  friend void outputRoute(ostream&, const Route&);
};

Route::Route(const Leg& first):
n(1), l(new const Leg* [n]), rdistance(first.distance)
{
  l[0] = &first; // memory address
}

Route::Route(const Route& r, const Leg& first):
n(r.n+1), l(new const Leg* [n]), rdistance(first.distance + r.rdistance)
{
  if (first.starts != r.l[r.n - 1]->ends)
  {
    delete [] l;
    throw "Start City of Leg does not match End City of Route.";
  }

  for(int i = 0; i < r.n; i++)
    l[i] = r.l[i];

  l[r.n] = &first;
}

Route::Route(const Route& r):
n(r.n), l(new const Leg* [n]), rdistance(r.rdistance)
{
  for(int i = 0; i < n; i++)
    l[i] = r.l[i];
}

// destructor
Route::~Route()
{
  delete[] l;
}

// compare function
bool Route::isGreaterThan(const Route& r) const
{
  bool x = false;

  if(rdistance > r.rdistance)
    x = true;

  return x;
}

// outputRoute function
void outputRoute(ostream& out, const Route& r)
{
  out << (r.l[0])->starts;

  for(int i = 0; i < r.n; i++)
  {
    out << " to " << (r.l[i])->ends;
  }
  out << ", " << r.rdistance << " miles" << endl;
}

// output Leg function
void outputLeg(ostream& out, const Leg& data)
{
  out << data.starts << " to " << data.ends << ", " << data.distance << " miles" << endl;
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

  cout << "Local scope test" << endl;
  { // start local scope
    const Route rCopy = ra;
    outputRoute(cout, rCopy);
  } // end local scope
  cout << endl;

  // outputRoute call
  outputRoute(cout, ra);
  outputRoute(cout, rb);
  outputRoute(cout, rc);
  outputRoute(cout, rd);
  outputRoute(cout, re);
  cout << endl;

  // Comparing Routes
  cout << "Compare Test (true indicating host object distance greater than other object)" << endl;
  cout << "Host object: " << endl;
  outputRoute(cout, ra);
  cout << "Other object: " << endl;
  outputRoute(cout, rb);
  cout << "Result: " << ra.isGreaterThan(rb);

  cout << endl << endl;
  cout << "Host object: " << endl;
  outputRoute(cout, rd);
  cout << "Other object: " << endl;
  outputRoute(cout, rc);
  cout << "Result: " << rd.isGreaterThan(rc);

  cout << endl << endl;
  cout << "Host object: " << endl;
  outputRoute(cout, rb);
  cout << "Other object: " << endl;
  outputRoute(cout, rc);
  cout << "Result: " << rb.isGreaterThan(rc);

  // Simple exception test
  cout << endl << endl;
  cout << "Simple exception test" << endl;
  try
  {
    Route(Route(Leg("a", "b", 0)), Leg("c", "d", 0));
  }
  catch (const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Lab 7b, ShortestRoute3.cpp \n";
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

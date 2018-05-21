// Term Project, ShortestRoute.cpp
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <set>
using std::set;

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
  Leg& operator=(const Leg&);

  friend ostream& operator<<(ostream&, const Leg&);
  friend ostream& operator<<(ostream&, const Route&);
  friend class Route;
  friend class ShortestRoute;
};

// Leg constructor initializer
Leg::Leg(const string s, const string e, const double d):
  starts(s), ends(e), distance(d){}

// output Leg function
ostream& operator<<(ostream& out, const Leg& data)
{
  out << data.starts << " to " << data.ends << ", " << data.distance << " miles" << endl;

  return out;
}

Leg& Leg::operator=(const Leg& l)
{
  if (this == &l) return *this;

  const_cast<string&>(starts) = l.starts;
  const_cast<string&>(ends) = l.ends;
  const_cast<double&>(distance) = l.distance;

  return *this; // mutable self reference
}

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

  Route& operator=(const Route&);
  bool operator<(const Route&) const;
  bool isGreaterThan(const Route&) const;
  friend ostream& operator<<(ostream&, const Route&);
  friend class ShortestRoute;
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

/*
Route& Route::operator=(const Route& route)
{
  if (this == &route) return *this;

  const_cast<int&>(n) = route.n;
  const_cast<double&>(rdistance) = route.rdistance;

  const Leg** const l = new const Leg*[route.n];
  for(int i = 0; i < route.n; i++)
  {
    route.l[i] = l[i];
  }

  delete[] l;

  return *this;
}*/

bool Route::operator<(const Route& r) const
{
  bool result = false;

  if(rdistance < r.rdistance) result = true;

  return result;
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
ostream& operator<<(ostream& out, const Route& r)
{
  out << (r.l[0])->starts << endl;

  for(int i = 0; i < r.n; i++)
  {
    out << "to " << (r.l[i])->ends << endl;
  }
  out << "Distance:" << r.rdistance << " miles" << endl;

  return out;
}
// class ShortestRoute
class ShortestRoute
{
public:
  static vector<Leg> legs; // public or private
  static const Route getAnyRoute(const string, const string);
  static const Route getShortestRoute(const string, const string);
};

vector<Leg> ShortestRoute::legs;

const Route ShortestRoute::getAnyRoute(const string from, const string to)
{
  for(int i = 0; i < legs.size(); i++)
  {
    if(legs[i].starts == from && legs[i].ends == to)
    {
      Route r(legs[i]);
      return r;
    }

    if(legs[i].starts != from && legs[i].ends == to)
    {
      Route r(getAnyRoute(from, legs[i].starts), legs[i]);
      return r;
    }
  }

  throw "No routes can be found between the cities.";
}

const Route ShortestRoute::getShortestRoute(const string from, const string to)
{
  set<Route> r;

  for(int i = 0; i < legs.size(); i++)
  {
    if(legs[i].starts == from && legs[i].ends == to)
      r.insert(Route(legs[i]));

    if(legs[i].starts != from && legs[i].ends == to)
      r.insert(Route(getShortestRoute(from, legs[i].starts), legs[i]));
  }

  if(r.size() == 0)
    throw "No routes can be found between the cities";
  else
    return *(r.begin());
}

void outputIO();

int main()
{
  outputIO();

  ShortestRoute::legs.push_back(Leg ("San Francisco", "Sacramento", 75));
  ShortestRoute::legs.push_back(Leg ("San Francisco", "Las Vegas", 600));
  ShortestRoute::legs.push_back(Leg ("San Francisco", "Los Angeles", 350));
  ShortestRoute::legs.push_back(Leg ("San Francisco", "Fresno", 171));
  ShortestRoute::legs.push_back(Leg ("Sacramento", "Fresno", 257));
  ShortestRoute::legs.push_back(Leg ("Fresno", "Los Angeles", 220));
  ShortestRoute::legs.push_back(Leg ("Fresno", "Carson City", 260));
  ShortestRoute::legs.push_back(Leg ("Sacramento", "Las Vegas", 571));
  ShortestRoute::legs.push_back(Leg ("Los Angeles", "Las Vegas", 270));
  ShortestRoute::legs.push_back(Leg ("Sacramento", "Carson City", 170));
  ShortestRoute::legs.push_back(Leg ("Carson City", "Las Vegas", 433));
  ShortestRoute::legs.push_back(Leg ("Los Angeles", "Carson City", 439));
  ShortestRoute::legs.push_back(Leg ("Carson City", "Salt Lake City", 547));
  ShortestRoute::legs.push_back(Leg ("Las Vegas", "Salt Lake city", 420));
  ShortestRoute::legs.push_back(Leg ("Las Vegas", "Grand Junction", 507));
  ShortestRoute::legs.push_back(Leg ("Salt Lake City", "Grand Junction", 283));
  ShortestRoute::legs.push_back(Leg ("Salt Lake City", "Denver", 519));
  ShortestRoute::legs.push_back(Leg ("Grand Junction", "Denver", 249));
  ShortestRoute::legs.push_back(Leg ("Grand Junction", "Colorado Springs", 309));
  ShortestRoute::legs.push_back(Leg ("Denver", "Topeka", 540));
  ShortestRoute::legs.push_back(Leg ("Denver", "Colorado Springs", 70));
  ShortestRoute::legs.push_back(Leg ("Colorado Springs", "Topeka", 522));
  ShortestRoute::legs.push_back(Leg ("Colorado Springs", "Springfield", 751));
  ShortestRoute::legs.push_back(Leg ("Topeka", "Kansas City", 64));
  ShortestRoute::legs.push_back(Leg ("Topeka", "Springfield", 229));
  ShortestRoute::legs.push_back(Leg ("Kansas City", "Louisville", 506));
  ShortestRoute::legs.push_back(Leg ("Springfield", "Louisville", 470));
  ShortestRoute::legs.push_back(Leg ("Kansas City", "Springfield", 165));
  ShortestRoute::legs.push_back(Leg ("Louisville", "Frankfort", 54));
  ShortestRoute::legs.push_back(Leg ("Springfield", "Frankfort", 527));
  ShortestRoute::legs.push_back(Leg ("Frankfort", "Cincinnati", 80));
  ShortestRoute::legs.push_back(Leg ("Louisville", "Cincinnati", 99));
  ShortestRoute::legs.push_back(Leg ("Cincinnati", "Charleston", 197));
  ShortestRoute::legs.push_back(Leg ("Frankfort", "Charleston", 198));
  ShortestRoute::legs.push_back(Leg ("Cincinnati", "Columbus", 106));
  ShortestRoute::legs.push_back(Leg ("Columbus", "Charleston", 161));
  ShortestRoute::legs.push_back(Leg ("Columbus", "New York", 535));
  ShortestRoute::legs.push_back(Leg ("Charleston", "New York", 531));
  ShortestRoute::legs.push_back(Leg ("San Francisco", "New York", 21000));

  try
  {
    cout << "Any Routes between San Francisco to New York: " << endl;
    cout <<  ShortestRoute::getAnyRoute("San Francisco", "New York") << endl;
  }
  catch(const char* ex)
  {
    cout << "ERROR DETECTED: "  << ex << endl;
  }

  cout << "=================================================" << endl << endl;

  try
  {
    cout << "Shortest Routes between San Francisco to New York: " << endl;
    cout << ShortestRoute::getShortestRoute("San Francisco", "New York") << endl;
  }
  catch(const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }
}

void outputIO()
{
  // Print my name and this assignment's title
  cout << "Term Project, ShortestRoute.cpp" << endl;
  cout << "Programmer: Aldo Sanjoto " << endl;
  cout << "Editor(s) used: Code::Blocks \n";
  cout << "Compiler(s) used: Code::Blocks " << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

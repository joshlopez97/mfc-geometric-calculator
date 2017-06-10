// identification comments code block
// Programmer: Joshua Lopez
// Programmer's ID: 1608685

#ifndef PSHAPES_H_
#define PSHAPES_H_

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include <cmath>
#include <cstdlib>

struct Shape
{
  virtual void output(ostream&) const = 0;
  virtual ~Shape() {}
};
ostream& operator<<(ostream&, const Shape&);

class Square : public Shape
{
  protected:
  const double side;

  public:
  void output(ostream&) const;
  Square(const vector<string>&);
  Square& operator=(const Square&);
};

namespace comsc
{
  class Rectangle : public Shape
  {
  protected:
    const double length;
    const double width;

  public:
    void output(ostream&) const;
    Rectangle(const vector<string>&);
    Rectangle& operator=(const Rectangle&);
  };
}
class Circle : public Shape
{
  protected:
  const double radius;

  public:
  void output(ostream&) const;
  Circle(const vector<string>&);
  Circle& operator=(const Circle&);
};

class Triangle : public Shape
{
  protected:
  const double side;

  public:
  void output(ostream&) const;
  Triangle(const vector<string>&);
  Triangle& operator=(const Triangle&);
};

class Cube : public Square
{
  public:
  void output(ostream&) const;
  Cube(const vector<string>& tokens)
    : Square(tokens) {}
  Cube& operator=(const Cube&);
};

class Box : public comsc::Rectangle
{
  const double height;

  public:
  void output(ostream&) const;
  Box(const vector<string>& tokens)
    : comsc::Rectangle(tokens), height(tokens.size() > 3? atof(tokens[3].c_str()) : 0.0) {}
  Box& operator=(const Box&);
};

class Cylinder : public Circle
{
  const double height;

  public:
  void output(ostream&) const;
  Cylinder(const vector<string>& tokens)
    : Circle(tokens), height(tokens.size() > 2? atof(tokens[2].c_str()) : 0.0) {}
  Cylinder& operator=(const Cylinder&);
};

class Prism : public Triangle
{
  const double height;

  public:
  void output(ostream&) const;
  Prism(const vector<string>& tokens)
    : Triangle(tokens), height(tokens.size() > 2? atof(tokens[2].c_str()) : 0.0) {}
  Prism& operator=(const Prism&);
};

// non-member function prototypes
vector<string> parseString(string);
ostream& roundingOn(ostream&);
ostream& roundingOff(ostream&);

const double PI = atan(1.0) * 4;    // PI constant used for calculations

#endif

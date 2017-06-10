// identification comments code block
// Programmer: Joshua Lopez
// Programmer's ID: 1608685
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <cstdlib>

#include "pShapes.h"

// Function calculates area/perimeter of SQUARE and prints to output stream
void Square::output(ostream& out) const
{
  const double s = this->side;    // s = side
  const double area = s * s;
  const double perimeter = s * 4;

  // print to console
  out << "SQUARE side=" << s;
  out << roundingOn;
  out << " area=" << area;
  out << " perimeter=" << perimeter << endl;
  out << roundingOff;
}

// constructor sets correct side for square
Square::Square(const vector<string>& tokens)
: side(tokens.size() > 1? atof(tokens[1].c_str()) : 0.0)
{
}

// overloaded operator function copies one square into another
Square& Square::operator=(const Square& square2)
{
  Square& host = *this;
  const_cast<double&>(host.side) = square2.side;
  return host;
}

// Function calculates area/perimeter of RECTANGLE and prints to an output stream
void comsc::Rectangle::output(ostream& out) const
{
  const double l = this->length;  // l = length
  const double w = this->width;   // w = width
  const double area = l * w;
  const double perimeter = 2 * (l + w);

  // print to output stream
  out << "RECTANGLE length=" << l;
  out << " width=" << w;
  out << roundingOn;
  out << " area=" << area;
  out << " perimeter=" << perimeter << endl;
  out << roundingOff;
}

// constructor sets correct length and width for rectangle
comsc::Rectangle::Rectangle(const vector<string>& tokens)
: length(tokens.size() > 1? atof(tokens[1].c_str()) : 0.0),
  width(tokens.size() > 2? atof(tokens[2].c_str()) : 0.0)
{
}

// overloaded operator function copies one rectangle into another
comsc::Rectangle& comsc::Rectangle::operator=(const comsc::Rectangle& rectangle2)
{
  comsc::Rectangle& host = *this;
  const_cast<double&>(host.length) = rectangle2.length;
  const_cast<double&>(host.width) = rectangle2.width;
  return host;
}

// function calculates area/perimeter of CIRCLE and prints to an output stream
void Circle::output(ostream& out) const
{
  const double r = this->radius;  // r = radius
  const double area = PI * r * r;
  const double perimeter = 2 * PI * r;

  // print to output stream
  out << "CIRCLE radius=" << r;
  out << roundingOn;
  out << " area=" << area;
  out << " perimeter=" << perimeter << endl;
  out << roundingOff;
}

// constructor sets correct radius for circle
Circle::Circle(const vector<string>& tokens)
: radius(tokens.size() > 1? atof(tokens[1].c_str()) : 0.0)
{
}

// overloaded operator function copies one circle into another
Circle& Circle::operator=(const Circle& circle2)
{
  Circle& host = *this;
  const_cast<double&>(host.radius) = circle2.radius;
  return host;
}

// function calculates area/perimeter of equilateral TRIANGLE and prints to output stream
void Triangle::output(ostream& out) const
{
  const double s = this->side;  // s = side
  const double area = (s * s) / 2;
  const double perimeter = 3 * s;

  // print to output stream
  out << "TRIANGLE side=" << s;
  out << roundingOn;
  out << " area=" << area;
  out << " perimeter=" << perimeter << endl;
  out << roundingOff;
}

// constructor sets correct side for triangle
Triangle::Triangle(const vector<string>& tokens)
: side(tokens.size() > 1? atof(tokens[1].c_str()) : 0.0)
{
}

// overloaded operator function copies one triangle into another
Triangle& Triangle::operator=(const Triangle& triangle2)
{
  Triangle& host = *this;
  const_cast<double&>(host.side) = triangle2.side;
  return host;
}

// function calculates surface area/volume of CUBE and prints to output stream
void Cube::output(ostream& out) const
{
  const double s = this->side;      // s = side
  const double surfaceArea = 6 * s * s;
  const double volume = s * s * s;

  // print to console
  out << "CUBE side=" << s;
  out << roundingOn;
  out << " surface area=" << surfaceArea;
  out << " volume=" << volume << endl;
  out << roundingOff;
}

// overloaded operator function copies one cube into another
Cube& Cube::operator=(const Cube& cube2)
{
  Cube& host = *this;
  const_cast<double&>(host.side) = cube2.side;
  return host;
}

// function calculates surface area/volume of BOX and prints to output stream
void Box::output(ostream& out) const
{
  const double l = this->length;    // length = l
  const double w = this->width;     // width = w
  const double h = this->height;    // height = h
  const double surfaceArea = (2 * l * w) + (2 * l * h) + (2 * w * h);
  const double volume = l * w * h;

  // print to output stream
  out << "BOX length=" << l;
  out << " width=" << w << " height=" << h;
  out << roundingOn;
  out.precision(2);
  out << " surface area=" << surfaceArea;
  out << " volume=" << volume << endl;
  out << roundingOff;
}

// overloaded operator function copies one box into another
Box& Box::operator=(const Box& box2)
{
  Box& host = *this;
  const_cast<double&>(host.length) = box2.length;
  const_cast<double&>(host.width) = box2.width;
  const_cast<double&>(host.height) = box2.height;
  return host;
}

// function calculates surface area/volume of CYLINDER and prints to output stream
void Cylinder::output(ostream& out) const
{
  const double r = this->radius; // r = radius
  const double h = this->height; // h = height
  // (2 * area of circle) + (height * circumference of circle)
  double surfaceArea = (2 * PI * r * r) + (2 * PI * r * h);
  // area of circle * height
  double volume = PI * r * r * h;

  // print to output stream
  out << "CYLINDER radius=" << r;
  out << " height=" << h;
  out << roundingOn;
  out << " surface area=" << surfaceArea;
  out << " volume=" << volume << endl;
  out << roundingOff;
}

// overloaded operator function copies one cylinder into another
Cylinder& Cylinder::operator=(const Cylinder& cylinder2)
{
  Cylinder& host = *this;
  const_cast<double&>(host.radius) = cylinder2.radius;
  const_cast<double&>(host.height) = cylinder2.height;
  return host;
}

// function calculates surface area/volume of equilateral PRISM and prints to output stream
void Prism::output(ostream& out) const
{
  const double s = this->side;      // s = side;
  const double h = this->height;    // h = height;
  const double triangleArea = (s * s) / 2;
  const double surfaceArea = (2 * triangleArea) + (3 * s * h);
  const double volume = triangleArea * h;

  // print to output stream
  out << "PRISM side=" << s;
  out << " height=" << h;
  out << roundingOn;
  out << " surface area=" << surfaceArea;
  out << " volume=" << volume << endl;
  out << roundingOff;
}

// overloaded operator function copies one prism into another
Prism& Prism::operator=(const Prism& prism2)
{
  Prism& host = *this;
  const_cast<double&>(host.side) = prism2.side;
  const_cast<double&>(host.height) = prism2.height;
  return *this;
}

// Function turns rounding on to the hundredth's place for output stream
ostream& roundingOn(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

// Function returns output stream to default rounding/formatting
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

// stream operator
ostream& operator<<(ostream& out, const Shape& s)
{
  s.output(out);
  return out;
}


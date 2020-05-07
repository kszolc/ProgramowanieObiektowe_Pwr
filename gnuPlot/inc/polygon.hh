#pragma once
#include <string>
#include <cstring>
#include <iostream>

#include "vector.hh"

class Triangle
{
public:
  Vector<double, 3> point[3];

  Triangle operator+(Vector<double,3> vec);

  friend std::ostream &operator<<(std::ostream &stream, Triangle tri)
  {

    for (int i = 0; i < 3; i++)
    {
      stream << tri.point[i] << " ";
    }
    stream << tri.point[0];
    stream << std::endl;
    return stream;
  }
  friend std::istream &operator>>(std::istream &stream, Triangle &tri)
  {

    for (int i = 0; i < 3; i++)
    {
      stream >> tri.point[i];
    }

    return stream;
  }
};
class Rectangle
{
public:
  Vector<double, 3> point[4];
  Rectangle operator+(Vector<double,3> vec);
  friend std::ostream &operator<<(std::ostream &stream, Rectangle tri)
  {

    for (int i = 0; i < 4; i++)
    {
      stream << tri.point[i] << " ";
    }
    stream << tri.point[0];
    stream << std::endl;
    return stream;
  }
  friend std::istream &operator>>(std::istream &stream, Rectangle &tri)
  {

    for (int i = 0; i < 4; i++)
    {
      stream >> tri.point[i];
    }

    return stream;
  }
};

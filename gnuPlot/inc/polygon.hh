#pragma once
#include <string>
#include <cstring>
#include <iostream>

class Point3
{
public:
  double pointPos[3];

  friend std::ostream &operator<<(std::ostream &stream, Point3 po)
  {
    for (int i = 0; i < 3; i++)
      stream << po.pointPos[i] << "  ";
    stream << std::endl;
    return stream;
  }
  friend std::istream &operator>>(std::istream &stream, Point3 &po)
  {
    for (int i = 0; i < 3; i++)
      stream >> po.pointPos[i];
    return stream;
  }
  Point3 operator+(Point3 addPoint)
  {
    Point3 result;
    for (int i = 0; i < 3; i++)
    {
      if(std::abs(addPoint.pointPos[i]) > 1)
      result.pointPos[i] = pointPos[i] + addPoint.pointPos[i];
    }
  }
};
template <int SIZE>
class Polygon : public Point3
{
private:
  std::string name;
  std::string tempName;
  int id;

public:
  Point3 pos[SIZE];

  friend std::ostream &operator<<(std::ostream &stream, Polygon polygon)
  {
    for (int i = 0; i < SIZE; i++)
      stream << polygon.pos[i] << "  ";
    stream << std::endl;
    return stream;
  }
  friend std::istream &operator>>(std::istream &stream, Polygon &polygon)
  {
    for (int i = 0; i < SIZE; i++)
      stream >> polygon.pos[i];
    return stream;
  }
  Polygon<SIZE> operator+(Point3 point)
  {
    Polygon<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
      result.pos[i] = pos[i] + point;
    }
    return result;
  }
};

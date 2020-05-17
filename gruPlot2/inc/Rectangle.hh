#pragma once

#include <iostream>

#include "vector.hh"
#include "fps.hh"

using Vector3 = Vector<double, 3>;
/**
 * @brief Rectangle object, simple, yet required to create mesh
 * 
 */
class Rectangle
{

public:
  /**
   * @brief Position of all four points of this rectangle
   * 
   */
  Vector3 point[4];

  /**
   * @brief counter of rectangle objects
   * 
   */
  static int count;

  Rectangle operator+(Vector3 shift);
  Rectangle operator*(Vector3 angle);
};

Vector3 calculateRotation(Vector3 point, Vector3 angle);
std::ostream &operator<<(std::ostream &stream, const Rectangle &rect);
std::istream &operator>>(std::istream &stream, Rectangle &rect);

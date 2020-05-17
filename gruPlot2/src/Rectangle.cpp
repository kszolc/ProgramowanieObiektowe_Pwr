#include "Rectangle.hh"

using Vector3 = Vector<double, 3>;

std::istream &operator>>(std::istream &stream, Rectangle &rect)
{
  for (int i = 0; i < 4; i++)
    stream >> rect.point[i];

  return stream;
}

std::ostream &operator<<(std::ostream &stream, const Rectangle &rect)
{
  for (int i = 0; i < 4; i++)
    stream << rect.point[i];
  stream << rect.point[0];
  stream << std::endl
     //    << "#\n"
         << std::endl;
  return stream;
}

Rectangle Rectangle::operator+(Vector3 shift)
{
  Rectangle result;
  for (int i = 0; i < 4; i++)
  {
    result.point[i] = point[i] + shift;
  }
  return result;
}
Rectangle Rectangle::operator*(Vector3 angle)
{
  Rectangle result;
  for (int i = 0; i < 4; i++)
  {
    result.point[i] = calculateRotation(point[i], angle);
  }
  return result;
}

Vector3 calculateRotation(Vector3 point, Vector3 angle){
  double rad = angle.value[0] * M_PI /180;
  Vector3 result;
  result.value[0] = cos(rad) * point.value[0] + sin(rad) * point.value[1];
  result.value[1] = -sin(rad) * point.value[0] + cos(rad) * point.value[1];
  result.value[2] = point.value[2];
  return result;
}

#pragma once
#include <iostream>
#include <cmath>
/**
 * @brief Vector class
 * 
 * @tparam T - Type of data to store
 * @tparam SIZE - Dimentions of created vector
 */
template <typename T, int SIZE>
class Vector
{
public:
  
  double length()
  {
    double sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
      sum += (value[i] * value[i]);
    }
    sum = std::sqrt(sum);
    return sum;
  }

  T value[SIZE];
  static int vectorCounter;

  Vector<T, SIZE> operator+(Vector<T, SIZE> vec)
  {
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
      result.value[i] = value[i] + vec.value[i];
    }
    return result;
  }
  Vector<T, SIZE> operator-(Vector<T, SIZE> vec)
  {
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
      result.value[i] = value[i] - vec.value[i];
    }
    return result;
  }

  Vector<T, SIZE> operator+=(Vector<T, SIZE> vec)
  {
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
      result.value[i] = value[i] + vec.value[i];
      value[i] = result.value[i];
    }
    return result;
  }

  Vector<T, SIZE> operator*(Vector<T, SIZE> vec)
  {
    Vector<T, SIZE> result;
    
      result.value[0] = value[0] * cos(vec.value[0]);
      result.value[1] = value[1] * sin(vec.value[1]);
      result.value[2] = value[2];
    
    return result;
  }

  bool operator==(Vector<T, SIZE> vec)
  {
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
      result.value[i] = value[i] - vec.value[i];
    }
    if(result.length() < 0.01) return true;
    else return false;
  }
    bool operator<=(Vector<T, SIZE> vec)
  {
   
    for (int i = 0; i < SIZE; i++)
    {
      if(abs(value[i] - vec.value[i]) <-0.001) return false;
    }
    return true;
  }
  bool operator==(double val)
  {

    if (std::abs(val - length()) < 0.001)
      return true;
    else
      return false;
  }

  friend std::ostream &operator<<(std::ostream &stream, Vector<T, SIZE> vec)
  {
    for (int i = 0; i < SIZE; i++)
    {
      stream << vec.value[i] << " ";
    }
    stream << "\n";
    return stream;
  }
  friend std::istream &operator>>(std::istream &stream, Vector<T, SIZE> &vec)
  {

    for (int i = 0; i < SIZE; i++)
    {
      stream >> vec.value[i];
    }

    return stream;
  }
};

#pragma once

#include "Size.hh"
#include <iostream>
#include <algorithm>



/*
 *  Matrix class
 * 
 * Variables:
 * value[SIZE][SIZE] - valuables stored in array
 * 
 * Methods:
 * wow, such empty...
 */
class Matrix
{
  private:
    const bool isZero(int num, int num2);
    
  public:
    double value[SIZE][SIZE];
  
    const double determinant();
 
};

/*
 * Gets matrix from input stream
 * 
 *  Format:
 * | double_value , double_value , double_value |
 * | double_value , double_value , double_value |
 * | double_value , double_value , double_value |
 */
std::istream &operator>>(std::istream &stream, Matrix &matrix);

/*
 * Prints matrix to output stream
 * 
 *  Format:
 * | double_value  double_value  double_value |
 * | double_value  double_value  double_value |
 * | double_value  double_value  double_value |
 */
std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);

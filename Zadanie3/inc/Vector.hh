#pragma once

#include "Size.hh"
#include <iostream>
#include <fstream>

using namespace std;
/*
 *  Defines multidimentional VECTOR.
 *  Number of dimenstions defines SIZE value
 *  
 *  Variables:
 *  double value[SIZE] - values of vector
 * 
 *  Methods:
 *  
 *  readFromFile() - reads data from Data.txt file 
 */
class Vector
{
  public:

  double value[SIZE];

  int readFromFile();

};

/*
 * Inputs value of vector in specific format to object of Vector class
 * 
 *  Format:
 *  [double_value , double_value , double_value]
 */
std::istream &operator>>(std::istream &stream, Vector &vec);

/*
 * Prints vector to output stream
 * 
 *  Format:
 *  [double_value , double_value , double_value]
 */
std::ostream &operator<<(std::ostream &stream, const Vector &vec);





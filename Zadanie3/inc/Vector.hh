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
/*!
 *  Load values of vector from file named by user
 *
 *  Input type:
 *  [double_value , double_value , double_value]
 *
 *  Returns:
 *  0 - Flawless read
 *  1 - Could not open file
 *  2 - Input type is invalid 
 */
  int readFromFile();
/*!
* Overloading + operator for Vectors
* 
* Input:
* This Vector instance
* Vector
*
* Returns:
* Sum of two input vectors by Vector type;
*/
  Vector operator + (Vector vec2);

  /*!
* Overloading - operator for Vectors
* 
* Input:
* This Vector instance
* Vector
*
* Returns:
* difference of two input vectors by Vector type;
*/
 // Vector operator - (Vector vec2);

  /*!
* Overloading * operator for Vector and Number;
* 
* Input:
* This Vector instance
* Double_value
*
* Returns:
* Multiplication by Vector type;
*/
  //Vector operator * (double num);

  /*!
* Overloading / operator for Vector and Number;
* 
* Input:
* This Vector instance
* Double_value
*
* Returns:
* Diviction by Vector type;
*/
  Vector operator / (double num);

  /*!
* Overloading * operator for Vectors
* 
* Input:
* Vector
* Vector
*
* Returns:
* Scalar product of two input vectors by double type;
*/
double operator *(Vector vec2);
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





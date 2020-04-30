#pragma once
#include <cmath>
#include <type_traits>
#include "complex.hh"
#include "vector.hh"

template <typename T, int SIZE>
class Matrix
{
private:


public:
  T val[SIZE][SIZE]; // [line][column]

  const T determinant()
  {
    Matrix cp = *this;
    int swaps = 0;
    T mul;
    T result;
  
    /*********************************************/
    /********** FORMING DIAGONAL MATRIX **********/
    /*********************************************/
    for (int i = 0; i < SIZE - 1; i++)
    {
      /********** CHECK IF DIAGONAL ELEMENT IS ZERO ********/

      if (cp.val[i][i] > -0.00001 &&cp.val[i][i] < 0.00001)
      {
        //Check if we have "space" for swapping columns
        if (i < SIZE - 1)
        { //proceed swaping columns
          int j = i + 1;

          while (cp.val[j][j] > -0.00001 &&cp.val[j][j] < 0.00001)
          { //Check if diagonal of next column is not zero
            j++;
            if (j >= SIZE)
              return result; // this is end of our list, and we dont have determinant
          }
          //swaping
          for (int k = 0; k < SIZE; k++)
          {
            T placeholder = cp.val[k][i];
            cp.val[k][i] = cp.val[k][j];
            cp.val[k][j] = placeholder;
          }
          swaps++;
        }
        else
          return result; //we dont have space so determinant is 0
      }
      // ********* END OF CHECKING IF ZERO ************/

      // DIAGONAL
      for (int j = i + 1; j < SIZE; j++)
      {
        mul = cp.val[j][i] / cp.val[i][i];
        for (int k = 0; k < SIZE; k++)
        {
          cp.val[j][k] -= cp.val[i][k] * mul;
        }
      }
    } /********** END OF FORMING DRIAGONAL MATRIX **********/
    result = cp.val[0][0];
    for (int i = 1; i < SIZE; i++)
    {
      result *= cp.val[i][i];
    }
    if (swaps % 2)
      return result * (-1);
    else
      return result;
  }

  T put(Vector<T, SIZE> vec, int column)
  {
    Matrix cp = *this;
   
    for (int i = 0; i < SIZE; i++)
    {
      cp.val[i][column] = vec.val[i];
    }
    return cp.determinant();
  }

  friend const std::ostream &operator<<(std::ostream &stream, Matrix<T, SIZE> m)
  {
    for (int i = 0; i < SIZE; i++)
    {
      stream << "|";
      for (int j = 0; j < SIZE; j++)
      {
        stream << " "<< m.val[i][j];
        m.val[i][j];
      }
      stream << " |" <<std::endl;
    }
    return stream;
  }
  friend std::istream &operator>>(std::istream &stream, Matrix<T, SIZE> &m)
  {
    {
      for (int i = 0; i < SIZE; i++)
      {
     //   std::cin.ignore(1024, '|');
        for (int j = 0; j < SIZE; j++)
        {
          stream >> m.val[i][j];
        }
      //  std::cin.ignore(1024, '|');
      }
      return stream;
    }
  }
};
#pragma once
#include <iostream>

class Complex{
  private:
    double re;
    double im;
  
  public:
  /*! 
   * Returns absolute value of this complex number
   */
    const double absv();

    // Operator overloads
    const Complex operator+(Complex c1);
    const Complex operator-(Complex c1);
    const Complex operator*(Complex c1);
    const Complex operator/(Complex c1);
    const Complex operator*(double d);
    void operator*=(Complex c1);
    void operator-=(Complex c1);
    const bool operator>(double d);
    const bool operator<(double d);


    // Overloads of in and out streams
    friend std::ostream &operator<<(std::ostream &stream, const Complex c1);
    friend std::istream &operator>>(std::istream &stream, Complex &c1);
    
};
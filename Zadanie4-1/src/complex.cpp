#include "complex.hh"
#include <cmath>

using namespace std;

const double Complex::absv()
{
  return sqrt(re * re + im * im);
}

const Complex Complex::operator+(Complex c1)
{
  Complex result;
  result.re = re + c1.re;
  result.im = im + c1.im;
  return result;
}

const Complex Complex::operator-(Complex c1)
{
  Complex result;
  result.re = re - c1.re;
  result.im = im - c1.im;
  return result;
}

const Complex Complex::operator*(Complex c1)
{
  Complex result;
  result.re = re * c1.re - im * c1.im;
  result.im = re * c1.im + im * c1.re;
  return result;
}
const Complex Complex::operator*(double d)
{
  Complex result;
  result.re = re *d;
  result.im = im *d;
  return result;
}
const Complex Complex::operator/(Complex c1)
{
  Complex result;
  result.re = (re * c1.re + im * c1.im) / (c1.re*c1.re + c1.im*c1.im);
  result.im = (im*c1.re - re*c1.im) / (c1.re*c1.re + c1.im*c1.im);
  return result;
}
void Complex::operator*=(Complex c1){
  Complex result;
  result.re = re * c1.re - im * c1.im;
  result.im = re * c1.im + im * c1.re;
  re = result.re;
  im = result.im;
}
void Complex::operator-=(Complex c1){
  re -=c1.re;
  im -= c1.im;
}

const bool Complex::operator>(double d)
{
  if(absv() - abs(d) > 0.00000001){
    return true;
  }else
  {
    return false;
  }
  
}
const bool Complex::operator<(double d)
{
  if(absv() - abs(d) < -0.00000001){
    return true;
  }else
  {
    return false;
  }
  
}

ostream &operator<<(std::ostream &stream, const Complex c1)
{
  stream << "("<<c1.re<<showpos<<c1.im<<noshowpos<<"i)";
  return stream;
}

istream &operator>>(std::istream &stream,  Complex &c1)
{
  cin.ignore (1024, '(');
  stream >> c1.re;
  stream >> c1.im;
  return stream;
}
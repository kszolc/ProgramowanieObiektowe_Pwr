#include <iostream>
#include <fstream>
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

int main()
{
  Vector dana;
  Matrix mat;
  //dana.readFromFile();
  cin >> mat;
  cin >> dana;

  cout << dana;
  cout << mat;
  return 0;
}

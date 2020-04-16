#include <iostream>
#include <fstream>
#include "Vector.hh"
#include "Matrix.hh"
#include "Matrix.hh"
#include "sysLinEq.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */
void loadToSystemOfEq(LinearEq eq, Vector v, Matrix m){
  eq.constTerm = v;
  for (int i =0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      eq.matByLines[i].value[j] = m.value[j][i];
    }
  }
}

int main()
{
  Vector con;
  Matrix mat;
  LinearEq eq;
  //dana.readFromFile();
  cin >> mat;
  cin >> con;

  cout << con;
  cout << mat;
  mat.determinant();
  eq.constTerm = con;
  for (int i =0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      eq.matByLines[i].value[j] = mat.value[j][i];
      eq.cp[i].value[j] = mat.value[j][i];
    }
  }
  eq.compute();


  return 0;
}

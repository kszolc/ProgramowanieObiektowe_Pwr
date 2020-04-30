#pragma once
#include "matrix.hh"
#include "vector.hh"
#include <iostream>

template <typename T, int size>
class SysOfLinEq
{
private:
  Matrix<T, size> mat;
  Vector<T, size> vec;
  

  Vector<T, size> result;
  T det;

  void get(){
    std::cin >> mat;
    std::cin >> vec;
  }


public:

  Vector<T,size> resolve(){
    get();
    det = mat.determinant();

    std::cout << mat;
    std::cout << std::endl;
    std::cout << vec;

    for(int i = 0; i < size;i++){
      
      result.val[i] = mat.put(vec,i) / det;
    }
    std::cout<<std::endl <<"Result:  "<< result <<std::endl;
    return result;

  }

};
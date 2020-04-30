#pragma once
#include <iostream>

template <typename T, int SIZE>
class Vector
{
public:
  T val[SIZE];

  friend std::ostream &operator<<(std::ostream &stream, Vector<T,SIZE> vec){
    
    stream<<"[ " <<vec.val[0];
    for(int i = 1; i<SIZE;i++){
      stream << " , " <<vec.val[i];
    }
    stream<<" ]" << std::endl;
    return stream;
  }
  friend std::istream &operator>>(std::istream &stream, Vector<T,SIZE> &vec){
    //std::cin.ignore (1024, '[');
    for(int i = 0; i<SIZE;i++){
      stream >> vec.val[i];
    }
    
    return stream;
  }

};
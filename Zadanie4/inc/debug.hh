#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "size.hh"

using namespace std;

class Deb{
 public:
 void pr(string message){
  if(debug){
    fstream file;
    if(!file.is_open()) file.open("../debug.txt", ios::out | ios::app);   
    file << message<<endl;
    file.close();
  }
 }
};

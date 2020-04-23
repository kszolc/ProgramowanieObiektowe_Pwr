#pragma once
#include <iostream>
#include <cmath>
#include "debug.hh"

class Com{
    private:
       double error = 0.000001;
    public:
     double re;
     double im;

     const double abs(){
       return sqrt(re * im);
     }

     bool operator==(double val){
         return(abs() < error);
     }
     
     bool operator!=(double val){
         return(abs() > error);
     }


};
#pragma once

#include "Size.hh"
#include "Matrix.hh"
#include "Vector.hh"
#include <iostream>
#include <algorithm>
#include <math.h>

    using namespace std;

class LinearEq{
    private:
        int debug =1;
     
        const double computeLine(int i);
        void errLength(int i);
        void length();
    public:  
        Vector constTerm;
        Vector matByLines[SIZE];
        Vector cp[SIZE];
        Vector result;
        Vector err;
        double errLen;
        void compute();
        

};
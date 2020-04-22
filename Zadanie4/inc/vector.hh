#pragma once
#include <iostream>
#include "size.hh"
#include "debug.hh"
template <typename T>
class Vector{
    public:
    T value[SIZE];
    Deb deb;
    //public:
    void load();
    void print();
};

#include <iostream>
#include "vector.hh"
#include "complex.hh"
template<>
void Vector<double>::load(){
    deb.pr("Loading data to class by vector form");
    for(int i =0; i <SIZE; i++){
        std::cin >> value[i];
        deb.pr(to_string(value[i]));
    }
}
template<>
void Vector<double>::print(){
    deb.pr("printing vector values on stdout");
    for(int i =0; i <SIZE; i++){
       cout << value[i] << "  ";
    }
    cout << endl;
    deb.pr("Done printing");
}

template<>
void Vector<Com>::print(){
    deb.pr("printing vector values on stdout");
    for(int i =0; i <SIZE; i++){
       cout << " ("<<value[i].re<< std::showpos << value[i].im<< std::noshowpos<<") ";
    }
    cout << endl;
    deb.pr("Done printing");

     cin.ignore (1024, '(');
}
template<>
void Vector<Com>::load(){
    deb.pr("Loading data to class by vector form");
    for(int i =0; i <SIZE; i++){
        std::cin.ignore (1024, '(');
        std::cin >> value[i].re;
        std::cin >> value[i].im;

    }
}


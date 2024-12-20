#include <iostream>
#include <string>
#include <cstring>
#include "sysOfLinEq.hh"
#include "complex.hh"
#include "matrix.hh"

#define SIZE 5

using namespace std;



int main(int argc, char** argv){
    if(argc == 2){ // Check if there are 2 arguments
     
        if(!strcmp(argv[1], "r")){
            SysOfLinEq<double, SIZE> sysOfLin;
            sysOfLin.resolve();
        }
        else if (!strcmp(argv[1], "c")){
            SysOfLinEq<Complex, SIZE> sysOfLin;
            sysOfLin.resolve();
        }
        else{ // Arguments are invalid
            cout << "Usage: "<<argv[0]<< " <r/c> (real/complex numbers)"<<endl;
            return 1;
        }

            
    
    }else{ // there is invalid number of arguments
        if(argc == 1){
            
            Matrix<double,2> macierz;
            Complex zesp;

            cin >> macierz;
            cin >> zesp;

            cout <<macierz;
            cout <<endl; 
            cout << zesp;

            cout << endl<< "Abs of Complex: " <<zesp.absv() <<endl <<"Determinant: "<< macierz.determinant();

            cout << endl <<endl;
            /*
            cout << "There are to few arguments!" <<endl;
            cout << "Usage: "<<argv[0]<< " <r/c> (real/complex numbers)"<<endl;
            return 1; */
            return 0;
        }else{
            cout << "There are to much arguments!" << endl;
            cout << "Usage: ./"<<argv[0]<< " <r/c> (real/complex numbers)"<<endl;
            return 2;
        }
    }

}
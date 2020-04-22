#include <iostream>
//#include "debug.hh"
//#include "complex.hh"
//#include "vector.hh"
#include "complexCompute.hh"
#include "realCompute.hh"
#include <cstring>
#include <ctime> 

using namespace std;

/*!
    All magic happens there
*/
int compute(int mode){ 
  // Some stuff for debug 
    Deb deb;
    time_t now = time(0);
    string dt = ctime(&now);
    deb.pr("\nProgram in debug mode ran on:");
    deb.pr(dt);
    deb.pr("\n");

    if(debug) cout << "WARNING! program running in debug mode!" <<endl
                   << "It will make huge debug.txt file full of useless information." << endl 
                   << "To disable it, change CONSTEXPR INT DEBUG to 0 in size.hh file."<<endl <<endl;
    

  //***********************************************//
  //********     Here starts computing    *********//
  //***********************************************//

    // Redirecting to other fucntions according to need

    if(mode ==1){ // Real numbers
        deb.pr("Entering REAL compute function");
        return (reComp());

    }
    else{ // Complex numbers
        deb.pr("Entering COMPLEX compute function");
        return(comComp());

    }
return 0;
}

/*!
    Mainly used for input, all computing happens in: int compute()
*/
int main(int argc, char** argv){
    if(argc == 2){ // Check if there are 2 arguments
     
        if(!strcmp(argv[1], "r")) return(compute(1));
        else if (!strcmp(argv[1], "c")) return(compute(2));
        else{ // Arguments are invalid
            cout << "Usage: "<<argv[0]<< " <r/c> (real/complex numbers)"<<endl;
            return 1;
        }
        
   
    }else{ // there is invalid number of arguments
        if(argc == 1){
            cout << "There are to few arguments!" <<endl;
            cout << "Usage: "<<argv[0]<< " <r/c> (real/complex numbers)"<<endl;
            return 1;
        }else{
            cout << "There are to much arguments!" << endl;
            cout << "Usage: ./"<<argv[0]<< " <r/c> (real/complex numbers)"<<endl;
            return 2;
        }
    }

}

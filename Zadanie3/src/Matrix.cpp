#include "Matrix.hh"

using namespace std;


std::ostream &operator<<(std::ostream &stream, const Matrix &matrix){
    for(int i = 0; i<SIZE;i++){
        stream << "|";
        for(int j = 0; j<SIZE;j++){
            stream << " " << matrix.value[j][i] << " ";
        }
        stream << "|" << endl;
    }
return stream;
}

std::istream &operator>>(std::istream &stream, Matrix &matrix){
  char coma1;
// Look for first bracket
  stream.ignore (1024, '|');

  // Load data into variables
  for(int i=0; i<SIZE; i++){
    for(int j = 0; j<SIZE; j++){
        stream >> matrix.value[j][i] >> coma1; // getting data

        if(coma1 != ',' && j < (SIZE-1)){ // check for commas
            cerr << "Optaining MATRIX data failed! Invalid data type. Make sure your input is formatted correctly." << endl << "Err code: 2" << endl;
             cerr << "Missing , after " << j+1 <<" value of line "<<i+1 <<endl;
            return stream;
        }
    }
    if(coma1 !='|' && i < (SIZE-1)){ // check for missing | at the end of each line
      cerr << "Optaining MATRIX data failed! Invalid data type. Make sure your input is formatted correctly." << endl << "Err code: 2" << endl;
      cerr << "Missing | at the end of line "<<i+1 << endl;
      return stream;
    }
    if(i<(SIZE-1)) stream.ignore (1024, '|'); //ignore all to next | when isnt it end of matrix
   
  }
  
  return stream;
}
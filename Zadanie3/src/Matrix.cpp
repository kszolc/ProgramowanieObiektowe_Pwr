#include "Matrix.hh"


using namespace std;


const Matrix Matrix::hadamard(Matrix m1, Matrix m2){
  Matrix result;
  for(int i = 0; i<SIZE; i++){
    for(int j = 0; j<SIZE; j++){
      result.value[i][j] = m1.value[i][j]*m2.value[i][j];
    }
  }
  return result;
}


std::ostream &operator<<(std::ostream &stream, const Matrix &matrix){
    for(int i = 0; i<SIZE;i++){
       // stream << SIZE;
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
        stream >> matrix.value[i][j] >> coma1; // getting data

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

const bool Matrix::isZero(int num, int num2){
  return (value[num][num2] < 0.00001 && value[num][num2] > -0.00001);
}
double Matrix::mix(){
int debug =0;
int swapCount =0;
    if(debug)  cout <<endl<<"Before" <<endl<< this;
    // Swaping columns
    for(int i = 0; i<SIZE;i++){
      if(isZero(i,i)){
        if(debug) cout << "Diagonal of column " << i << " is zero! Starting looking for replacement"<<endl;
        int j = i;
        bool swap =1;
        int rolls =0;

        do{
         if(debug) cout << "Element "<< i << " " << j << " is " << value[i][j] << endl;
          if(!isZero(i,j)){
           if(debug) cout << "Column " << j << " seems to be a good replacement! Proceeding to swap..." <<endl;
            swap =0;
            swapCount++;
            for(int k=0;k<SIZE;k++) std::swap(value[i][k], value[j][k]);
          }
          j++;
          if(j == SIZE){
            j=0;
            rolls++;
          }
        }while(swap && j < SIZE && rolls <3);
      }
    }
    if(debug)  cout << endl << "After" <<endl<< this << endl << "Swap count: " << swapCount <<endl;
    // Check if all diagonals arent nulls
    for (int i =0;i<SIZE;i++){
      if(isZero(i,i)){ //if yes, proceed another swaping round
       if(debug)   cout << "There is still zero in diagonals! Another round" << endl;
          for(int j =0; j<SIZE; j++){ 
            if(!isZero(i,j)){  // Check if whole column isnt filled with nulls
              if(swapCount % 2 == 0){ // Number of swaps changes positivity of determinant
                return determinant(); // even? Dont change
              }else{ // odd? Change the minus
                return !determinant();
              }
            } 
          }
          // Oh no, whole column have only zeros! There is no determinant. Put this error in stdout
          cout << "Err: There is no determinant! One whole column is all zeros!" << endl;
          return 0;
      }
    }  
}

const double Matrix::determinant(){
  bool debug =0; //Strongly recomended to change it to 0, otherwise terminal will be filled with useless info
  
  int swapCount =0;
   mix();
   auto dataCp = *this;
  if(debug) cout << "Starting making diagonal matrix..."<<endl;
  double multiplier;
  for(int i = 0; i<SIZE-1;i++){
    if(debug) cout << "Before: " << endl << dataCp <<endl;
    for(int j =i+1; j<SIZE;j++){
     if(debug) cout << dataCp.value[i][j] << endl;
      multiplier = dataCp.value[i][j]/dataCp.value[i][i];
      if(debug) cout << "Multiplier " <<j<< " for column " << i << " is " << multiplier <<endl;

      for(int k = 0; k<SIZE;k++){
        dataCp.value[k][j] -= multiplier * dataCp.value[k][i];
      }
      
    }
    if(debug) cout << "After: " << endl << dataCp <<endl;
  }
  double det = 1;
  for (int i = 0; i <SIZE; i++){
    det *= dataCp.value[i][i];
  }
  if(debug) cout << "det = " << det<< endl;
   if(swapCount % 2 == 0){ // Number of swaps changes positivity of determinant
      return det; // even? Dont change
   }else{ // odd? Change the minus
      return !det;
   }
}
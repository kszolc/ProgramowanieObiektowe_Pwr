#include "Vector.hh"


std::istream &operator>>(std::istream &stream, Vector &vec){
  char coma1;
// Look for first bracket
  stream.ignore (1024, '[');

  // Load data into variables
  for(int i=0; i<SIZE; i++){
    stream >> vec.value[i] >> coma1;

    if(coma1 != ',' && i < (SIZE-1)){ // check for commas
      cerr << "Optaining VECTOR data failed! Invalid data type. Make sure your input is formatted correctly." << endl << "Err code: 2" << endl;
      cerr << "Missing , after " << i+1 <<" value!"<<endl;
      return stream;
    }
    if(coma1 !=']' && i == (SIZE-1)){ // check for missing ] at the end of data
      cerr << "Optaining VECTOR data failed! Invalid data type. Make sure your input is formatted correctly." << endl << "Err code: 2" << endl;
      cerr << "Missing ] at the end of vector data " << endl;
      return stream;
    }
  }
  
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const Vector &vec){
  
  stream << endl <<"[";

  for(int i=0; i<SIZE; i++){
    stream << vec.value[i]; // print value
    if(i != SIZE-1){  // check if need of placing comma
      stream << " , ";
    }
  }
  stream << "]" << endl; // end it all
  return stream;
}


Vector Vector::operator +(Vector vec2){
  Vector result;

  for(int i = 0; i < SIZE; i++) result.value[i] = value[i] + vec2.value[i];

  return result;
}



Vector Vector::operator/(double num){
  Vector result;
  for(int i = 0; i < SIZE; i++) result.value[i] = value[i] *num;
  return result;
}


double Vector::operator *(Vector vec2){
  double result = 0;
  for(int i = 0; i < SIZE; i++) result += value[i] * vec2.value[i];
  return result;
}


int Vector::readFromFile(){
  ifstream dataFile;


  // Open file with data in it
  dataFile.open ("Data.txt");

  //Check if file opened succesfully
  if (!dataFile.is_open()){
    cerr << "Could not open file!"<<endl<<" Err: 1";
    return 1;
  }

  dataFile >> *this;
  return 0;

}

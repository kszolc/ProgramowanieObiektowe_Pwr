#include "sysLinEq.hh"

using namespace std;

Vector operator -(Vector vec1,Vector vec2){
  Vector result;

  for(int i = 0; i < SIZE; i++) result.value[i] = vec1.value[i] - vec2.value[i];

  return result;
}

Vector operator *( double num, Vector vec){
  Vector result;
  for(int i = 0; i < SIZE; i++) result.value[i] = vec.value[i] *num;
  return result;
}


const double LinearEq::computeLine(int i){
    double sum=0;
    for(int j=0;j<SIZE;j++){
        
        sum += matByLines[i].value[j];
        if(debug) cout << "Sum of line: " << i << " element: " << j<< " value: " << sum<<endl;
    }
    return constTerm.value[i]*sum;
}
void LinearEq::errLength(int i){
    err.value[i] =0;
    for(int j=0;j<SIZE;j++){
        err.value[i] += cp[i].value[j] * result.value[i];
        if(debug) cout << err.value[i] <<endl;
    }
    err.value[i] -= constTerm.value[i];
}

 void LinearEq::length(){
    errLen =1;
    for(int i =0; i<SIZE;i++){
        if(err.value[i]<0) err.value[i] *=-1;
        if(debug) cout<<"error: " << err.value[i]<<endl;
        errLen *= err.value[i];
    }
    errLen = sqrt(errLen);
}

 void LinearEq::compute(){
     if(debug) cout << endl <<endl << "COMPUTING LINEAR EQUATION" << endl << endl;
     if(debug){
         for(int i=0;i<SIZE;i++){
             cout << matByLines[i];
         }
         cout << constTerm;
     }
    for(int i =0; i<SIZE-1;i++){
      
        for (int j=i+1;j<SIZE;j++){
            double mul = matByLines[j].value[i] / matByLines[i].value[i];
            if(debug) cout << "multiplier of line nr " << i << " is " << mul <<endl;
            if(debug) cout << matByLines[j].value[i] << " "<< matByLines[i].value[i] << endl;
            
           matByLines[j]= matByLines[j]-mul*matByLines[i];
            
           constTerm.value[j] -= mul*constTerm.value[i];
           if(debug) cout << "new value of ["<<i<< j <<"] is "<< matByLines[j]<<endl;
           if(debug) cout << "new value of const ["<< j <<"] is "<< constTerm.value[j]<<endl;
        }
        for (int k=i+1;k<SIZE;k++){
            double mul = matByLines[k+1].value[k] / matByLines[k].value[k];
            if(debug) cout << "multiplier of line nr " << k << " is " << mul <<endl;
            if(debug) cout << matByLines[k+1].value[k] << " "<< matByLines[k].value[k] << endl;
            
           matByLines[k+1]= matByLines[k+1]-mul*matByLines[k];
            
           constTerm.value[k+1] -= mul*constTerm.value[k];
           if(debug) cout << "new value of ["<<k<< k+1 <<"] is "<< matByLines[k+1]<<endl;
           if(debug) cout << "new value of const ["<< k+1 <<"] is "<< constTerm.value[k+1]<<endl;
        }
        
      
    }
    
    if(debug){
        for(int i=0;i<SIZE;i++){
            cout << matByLines[i];
        }
        cout << constTerm;
    }
    for(int i =SIZE-1;i>=0;i--){
            if(debug) cout << endl<<  "Line " << i << " before \n\n" << matByLines[i]<< "    " <<constTerm.value[i]<<endl;
            for(int k=SIZE-1;k>i;k--){
                matByLines[i].value[k] = matByLines[i].value[k] * result.value[k];
            }
            double sum=0;
            for(int l = SIZE-1; l>=i;l--){
                sum += matByLines[i].value[l];
                if(debug) cout << "Sum = " <<sum <<endl;
            }
            result.value[i] = constTerm.value[i]/sum;
            if(debug) cout << "Line " << i << " result " <<result.value[i] <<endl;
        
       
    }
    for (int m =0;m<SIZE;m++){
        errLength(m);
    }
    
     length();
    cout << "Wynik to: " << result<< endl << "Wektor bledu: " <<err<<endl<<"Dlugosc wektora bledu: " <<errLen<<endl;
}
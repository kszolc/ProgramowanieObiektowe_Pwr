#include "realCompute.hh"
#include "vector.hh"

int reComp(){
    Deb deb; // only for debug purposes
    deb.pr("We are in reComp function");

    Vector<double> constTerm;
    Vector<double> matrix[SIZE];
    Vector<double> result;

    // ****************************** //
    // **** LOADING AND PRINTING **** //
    // ****************************** //

    // load matrix
    for(int i=0;i<SIZE;i++){
        matrix[i].load();
    }

    constTerm.load(); // load constant term vector
    cout << "Constant term vector: ";
    constTerm.print();
    cout << endl << "Matrix: " <<endl;;

    // printing matrix in correct order
    for(int i = 0;i<SIZE;i++){
        for(int j =0;j<SIZE;j++){
            cout << matrix[j].value[i] << "  ";
        }
        cout << endl;
    }


    cout << endl;


    // ****************************** //
    // *** Making diagonal matrix *** //
    // ****************************** //

    double div = 1;

    for(int i=0;i<SIZE-1;i++){ //columns = array number    
        for(int j=i+1;j<SIZE;j++){ // lines = vectors
            //divider of each line
            div = matrix[i].value[j] / matrix[i].value[i]; 
            deb.pr("Divider of column: "+to_string(i)+" line: "+to_string(j)+" is: "+to_string(div) + "  (i,i variable: "+to_string(matrix[i].value[i])+ " ji variable: "+to_string(matrix[j].value[i])+" )");

            /********* CONSTANT TERM COMPUTE ********/
            deb.pr("computing constant term nr: "+to_string(j));
            deb.pr(to_string(constTerm.value[j])+" - "+ to_string(div* constTerm.value[i]));
            constTerm.value[j] -= div* constTerm.value[i];
            deb.pr("Constant term is: "+to_string(constTerm.value[j])+"\n");

            /******** MATRIX VALUES ****************/
            for(int k=0;k<SIZE;k++){ // differencing line number J, column K
                deb.pr("\n"+to_string(matrix[k].value[j])+" - "+to_string(div * matrix[k].value[i]));
                matrix[k].value[j] -= div * matrix[k].value[i];
                deb.pr("Value nr: "+to_string(k) + " is now: "+to_string(matrix[k].value[j]));
            }
            
          
        }

    }
    // ********************************* //
    // ********* RESOLVING ************* //
    // ********************************* //

    double mul;
    double sum;
    deb.pr("Starting to resolve");
    for(int i = SIZE-1;i>=0;i--){ // lines
        sum =0;
        for(int j = SIZE-1; j>=i; j--){ //columns

            // **** MULTIPLY ARGUMENT BY ITS RESULT ****//
            if(j==i) mul = matrix[j].value[i];
            else mul = matrix[j].value[i] * result.value[j];
        
            deb.pr(to_string(i)+to_string(j));   
            deb.pr("suma "+to_string(sum)+" + value "+to_string(matrix[j].value[i])+" * result "+to_string(result.value[j]));

            sum += mul;   // Add multipleid argument to sum of the line
        }

        // ***** SET RESULT IN VECTOR ******// 
        result.value[i] = sum / constTerm.value[i];
        deb.pr("sum "+to_string(sum));
        deb.pr("new result "+to_string(result.value[i]));
        deb.pr("new line");
    }
    cout <<endl << "Result vector: ";
    
    result.print();
    return 0;
    
}
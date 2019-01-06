#include <stdio.h>

#include "matrix.h"


int main(){
    
 
    
    //ввод последовательности
    double *s  = new double[6];
    int i;
    for(i = 0; i < 6; i++)
        s[i] = i;
    //конец ввода последовательности
    
    
    
    
    
    Matrix f(3, 2);
    Matrix g(3, 2);
    f.ChangeMatrixInRows(s);
    g.ChangeMatrixInRows(s);
    f -= g;
    g.PrintMatrix();
    f.PrintMatrix();
    g.~Matrix();//release of memory
    f.~Matrix();//release of memory
    
    
}


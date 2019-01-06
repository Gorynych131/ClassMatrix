#include <stdio.h>

#include "matrix.h"


/* 
 * 
 * 
 * 
 *  НЕ РАБОТАЕТ 
 *              УЗНАТЬ ПОЧЕМУ
 * 
 * 
 * 
Matrix::Matrix()//конструктор ввода матрицы с клавиатуры
{
     
    printf("Enter number of columns: ");
    scanf("%d", &N);//кол-во столбцов
    printf("Enter number of rows: ");
    scanf("%d", &M);// кол-во строк
    printf("next");
    
    a = new double[ N * M ];
    int i;    
    for(i = 0; i < N * M ; i++){
        scanf("%lf\n", &a[i]);
    }
}
*/



/*  correct   */
Matrix::Matrix()
{
    N = 1;
    M = 1;
    
    a = new double[1];
    a[0] = 0.;
    
}


/*  correct  */
Matrix::Matrix(bool s, int n, int m) 
{
    if (s){
       
        N = n;
        M = m;
        
        a = new double[N * M];//get memory
        int  i; int j = 0;
        for(i = 0; i < N * M; i++)
            a[i] = 0.;
        for( i = 0; i < N; i++){
            a[i + j * M] = 1;
            j++;
        }
        
    }
    else{
        
        N = n;
        M = m;
    
        a = new double[N * M];
        int i;
        for( i = 0; i < N * M; i++)
            a[i] = 0.;
    }
}



/*  correct   */
Matrix::Matrix(int n, int m)//создание нулевой матрицы(конструктор) заданного размера
{
    
    N = n; M = m;
    a = new double[ N * M ];
    int i;    
    for(i = 0; i < N * M; i++)
        a[i] = 0.;
    
}

Matrix::~Matrix()
{
    delete[] a;
}


/*  correct   */
void Matrix::ChangeValue(double value, int i, int j)// i - row, j - column
{
    
    a[j + i * M] = value;
    
}

/*  correct  */
void Matrix::ChangeMatrixInRows(double *array){
    int i; int j;
    for( i = 0; i < N; i++){
        for( j = 0; j < M; j++){
            ChangeValue(array[i * M + j], i, j);
        }
    }
}


/*  correct   */
void Matrix::ChangeMatrixInCols(double *array){
    int i; int j;
    for( i = 0; i < N; i++){
        for( j = 0; j < M; j++){
            ChangeValue(array[i + j * N], i, j);
        }
    }
}


Matrix& Matrix::operator=(const Matrix& mat)
{
    
    int i;
    for(i = 0; i < N * M; i++)
        a[i] = mat.a[i];
    return *this;
}

/*  correct  */
Matrix Matrix::operator+(Matrix& mat)//sum of matrix
{
    
    static Matrix res(mat.N, mat.M);
    int i;
    for(i = 0; i < mat.N * mat.M; i++)
        res.a[i] = a[i] + mat.a[i];
    
    return res;
    
}


/*  correct  */
Matrix& Matrix::operator+=(const Matrix& mat)
{
    
    int i;
    for(i = 0; i < N * M; i++)
        a[i] = a[i] + mat.a[i];
    return *this;
    
}


/*  correct  */
Matrix Matrix::operator*(double c)
{
    
    static Matrix res(N, M);
    int i;
    for(i = 0; i < N * M; i++)
        res.a[i] = c * a[i];
    
    return res;
    
}


/*  correct  */
Matrix Matrix::operator-(Matrix& mat)
{

    static Matrix res(N, M);
    int i;
    for(i = 0; i < mat.N * mat.M; i++)
        res.a[i] = a[i] - mat.a[i];
    
    return res;
    
}


/*  correct  */
Matrix& Matrix::operator-=(const Matrix& mat)
{
    
    int i;
    for(i = 0; i < N * M; i++)
        a[i] = a[i] - mat.a[i];
    return *this;
    
}

/**///доделать
Matrix operator*(Matrix& mat)
{
    
    
    int i; int j;
    for( i = 0; i < N; i++){
        for( j = 0; j < M; j++){
            

/*   correct  */
double Matrix::GetValue(int i, int j)
{
    
    return a[i * M + j];
    
}


/*  correct   */
int Matrix::GetRows()
{
    return N;
}


/*  correct   */
int Matrix::GetCols()
{
    return M;    
}


/*  correct   */
void Matrix::PrintMatrix()//print matrix
{
    printf("\n");
    printf("Matrix:\n");
    
    int i; int k;
    if( N * M == 0){
        printf("  %lf\n", a[0]);
    }
    else{
    for( i = 0; i < N; i++){
        printf("    ");
        for( k = 0; k < M; k++){
            printf("%lf   ", a[i * M + k]);
        }
        printf("\n");
    }
    printf("\n");
    }
}







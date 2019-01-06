#ifndef MATRIX_H
#define MATRIX_H


/*
*/

/*
уже сделано:
1)создание матрицы
2)вывод матрицы
3)записать 1 или массив объектов
4)взять элемент

что можно добавить:
-сумма
-детерминант
-произведение



*/
class Matrix
{
public:
	/* variables */
	
	int N;//number of rows
	int M;//number of columns

	double *a; //values of matrix


	/* 	constructors	*/

	Matrix();//default--constructor (builds matrix of 1 zero element)
	Matrix(bool s, int n, int m);//constructor of E and 0
	Matrix(int n, int m);//size--constructor
	
	~Matrix();//delete matrix
		
	
	
	/*	Evolution	*/
	
	void ChangeValue(double value, int i, int j);//evolution of 1 cell
	void ChangeMatrixInRows(double *array);
	void ChangeMatrixInCols(double *array);
	
	
	
	
	Matrix& operator=(const Matrix& mat);
	Matrix operator+(Matrix& mat);
	Matrix& operator+=(const Matrix& mat);
	Matrix operator*(double c);
	Matrix operator-(Matrix& mat);
	Matrix& operator-=(const Matrix& mat);
	Matrix operator*(Matrix& mat);
	
	/*	Getting values	*/
	
	void PrintMatrix();//print matrix
	
	double GetValue(int i, int j);
	//get number of rows and columns
	int GetRows();
	int GetCols();
	
    
};

#endif

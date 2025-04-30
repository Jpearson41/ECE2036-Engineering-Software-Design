#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "complex.h"
#include <string>
#define MATRIX_FIELD 30

using namespace std;

//This is a class prototype to let the compiler know
//that I intend to define a class Matrix. It is needed
//for the global function definition that I put before
//the class Matrix as an example in this lab.
class Matrix;
ostream& operator<< (ostream &, const Matrix &);
Matrix operator*(Complex, const Matrix &);
Matrix operator*(const Matrix &, Complex);
Matrix operator*(const Matrix &, const Matrix &);

class Matrix
{
friend ostream& operator<< (ostream &, const Matrix &);
friend Matrix operator*(Complex, const Matrix &);
friend Matrix operator*(const Matrix &, Complex);
friend Matrix operator*(const Matrix &, const Matrix &);
//you put stuff in here!
public:
//Constructors
	Matrix();
	Matrix(int numRows, int NumColumns);

//Non-operator Mem-funcs
	void printMatrix();            
	Matrix & transpose();

//Rule of Three Overloads
	Matrix & operator=(const Matrix & RHS);          //Assignment Operator Overload
	Matrix & operator=(Matrix *RHS);
	
	//Matrix& operator=(Matrix* RHS);
	Matrix(const Matrix &);              //Copy Constructor
	~Matrix();                           //Destructor
//Additional Operator Overloads
	Complex & operator()(int,int);
	Matrix operator+(const Matrix & RHS);
	Matrix operator-(const Matrix & RHS);
	Matrix operator~();     //return a copy of transposed matrix
	Matrix operator!();


private:
	int numOfRows;        //Number of Rows
	int numOfColumns;     //Number of Column
	Complex * beginPtr; //Ptr to Array of ComplexNums



};

#endif
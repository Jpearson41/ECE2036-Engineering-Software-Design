#include "matrix.h"
#include "complex.h"
#include <iostream>
#include <iomanip>

//Matrix class implementations

//Constructors
Matrix::Matrix() {
	this->numOfRows = 0;
	this->numOfColumns = 0;
	this->beginPtr = NULL;
}
Matrix::Matrix(int numRows, int numColumns) {
	this->numOfRows = numRows;
	this->numOfColumns = numColumns;
	//Dynamically Allocate Array with 
	int size = numRows * numColumns;
	beginPtr = new Complex[size];
	for (int i = 0; i < size; i++) {
		beginPtr[i] = Complex();          //Fill Array with zero'd ComplexNums
	}
}
//Destructor
Matrix::~Matrix() {
	delete[] beginPtr;                    //Deallocate Array of ComplexNums
}

//Copy Constructor
Matrix::Matrix(const Matrix & arrayToCopy) {
	int size = arrayToCopy.numOfRows * arrayToCopy.numOfColumns;
	this->beginPtr = new Complex[size];
	this->numOfColumns = arrayToCopy.numOfColumns;
	this->numOfRows = arrayToCopy.numOfRows;
	for (int i = 0 ; i < size; i++) {
		this->beginPtr[i] = arrayToCopy.beginPtr[i];
	}
}

//Non Operator Mem Functions
void Matrix::printMatrix() {
	//Goal is to Print entire Matrix
	int numRows = this->numOfRows;
	int numCols = this->numOfColumns;

	int size = numRows * numCols;
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (counter == numCols) {
			cout << "\n" << endl;
			counter = 0;
		}
		double real = this->beginPtr[i].getReal();
		double imag = this->beginPtr[i].getImag();
		//Print real and complex values of ComplexNum in Matrix
		//First check for no real or imag values
		if (real == 0 && imag == 0) {
			cout << setprecision(7) << real;
			cout << "           ";
		}else if (imag == 0) {
			cout << setprecision(7) << real;
			cout << "           ";
		//Then check to see if complex is negative or not
		}else if (real == 0) {
			cout << setprecision(7) << imag << "j";
			cout << "           ";
		}else if (imag < 0) {
			cout << setprecision(7) << real << "-" << setprecision(7) << imag << "j";
			cout << "           ";
		}else {
			cout << setprecision(7) << real << "+" << setprecision(7) << imag << "j";
			cout << "           ";
		}
		
		counter++;
	}

}

Matrix & Matrix::transpose() {
	//Goal is to convert matrix to transpose
	int numRows = this->numOfRows;
	int numCols = this->numOfColumns;

	int size = numRows * numCols;
	Matrix trans(numCols,numRows);    //created flipped matrix
	//First check to make sure matrix contains val
	for (int i = 0; i < numRows; i++) {
		for (int k = 0; k < numCols; k++) {
			int oldIndex = i * numCols + k;
			int newIndex = k * numRows + i;
			trans.beginPtr[newIndex] = this->beginPtr[oldIndex];     //copy transpose of matrix into trans matrix
		}
	}
	for (int i = 0; i < size; i++) {
		this->beginPtr[i] = trans.beginPtr[i];                       //copy trans matrix into this matrix to return
	}
	this->numOfRows = numCols;        //Flip # of columns and rows
	this->numOfColumns = numRows;       
	return(*this);     //return reference to transposed matrix

}

//Mem-func Operator Overloads
//Assignment Operator
Matrix & Matrix::operator=(const Matrix & RHS) {
	//if (&RHS != this) {
	int sizeLHS = this->numOfRows * this->numOfColumns;
	int sizeRHS = RHS.numOfRows * RHS.numOfColumns;		
	if (sizeLHS != sizeRHS) {
		delete[] this->beginPtr;
		this->beginPtr = new Complex[sizeRHS];
		this->numOfRows = RHS.numOfRows;
		this->numOfColumns = RHS.numOfColumns;
		for (int i = 0; i < sizeRHS; i++)
			this->beginPtr[i] = RHS.beginPtr[i];
		return(*this);
	}else {
		for (int i = 0; i <sizeRHS; i++) {
			this->beginPtr[i] = RHS.beginPtr[i];
		}
		return(*this);
	}
	//}
	//return(*this);
}
//Assignment Operator 2
Matrix& Matrix::operator=(Matrix *RHS) {
	//if (RHS != this) {
	int sizeLHS = this->numOfRows * this->numOfColumns;
	int sizeRHS = (*RHS).numOfRows * (*RHS).numOfColumns;
	if (sizeLHS != sizeRHS) {
		delete[] this->beginPtr;
		this->beginPtr = new Complex[sizeRHS];
		for (int i = 0; i < sizeRHS; i++) {
			this->beginPtr[i] = (*RHS).beginPtr[i];
		}
		return(*this);
	}else {
		for (int i = 0; i <sizeRHS; i++) {
			this->beginPtr[i] = (*RHS).beginPtr[i];
		}
		return(*this);
	}
	//}
	//return(*this);
}
//Parentheses Overload
Complex & Matrix::operator()(int row, int column) {
	int index = ((row-1) * this->numOfColumns) + column;
	//Complex & result = this.beginPtr[index - 1];
	return(this->beginPtr[index-1]);
}
//Addition Operator
Matrix Matrix::operator+(const Matrix & RHS) {
	//Goal is to add matrices elements
	int sizeLHS = this->numOfRows * this->numOfColumns;
	//Create new Matrix to return copy of
	Matrix addition(this->numOfRows, this->numOfColumns);
	int sizeRHS = RHS.numOfRows * RHS.numOfColumns;
	if (sizeLHS == sizeRHS) {
		for (int i = 0; i < sizeLHS; i++) {
			addition.beginPtr[i] = this->beginPtr[i] + RHS.beginPtr[i];
		}
		return (addition);
	}
	//If operator cannot be implemented, return zero'd out matrix
	addition = Matrix();
	cout << "Matrix Mismatch Error!" << endl;
	return (addition);
}
//Subtraction Operator
Matrix Matrix::operator-(const Matrix & RHS) {
	//Goal is to subtract matrices elements
	//create new Matrix to return copy of
	Matrix difference(this->numOfRows, this->numOfColumns);
	if (&RHS != this) {
		int sizeLHS = this->numOfRows * this->numOfColumns;
		//Create new Matrix to return copy of
		int sizeRHS = RHS.numOfRows * RHS.numOfColumns;
		if (sizeLHS == sizeRHS) {
			for (int i = 0; i < sizeLHS; i++) 
				difference.beginPtr[i] = difference.beginPtr[i] - RHS.beginPtr[i];
			return (difference);
		}
		//If operator cannot be implemented, return zero'd out matrix
		difference = Matrix();
		cout << "Matrix Mismatch Error!" << endl;
		return(difference);
	}
	//If the operation is being called on the same 2 Matrices, print out zero
	int sizeRHS = RHS.numOfRows * RHS.numOfColumns;
	for (int i = 0; i < sizeRHS; i++) {
		difference.beginPtr[i] = Complex(0,0);
	}
	return(difference);
	
}
//Tilda Operator
Matrix Matrix::operator~() {
	//Goal is to return copy of transpose of matrix
	int numRows = this->numOfRows;
	int numCols = this->numOfColumns;
	//Create new Matrix to return copy of
	Matrix trans(numCols,numRows);    //created flipped matrix
	int size = numRows * numCols;
	int oldIndex = 0, newIndex = 0;
	for (int i = 0; i < numRows; i++) {
		for (int k = 0; k < numCols; k++) {
			oldIndex = i * numCols + k;
			newIndex = k * numRows + i;
			
			trans.beginPtr[newIndex] = this->beginPtr[oldIndex];
		}
	}
	return(trans);     //return transpose copy of matrix
	

}
//Exclamation Point Operator
Matrix Matrix::operator!() {
	//Goal is to return copy of conjugate transpose matrix
	//Create new Matrix to return copy of
	Matrix ctrans = *this;
	ctrans = ~ctrans;               //take tranpose of ctrans
	int size = this->numOfRows * this->numOfColumns;
	for (int i = 0; i < size; i++) {
		if (ctrans.beginPtr[i].getImag() != 0) {
			int temp = ctrans.beginPtr[i].getImag();
			temp = temp * -1;
			ctrans.beginPtr[i].setImag(temp);
		}
	}
	return ctrans;     //return conjugated transpose copy of matrix

}

//Non-mem func Operator Overloads
ostream & operator<< (ostream & output, const Matrix & matrix) {
	int numRows = matrix.numOfRows;
	int numCols = matrix.numOfColumns;

	int size = numRows * numCols;
	int counter = 0;
	if ((numRows + numCols) == 0) {
		output << "This matrix has zero elements!" <<endl;
		return(output);
	}
	for (int i = 0; i < size; i++) {
		if (counter == numCols) {
			output << "\n" << endl;
			counter = 0;
		}
		double real = matrix.beginPtr[i].getReal();
		double imag = matrix.beginPtr[i].getImag();
		//Print real and complex values of ComplexNum in Matrix
		if (real == 0 && imag == 0) {
			output << setprecision(7) << 0.000000;
			output << "           ";
		}else if (imag == 0) {
			output << setprecision(7) << real;
			output << "           ";
		//Then check to see if complex is negative or not
		}else if (real == 0) {
			output.precision(7); 
			output<< fixed << imag << "j";
			output << "           ";
		}else if (imag < 0) {
			output << setprecision(7) << real << setprecision(7) << imag << "j";
			output << "           ";
		}else {
			output << setprecision(7) << real << "+" << setprecision(7) << imag << "j";
			output << "           ";
		}
		
		counter++;
	}
	return output;

}
//Multiplied by Complex number on left side
Matrix operator*(Complex comNum, const Matrix & matrix) {
	//Goal is to multiply a matrix by a complex number
	Matrix product(matrix.numOfRows, matrix.numOfColumns);
	double numReal = comNum.getReal();
	double numImag = comNum.getImag();
	int size = matrix.numOfColumns * matrix.numOfRows;
	for (int i = 0; i < size; i++) {
		double matrixReal = matrix.beginPtr[i].getReal();
		double matrixImag = matrix.beginPtr[i].getImag();

		double newReal = (numReal * matrixReal) + (-1*numImag * matrixImag);
		double newImag = ((numImag * matrixReal) + (numReal * matrixImag));
		product.beginPtr[i] = Complex(newReal, newImag);
	}
	return(product);
}

//Multiplied by Complex number on right side
Matrix operator*(const Matrix & matrix, Complex comNum) {
	//Goal is to multiply a matrix by a complex number
	Matrix product(matrix.numOfRows, matrix.numOfColumns);
	double numReal = comNum.getReal();
	double numImag = comNum.getImag();
	int size = matrix.numOfColumns * matrix.numOfRows;
	for (int i = 0; i < size; i++) {
		double matrixReal = matrix.beginPtr[i].getReal();
		double matrixImag = matrix.beginPtr[i].getImag();

		double newReal = (numReal * matrixReal) + (-1*numImag * matrixImag);
		double newImag = (numImag * matrixReal) + (numReal * matrixImag);
		product.beginPtr[i] = Complex(newReal, newImag);
	}
	return(product);
}

//Matrix mulitplied by another Matrix
Matrix operator*(const Matrix & matrix1, const Matrix & matrix2) {
	//Goal is to multiply matrices by one another
	int sizeM1 = matrix1.numOfRows * matrix1.numOfColumns;
	int sizeM2 = matrix2.numOfRows * matrix2.numOfColumns;
	int rows1 = matrix1.numOfRows;
	int rows2 = matrix2.numOfRows;
	int cols1 = matrix1.numOfColumns;
	int cols2 = matrix2.numOfColumns;

	Matrix mProduct(matrix1.numOfRows, matrix2.numOfColumns);

/*if (sizeM1 == sizeM2) {
		for (int i = 0; i < sizeM1; i++) {
			mProduct.beginPtr[i] = matrix1.beginPtr[i] * matrix2.beginPtr[i];
		}

		return (mProduct);
	}else*/
	if (matrix1.numOfColumns == matrix2.numOfRows) {
		//Calculate dot product
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols2; j++) {
				Complex sum(0,0);
				for (int k = 0; k < cols1; k++) {
					sum = sum + matrix1.beginPtr[i * cols1 + k] * matrix2.beginPtr[k * cols2 + j];
				}
				mProduct.beginPtr[i *cols2 + j] = sum;
			}
		}
		return(mProduct);
	}else {

		//If operator cannot be implemented, return zero'd out Matrix 
		mProduct = Matrix();
		cout << "Matrix Mismatch Error!" << endl;
		return (mProduct);
	}
}

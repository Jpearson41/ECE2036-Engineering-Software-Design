#include "complex.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Class Implementations
//Constructors
Complex::Complex() {
	this->setReal(0.000000);
	this->setImag(0.000000);
	this->setNaN(1);      //Deafult = 1, 0 if not a number
}
Complex::Complex(double real, double imag) {
	this->setReal(real);
	this->setImag(imag);
	this->setNaN(1);
}
Complex::Complex(double real) {
	this->setReal(real);
	this->setImag(0.000000);
	this->setNaN(1);
}

//Display Functions
void Complex::displayPolar() {
	if (this->getNaN() != 0) {
		double real = this->getReal();
		double imag = this->getImag();
		cout << setprecision(7) << real << " < " << setprecision(7) << imag << endl;
	}else {
		cout << "NaN"<<endl;
	}
	
}
void Complex::displayRect() {
	if (this->getNaN() != 0) {
		double real = this->getReal();
		double imag = this->getImag();
		cout << setprecision(7) << real << " + " << setprecision(7) << imag << "j" <<endl;
	}else {
		cout << "NaN" << endl;
	}
}

//Gettters
double Complex::getReal() {
	return this->real;
}
double Complex::getImag() {
	return this->imag;
}
bool Complex::getNaN() {
	return this->NaN;
}
//Setters
void Complex::setReal(double r) {
	this->real = r;
}
void Complex::setImag(double i) {
	this->imag = i;
}
void Complex::setNaN(int num) {
	this->NaN = num;
}
void Complex::setComplex(double num1, double num2) {
	this->real = num1;
	this->imag = num2;
}

//Operator Overloads
Complex Complex::operator+(Complex RHS)
{
	Complex sum;
	sum.real = this->getReal() + RHS.getReal();
	sum.imag = this->getImag() + RHS.getImag();
	sum.NaN = 1;
	return(sum);
}
Complex Complex::operator-(Complex RHS)
{
	Complex difference;
	difference.real = this->getReal() - RHS.getReal();
	difference.imag = this->getImag() - RHS.getImag();
	difference.NaN = 1;
	return(difference);
}
Complex Complex::operator*(Complex RHS) 
{
	Complex product;
	product.real = (this->getReal() * RHS.getReal()) + (this->getImag() * RHS.getImag() * -1);
	product.imag = (this->getImag() * RHS.getReal()) + (this->getReal() * RHS.getImag());
	product.NaN = 1;
	return(product);

}
Complex Complex::operator/(Complex RHS)
{
	Complex quotient;
	if (RHS.getReal() == 0 || RHS.getImag() == 0) {
		quotient.NaN = 0; //Not a number
		quotient.real = 0;
		quotient.imag = 0;
		return(quotient);
	}else {
		quotient.real = this->getReal() / RHS.getReal();
		quotient.imag = this->getImag() / RHS.getImag();
		quotient.NaN = 1;
		return(quotient);
	}
	
}
//Non-mem func Operator Overloads
ostream & operator<< (ostream & output, const Complex & comNum) {
	if (comNum.NaN != 0) {
		double real = comNum.real;
		double imag = comNum.imag;
		output << setprecision(7) << real << " + " << setprecision(7) << imag << "j" <<endl;
		return output;
	}else {
		output << "NaN"<<endl;
		return output;
	}

}

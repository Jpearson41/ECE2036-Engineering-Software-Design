#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex;
ostream& operator<< (ostream &, const Complex &);

class Complex
{
public:
	//Constructors
	Complex();                //default
	Complex(double real, double imag);
	Complex(double real);     //Purely real

	//Opeartor Overloads
	friend ostream& operator<< (ostream &, const Complex &);
	Complex operator+(Complex);
	Complex operator-(Complex);
	Complex operator*(Complex);
	Complex operator/(Complex);

	//Display functions
	void displayPolar();               //Need to implement
	void displayRect();				   //Need to implement
	//Getters
	double getReal();
	double getImag();
	bool getNaN();

	//Setters
	void setComplex(double, double);    //Need to implement
	void setReal(double);
	void setImag(double);
	void setNaN(int);

private:
	double real;
	double imag;
	bool NaN;        //Not a number -> true if try to divide by zero
};

#endif

/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath> //To use "pow"
#include <vector>


// ADD implementation of the member functions for class Polynomial
Polynomial(const std::vector<double>& coeffs) : coeffecients(coeffs) {};

Polynomial(double& realConstant) : coeffecients(realConstant) {};

Polynomial(Polynomial& toBeCopied) : Polynomial(toBeCopied) {};

void operator=(Polynomial setAs) {
	this.clone()
}




double Polynomial::operator()(double d) const{ //Const, operator() should not modify the calling Polynomial
    double sum = 0;

    //Maxs kod
    /*for (int i = 0; i < std::ssize(this->coeff);i++) {
        sum += this->coeff[i] * pow(x, i);
    }*/

    //Vår kod
    for (int i = 0; i < (*this).coeffecients.size(); i++) {
        sum += (*this)[i] * std::pow(d, i);
    }
    return sum;
}

double Polynomial::operator[](int index) {
    return (*this).coeffecients[index]; //Samma detta?: 	return this->coeff[index];


}

/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"

#include <vector>


// ADD implementation of the member functions for class Polynomial
Polynomial(const std::vector<double>& coeffs) : coeffecients(coeffs) {};

Polynomial(double& realConstant) : coeffecients(realConstant) {};

Polynomial(Polynomial& toBeCopied) : Polynomial(toBeCopied) {};

void operator=(Polynomial setAs) {
	this.clone()
}

double Polynomial::operator()(double d) {
    double sum = (*this)[0];
    for (int i = 1; i < (*this).coeffecients.size(); i++) {
        sum += (*this)[i] * std::pow(d, i);
    }
    return sum;
}

double Polynomial::operator[](int index) {
    return (*this).coeffecients[index];
}

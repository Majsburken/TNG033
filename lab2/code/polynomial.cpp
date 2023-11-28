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
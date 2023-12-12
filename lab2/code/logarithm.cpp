/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include "vector"

// ADD implementation of the member functions for class Logarithm

Logarithm::Logarithm() : c1{ 0.0 }, c2{ 1.0 }, E{ new Polynomial{std::vector<double> {0.0,1.0}} } {
}


Polynomial* Polynomial::clone() const {
  
}

double Polynomial::operator()(double d) const { //Const, operator() should not modify the calling Polynomial
  
}
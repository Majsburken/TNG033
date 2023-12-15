/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"

#include <string>

#include <vector>


//Constructor
Polynomial::Polynomial(const int coeff, const int deg) : coefficients_table{ {coeff,deg} } {
}

Polynomial::Polynomial(int i): coefficients_table{{i,0}}{
}

//default constructor?
Polynomial::Polynomial() : coefficients_table{ {0,0} } {
}


Polynomial::Polynomial(const std::vector<term>& ppairs) {
	for (term t : ppairs) {
		coefficients_table{ t };
	}
}



Polynomial::operator std::string() const {
	std::string s;

	return s;
}

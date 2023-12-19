/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>


//Constructor
Polynomial::Polynomial(const int deg, const int coeff) {
	if (coeff != 0) {
		coefficients_table = {{deg,coeff}};
	};
}

Polynomial::Polynomial(const int i): coefficients_table{{0,i}}{
}

//constructor takes in vector
 Polynomial::Polynomial(const std::vector<term>& ppairs){
//                                                                      destination
//              begin           end              (insert     in container      container destination)
    std::copy(ppairs.begin(), ppairs.end(), std::inserter(coefficients_table, coefficients_table.begin()));
 }


//Output Format: "-8X^0 + 2X^1 - 5X^2 + 1X^6"
Polynomial::operator std::string() const {
	std::string s;

	//Returns string '0' if there is no Polynomial
	if (std::ssize(coefficients_table) == 0) {
		return std::string("0");
	}

	for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
		if (it == coefficients_table.begin()) {
			//std::to_string because it-> second and first are ints
			s += std::to_string(it->second) + "X^" + std::to_string(it->first);
		}
		else{
			if (it->second < 0) {
				s += " - ";
			}
			else {
				s += " + ";
			}
			s += std::to_string(abs(it->second)) + "X^" + std::to_string(it->first);
		}
	}
	return s;
}

int Polynomial::degree() const {
	//returns this coefficients_table's last (rbegin()) elements first (degree)
	if (std::ssize(coefficients_table) == 0) {
		return 0;
	}
	return coefficients_table.rbegin()->first;
}

Polynomial& Polynomial::operator+=(const Polynomial& toAdd) {
	//coeff + coeff stored in coefficients_table
	for (auto it = toAdd.coefficients_table.begin(); it != toAdd.coefficients_table.end(); ++it) {
		coefficients_table[it->first] += it->second;//coeff += coeff

			if (coefficients_table[it->first] == 0) {
				coefficients_table.erase(it->first);
			}
	}
	
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& toSubtract) {

	//coeff - coeff stored in coefficients_table
	for (auto it = toSubtract.coefficients_table.begin(); it != toSubtract.coefficients_table.end(); ++it) {
		coefficients_table[it->first] -= it->second;//coeff-coeff.toSubtract
		if (coefficients_table[it->first] == 0) {
			coefficients_table.erase(it->first);
		}
	}
	Polynomial result;

	////only adds it to result if not 0
	//for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
	//	if (it->second != 0) {
	//		result.coefficients_table[it->first] += it->second;
	//	}
	//}

	//sets *this to result, zeroes not included
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& toMultiply) {

	Polynomial result;
	//loops through toMultiply
	for (auto it = toMultiply.coefficients_table.begin(); it != toMultiply.coefficients_table.end(); ++it) {

		result += multiply_with_term(*it);
	}

	*this = result;
	return *this;
}

Polynomial Polynomial::multiply_with_term(term termMultiply) {
	Polynomial result;

	//loops through coefficients_table and multiplies with tearmMultiply
	for (term currentTerm : coefficients_table) {
		int degree = currentTerm.first + termMultiply.first; //deggree +
		int coeff = currentTerm.second * termMultiply.second;//coeff *

		result.coefficients_table[degree] = coeff;
	}

	return result;
}

bool Polynomial::operator==(const Polynomial& toCompare) const {
	return coefficients_table == toCompare.coefficients_table; //returns true if the same, else false
}

Polynomial operator*(Polynomial lhs,const Polynomial& toMultiply) {
	lhs *= toMultiply;
	return lhs;
}

//<< allows Polynomial to be streamed to output stream cout, override
//							cout				polynomial
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
	os << std::string{ p }; //writes string representation to output stream
	return os;//returns that output stream
}

Polynomial operator+(Polynomial lhs, const Polynomial& toAdd) {
	lhs += toAdd;	
	return lhs;
}

Polynomial operator-(Polynomial lhs, const Polynomial& toSubtract) {
	lhs -= toSubtract;
	return lhs;
}

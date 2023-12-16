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
Polynomial::Polynomial(const int deg, const int coeff) : coefficients_table{ {deg,coeff} } {
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

	for (auto it = toAdd.coefficients_table.begin(); it != toAdd.coefficients_table.end(); ++it) {
		coefficients_table[it->first] += it->second;
	}
	Polynomial result;

	for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
		if (it->second != 0) {
			result.coefficients_table[it->first] += it->second;
		}
	}


	return *this = result;
}

Polynomial& Polynomial::operator-=(const Polynomial& toSubtract) {

	for (auto it = toSubtract.coefficients_table.begin(); it != toSubtract.coefficients_table.end(); ++it) {
		coefficients_table[it->first] -= it->second;
	}
	Polynomial result;

	for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
		if (it->second != 0) {
			result.coefficients_table[it->first] += it->second;
		}
	}

	return *this = result;
}

Polynomial& Polynomial::operator*=(const Polynomial& toMultiply) {

	Polynomial result;

	for (auto it = toMultiply.coefficients_table.begin(); it != toMultiply.coefficients_table.end(); ++it) {

		result += multiply_with_term(*it);
	}

	*this = result;
	return *this;
}

Polynomial Polynomial::multiply_with_term(term termMultiply) {
	Polynomial result;

	for (term currentTerm : coefficients_table) {
		int degree = currentTerm.first + termMultiply.first;
		int coeff = currentTerm.second * termMultiply.second;

		result.coefficients_table[degree] = coeff;
	}

	return result;
}

bool Polynomial::operator==(const Polynomial& toCompare) const {
	return coefficients_table == toCompare.coefficients_table;
}

Polynomial operator*(Polynomial lhs,const Polynomial& toMultiply) {
	/*Polynomial result;

	for (auto it = toMultiply.coefficients_table.begin(); it != toMultiply.coefficients_table.end(); ++it) {

		result += multiply_with_term(*it);
	}

	*this = result;
	return *this;*/

	lhs *= toMultiply;
	return lhs;

	//return *this *= toMultiply;
}


std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
	os << std::string{ p };
	return os;
}

Polynomial operator+(Polynomial lhs, const Polynomial& toAdd) {
	lhs += toAdd;	
	return lhs;
}

Polynomial operator-(Polynomial lhs, const Polynomial& toSubtract) {
	lhs -= toSubtract;
	return lhs;
}

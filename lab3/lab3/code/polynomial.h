/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using term = std::pair<int, int>;


class Polynomial {

private:	
	std::map<int, int> coefficients_table;

public:
	
	//constructor takes in deg nad coeff
	Polynomial(const int deg, const int coeff);

	//Constructor, creates Polynomial of a constant 'i'
	Polynomial(const int i);

	//Default constructor
	//creates empty instance of polynomial, explicit to avoid implicit type conversions, default compiler implements default constructor
	explicit Polynomial() = default;

	//Constructor, creates Polynomial of a Vector<term>, 'ppairs' aka term -> 'std::pair<int, int>'
	Polynomial(const std::vector<term>& ppairs);

	//String Operator
	explicit operator std::string() const;

	//Return degree integer, will not modify the calling Polynomial
	int degree() const;

	//reference in order to cascade, const reference dont want to change toAdd, reference no copy
	Polynomial& operator+=(const Polynomial& toAdd);

	Polynomial& operator-=(const Polynomial& toSubtract);

	Polynomial& operator*=(const Polynomial& toMultiply);

	Polynomial multiply_with_term(term termMultiply);

	bool operator==(const Polynomial& toCompare) const;

	//Polynomial& operator*(const Polynomial& toMultiply);
	friend Polynomial operator*(Polynomial lhs, const Polynomial& toMultiply);


	friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

	friend Polynomial operator+(Polynomial lhs, const Polynomial& toAdd);

	friend Polynomial operator-(Polynomial lhs, const Polynomial& toSubtract);


protected:

};



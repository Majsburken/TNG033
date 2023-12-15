/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {

private: 
	Expression* E;
	int c1;
	int c2;
	int b;

public:
	//default constructor
	Logarithm();

	//constructor with given values
	Logarithm(Expression& Exp, int cf1, int cf2, int base);

	//copy constructor
	Logarithm(const Logarithm& L);

	//destructor not used? don't know, in clone?
	~Logarithm();

	//pure virtual in expression implemented here
	Logarithm* clone() const override;

	//sets this to setAs values, const call by reference for efficiency, returning reference for cascading purposes?
	Logarithm& operator=(const Logarithm& setAs);
	
	//Overloaded function call operator, override
	virtual double operator()(const double d) const override;

	operator std::string() const override;

	//changes the base of the logarithm to given int, int > 1
	void set_base(int base);

};

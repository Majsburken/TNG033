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
	Logarithm();

	Logarithm(Expression& Exp, int cf1, int cf2, int base);

	Logarithm(const Logarithm& L);

	~Logarithm();

	Logarithm* clone() const override;

	virtual double operator()(double d) const override;

	operator std::string() const override;

	void set_base(int base);

	Logarithm& operator=(const Logarithm& setAs);
};

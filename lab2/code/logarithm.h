/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {

private: 
	double c1;
	double c2;
	Expression* E;

public:
	Logarithm();


	Polynomial* clone() const;
	virtual double operator()(double d) const override;



};

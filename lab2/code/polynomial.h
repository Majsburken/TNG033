/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once
#include <vector>

#include <iostream>

#include "expression.h"

//Polynomial is a derived class of base class Expression
class Polynomial : public Expression {

protected:
    std::vector<double> coeffecients;


    // ADD CODE
public:
    Polynomial(const std::vector<double>& coeffs);

    Polynomial(double& realConstant);

    Polynomial(Polynomial& toBeCopied);

    void operator=(Polynomial setAs);
};



/*
 * std::vector should be used to store polinomial's coefficients
 */
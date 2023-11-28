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

private:
    std::vector<double> coeffecients;

public:
    Polynomial(const std::vector<double>& coeffs);

    Polynomial(const double& realConstant);

    Polynomial(Polynomial& toBeCopied);

    void operator=(Polynomial setAs);

    Polynomial* clone() const;

    //Const, operator() should not modify the calling Polynoimal(?)
    //Function operator() will override the Pure Virtual function declared in base class
    virtual double operator()(double d) const override;

    double operator[](int index);

    std::string toString(std::ostream& os) const;

};



/*
 * std::vector should be used to store polinomial's coefficients
 */
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

    Polynomial(const Polynomial& toBeCopied);

    Polynomial& operator=(const Polynomial& setAs);

    Polynomial& operator+=(const Polynomial& toAdd);

    friend Polynomial operator+(const Polynomial& lhs,const Polynomial& rhs);

    friend Polynomial operator+(Polynomial& lhs, double d);

    Polynomial* clone() const override;

    //Const, operator() should not modify the calling Polynoimal(?)
    //Function operator() will override the Pure Virtual function declared in base class
    virtual double operator()(double d) const override;

    double& operator[](int index);

    double operator[](int index) const;


    operator std::string() const override;

};



/*
 * std::vector should be used to store polinomial's coefficients
 */
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
    //only accessed in the member functions of the class
    std::vector<double> coeffecients;

public:
    //constructor, makes a polynomial from a vector of coefficients
    Polynomial(const std::vector<double>& coeffs);

    //makes a polynomial out of a constant
    Polynomial(const double& realConstant);

    //copy constructor
    Polynomial(const Polynomial& toBeCopied);

    Polynomial& operator=(const Polynomial& setAs);

    Polynomial& operator+=(const Polynomial& toAdd);

    friend Polynomial operator+(const Polynomial& lhs,const Polynomial& rhs);

    friend Polynomial operator+(Polynomial& lhs, double d);

    //this is a pure virtual function in expression being implemented
    Polynomial* clone() const override;

    //Const, operator() should not modify the calling Polynoimal(?)
    //Function operator() will override the Pure Virtual function declared in base class
    virtual double operator()(const double d) const override;

    double& operator[](const int index);

    double operator[](const int index) const;

    //this is a pure virtual function in expression being implemented
    operator std::string() const override;

};

/*
 * std::vector should be used to store polinomial's coefficients
 */
/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS
    bool isRoot(const double x) const;

    //Pure virtual function, must be implemented in a derived class, not implemented in base class
    virtual std::string string(std::ostream& os) const = 0;

    //Returns a double and takes a double as agrument
    //Const, operator() should not modify any Expressions's derived classes (Polynomial, Logarithm)
    //Pure Virtual function, we do not define the function in the base class
    virtual double operator()(double d) const = 0;

    friend std::ostream& operator<<(std::ostream& os, Expression a);

    virtual Expression* clone() const = 0;
    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions;
};

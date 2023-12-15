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
    bool isRoot(const double x) const;//const in order to not change the expression calling nor the value x

    //Pure virtual function, must be implemented in a derived class, not implemented in base class
    //explicit to not allow implicit conversions
    explicit virtual operator std::string() const = 0;

    //Returns a double and takes a double as argument
    //Const, operator() should not modify any Expressions's derived classes (Polynomial, Logarithm)
    //Pure Virtual function, we do not define the function in the base class
    //const double because we dont want to change it, its overloaded pol and log overrides this function
    virtual double operator()(const double d) const = 0;

    //stream insertion, writes expression to output stream
    //friend in order for derived classes to to access the function
    //const expression, we dont want to change it, non const function we want to change values in it
    //os non const, inserts e into it
    friend std::ostream& operator<<(std::ostream& os, const Expression& e) {
    os << std::string{ e };
    return os;
    }

    //polymorphic copying, all underclasses has their own clone function, copying works for all classes
    //pure virtual, it must be implemented in the subclasses
    //creates a new object with the values of o, returns pointer to the new object
    virtual Expression* clone() const = 0;

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    //returns reference to expression, can only be accessed within superclass and subclasses when protected
    //not from test.cpp which is outside of the class so it wont compile
	Expression& operator=(const Expression& rhs) = default; //default given by compiler

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions;
};

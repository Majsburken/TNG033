/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include "expression.h"
#include "vector"
#include "iomanip"
#include <format>
#include <string>
#include <cmath>

// ADD implementation of the member functions for class Logarithm

//Default Constructor
//Creates Logarithm: 0.00 + 1.00 * Log_2( 0.00 + 1.00 * X^1 )
Logarithm::Logarithm() : E{ new Polynomial{std::vector<double> {0.0,1.0}} }, c1{ 0 }, c2{ 1 }, b{ 2 } {
}

//Constructor, takes in arguments
//could arguments be const?
Logarithm::Logarithm(Expression& Exp, int cf1, int cf2, int base) {
    E = Exp.clone();//clone to make correct number of expressions?    
    (*this).c1 = cf1;
    (*this).c2 = cf2;
    (*this).b = base;
}

//Copy Constructor
Logarithm::Logarithm(const Logarithm& L) {
    (*this).E = L.E->clone();//clones L's expression
    (*this).c1 = L.c1;
    (*this).c2 = L.c2;
    (*this).b = L.b;
}

//destructor
Logarithm::~Logarithm() {
    delete E;
    c1 = 0;
    c2 = 0;
    b = 0;
}

//returns pointer to new logarithm which is copy of this
Logarithm* Logarithm::clone() const {
    return new Logarithm(*this);
}

double Logarithm::operator()(const double d) const { //Const, operator() should not modify the calling Polynomial
	return c1 + c2 * (log2(E->operator()(d))/ log2(b)); //object E calls operator() with argument d
}

void Logarithm::set_base(int base) {
    (*this).b = base;
}

Logarithm::operator std::string() const {
    std::string s;
    
    s += std::format("{:.2f}", (double)(*this).c1);
    if (c2 < 0) {
        s += " - " + std::format("{:.2f}", abs((double)(*this).c2));
    }
    else {
        s += " + " + std::format("{:.2f}", (double)(*this).c2);
    }
        
    s += " * Log_" + std::to_string((*this).b) + "( ";
    s += std::string(*E) + " )";

    return s;
}

//return reference in order to cascade??
Logarithm& Logarithm::operator=(const Logarithm& setAs) {
    delete E;//delete expression first in order to keep the correct count of expressions
    (*this).E = setAs.E->clone();//clones the expression which creates a new one, increases count
    (*this).c1 = setAs.c1;
    (*this).c2 = setAs.c2;
    (*this).b = setAs.b;
    return *this;

}
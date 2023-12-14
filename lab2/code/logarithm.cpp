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
// ADD implementation of the member functions for class Logarithm

//Default Constructor
//Creates Logarithm: 0.00 + 1.00 * Log_2( 0.00 + 1.00 * X^1 )
Logarithm::Logarithm() : E{ new Polynomial{std::vector<double> {0.0,1.0}} }, c1{ 0 }, c2{ 1 }, b{ 2 } {
}

//Copy Constructor
Logarithm::Logarithm(const Logarithm& L) {
    (*this).E = L.clone();
    (*this).c1 = L.c1;
    (*this).c2 = L.c2;
    (*this).b = L.b;
}

//Constructor, takes in arguments
Logarithm::Logarithm(Expression& Exp, int cf1, int cf2, int base) {
    (*this).E = { Exp.clone() };
    (*this).c1 = cf1;
    (*this).c2 = cf2;
    (*this).b = base;
}

Logarithm::~Logarithm() {
    delete E;
    c1 = 0;
    c2 = 0;
    b = 0;
}

Logarithm* Logarithm::clone() const {
    return new Logarithm( *this );
}

double Logarithm::operator()(double d) const { //Const, operator() should not modify the calling Polynomial
    return 0;
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
        //s += " + " + std::format("{:.2f}", (*this).coeffecients[i]);

    //this p c1 c2 bas

    return s;
}
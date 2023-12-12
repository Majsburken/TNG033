/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath> //To use "pow"
#include <vector>
#include <iomanip>
#include <format>
#include <string>


// ADD implementation of the member functions for class Polynomial
//polynomial:: because it is a class function, push back elements of arg. vector into the this polynomial's vector of coefficiants  
Polynomial::Polynomial(const std::vector<double>& coeffs) { //WHY & and not call by value
    for (double e : coeffs) {
        (*this).coeffecients.push_back(e);
    }
};

//polynomial:: because it is a class function, push back elements of arg. into the this polynomial's vector of coefficiants  
Polynomial::Polynomial(const double& realConstant) { //WHY & and not call by value
    (*this).coeffecients.push_back(realConstant);
};

//push_backs arguments of the poly. to be copied into the vector of the poly. calling.
Polynomial::Polynomial(const Polynomial& toBeCopied) {
    for (double e : toBeCopied.coeffecients) {
        (*this).coeffecients.push_back(e);
    }
};


Polynomial& Polynomial::operator=(const Polynomial& setAs) {
    (*this).coeffecients = (setAs).coeffecients;

    return *this;
    
}

Polynomial& Polynomial::operator+=(const Polynomial& toAdd) {
    for (int i = 0; i < std::ssize(toAdd.coeffecients); i++) {
        if (i < std::ssize((*this).coeffecients)) {
            (*this).coeffecients[i] += toAdd.coeffecients[i];
        }
        else {
            (*this).coeffecients.push_back(toAdd.coeffecients[i]);
        }
    }
    return *this;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
   return  Polynomial(lhs) += rhs; //not dynamic conastructor = deletes object itself
}

Polynomial operator+(Polynomial& lhs, double d) {
    return lhs + Polynomial(d);
}

Polynomial* Polynomial::clone() const{
   return new Polynomial(*this); //dynamic constructor new says you will handle the deleting and stuff yourself
   //"new" allocates memory in heap
}

//Implementation of pure virtial function declared in parent class
Polynomial::operator std::string() const {
    std::string s;
    for (int i = 0; i < (*this).coeffecients.size(); i++) {
        if (i == 0) {
            s+= (std::format("{:.2f}", coeffecients[i]));
        }
        else {
            if ((*this).coeffecients[i] < 0) {
                s += " - " + std::format("{:.2f}", abs((*this).coeffecients[i]));
            }
            else {
                s += " + " + std::format("{:.2f}", (*this).coeffecients[i]);
            }
            s += " * X^" + std::to_string(i);
        }
    }
    return s;
}

double Polynomial::operator()(double d) const{ //Const, operator() should not modify the calling Polynomial
    double sum = 0.00;

    for (int i = 0; i < (*this).coeffecients.size(); i++) {
        sum += (*this).coeffecients[i] * std::pow(d, i);
    }
    /*return (std::format("{:.2f}", sum));*/

    return sum;
}

 double& Polynomial::operator[](int index){
     return coeffecients[index];
}

 double Polynomial::operator[](int index) const {
     return coeffecients[index];
 }

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    os << std::string{ p };
    return os;
}



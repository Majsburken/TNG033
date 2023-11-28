/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "expression.h"
#include <vector>
#include <math.h>
#include <string>


// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;

// Used only for debug purposes
// Return number of existing Expressions
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}



/* ************************* */
 bool Expression::isRoot(double possibleRoot) {
     double sum = (*this)[0];

     if ((*this)(possibleRoot) == 0) {
         return true;
     }
    
}

 std::string string(Expression e) {
    std::string s = e[0];

    for (int i = 1; i < e.size(); i++) {
        if (e[i] != 0) {
            s += " + " + e[i] + "x^" + i;
        }
    }

    return s;
}


 virtual void Expression::operator()(double d) = 0;

 std::ostream& operator<<(std::ostream& os, Expression a) {
     os << std::string(a);
     return os;
 }

 Expression* clone() {
     Expression* ptr = Expression{ this }; //VET INTE
     return ptr;
}



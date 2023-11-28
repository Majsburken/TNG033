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
 bool Expression::isRoot(const double possibleRoot) const {
     if ((*this)(possibleRoot) == 0) {
         return true;
     }
     return false;
}

//string should not be implemented here, it is a pure virtual function

 //operator() should not be implemented here, it is a pure virtual function

 std::ostream& operator<<(std::ostream& os, Expression& a) {
     os << a.toString(os);
     return os;
 }





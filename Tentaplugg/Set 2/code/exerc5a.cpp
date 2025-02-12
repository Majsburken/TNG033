/**************************************************************************
 * TNG033: set of exercises 2                                              *
 * Exercise 5a                                                             *
 * *************************************************************************/

#include <iostream>

void f(int k) {
    std::cout << k << '\n';
}

class Integer {
    // ADD CODE
};

// Test class Integer
int main() {
    Integer i1{5};
    Integer i2{-1};

    std::cout << "i1+i2 = " << i1 + i2 << '\n';
    std::cout << "i1-i2 = " << i1 - i2 << '\n';
    std::cout << "i1*i2 = " << i1 * i2 << '\n';
    std::cout << "i1/i2 = " << i1 / i2 << '\n';
    std::cout << "i1%i1 = " << i1 % i1 << '\n';

    f(i1);
}
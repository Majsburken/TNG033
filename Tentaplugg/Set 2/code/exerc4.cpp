/**************************************************
 * TNG033: Set of exercises  2                    *
 * Exercise 4                                     *
 * ************************************************/

#include <iostream>
#include <vector>
#include <cassert>

/* ************************** *
 * Class Set definition       *
 * ************************** */

// A class to represent sets of non-negative integers
class Set {
public:
    //ADD CODE

    // Overloaded stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Set& s);

private:
    std::vector<bool> elements;
};


/* ****************************** *
 * Class Set implementation       *
 * ****************************** */


// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Set& s) {
    os << "{ ";

    if (!s.empty()) {
        for (int i = 0; i < std::ssize(s.elements) - 1; ++i) {
            if (s.elements[i]) {
                os << i << ", ";
            }
        }

        // Write last element
        if (s.elements[std::ssize(s.elements) - 1]) {
            os << std::ssize(s.elements) - 1;
        }
    }
    os << " }";
    return os;
}

/* ************** *
 * main function  *
 * ************** */

int main() {
    Set S1{};  // empty set
    std::cout << "S1 = " << S1 << "\n";

    Set S2{4};
    std::cout << "S2 = " << S2 << "\n";
    std::cout << "S2 has " << S2.cardinality() << " elements\n";

    S2 += Set{8};
    std::cout << "S2 = " << S2 << "\n";
	
	assert(S1 != S2);

    S1 = S2 + Set{5}; // assignment operator
    std::cout << "S1 = " << S1 << "\n";

    Set S3{S1 + Set{20}}; // copy constructor
    std::cout << "S3 = " << S3 << "\n";

    S2 += S1 + S3;
    std::cout << "S2 = " << S2 << "\n";
    std::cout << "S2 has " << S2.cardinality() << " elements\n";

    S2 += Set{};
    std::cout << "S2 = " << S2 << "\n";

    assert(S2 == S3);

    // std::cout << "S2 + 3" << S2 + 3 << "\n"; // should not compile
}

// =======================================================
// Exerc2
// Name:
// LiU-id:
// Personal number:
// =======================================================
// Write your name, liU-id, and personal number.
// Don't modify the source file's name

#include <iostream>
#include <vector> //We store the terms in Vectors
#include <format>
#include <string>
#include <cmath>


class Polynomial {
public:

    //Default constructor
    Polynomial(double c = 0) {
        //Creates a Polynomal consisting of a constant
        if (c != 0) {
            non_zero_terms = std::vector<Term>{ Term{c, 0} };
        }
        //Creates an empty Polynomial
        else { //No input, uses default values, stated in "private:"
            non_zero_terms = std::vector<Term>{};
        }
    }

    //Pass by reference to make more efficient
    //Const, we do not want to modify the Vector
    Polynomial(const std::vector<double>& V) {
        for (int i = 0; i < std::ssize(V); i++) {
            if (V[i] != 0) {
                non_zero_terms.push_back(Term{ V[i],i });
            }
        }
    }

    ~Polynomial() = default;


    //Must have the "&" to avoid infinite loops and uneccessary copying
    Polynomial(const Polynomial& P) = default; //Copy constructor, using the default

    //Must have "&" to allow cascading
    Polynomial& operator=(const Polynomial& toBeAssignedTo) = default; //Always try to use default

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs) { //Lecture 7
        if (std::ssize(rhs.non_zero_terms) == 0) {
            os << 0;
        }
        else {
            std::string s = "";

            if (rhs.non_zero_terms[0].coeff < 0) {
                s += "- ";
            }

            s += std::format("{:.1f}", abs(rhs.non_zero_terms[0].coeff)) + " * X^" + std::to_string(rhs.non_zero_terms[0].deg);
            

            for (int i = 1; i < std::ssize(rhs.non_zero_terms); i++) {

                if (rhs.non_zero_terms[i].coeff < 0) {
                    s += " - ";
                }
                else {
                    s += " + ";
                }
                s += std::format("{:.1f}", abs(rhs.non_zero_terms[i].coeff)) + " * X^" + std::to_string(rhs.non_zero_terms[i].deg);
            }
            os << s;
        }
        return os;
    }



    const double operator[](int deg) const { //Const because we do not want to modify the Polynomial itself
        for (int i = 0; i < std::ssize(non_zero_terms); i++) {
            if (non_zero_terms[i].deg == deg) {
                return non_zero_terms[i].coeff;
            }
        }
        return 0.0;
    }

    friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs) {
        return lhs += rhs;
    }



    //Polynomial& operator+=(const Polynomial& rhs) {
    //    std::vector<Term> summed;

    //    int i = 0;
    //    int j = 0;

    //    while (i < std::ssize(non_zero_terms) && j < std::ssize(rhs.non_zero_terms)) {
    //        if (non_zero_terms[i].deg < rhs.non_zero_terms[j].deg) {
    //            summed.push_back(non_zero_terms[i]);
    //            i++;
    //        }
    //        else if (non_zero_terms[i].deg > rhs.non_zero_terms[j].deg) {
    //            summed.push_back(rhs.non_zero_terms[j]);
    //            j++;
    //        }
    //        else {  // same degree
    //            Term t = { non_zero_terms[i].coeff + rhs.non_zero_terms[j].coeff, non_zero_terms[i].deg };
    //            if (t.coeff != 0.0) {  // terms with coefficient zero are not stored
    //                summed.push_back(t);
    //            }
    //            i++;
    //            j++;
    //        }
    //    }

    //    while (i < non_zero_terms.size()) {
    //        summed.push_back(non_zero_terms[i]);
    //        i++;
    //    }

    //    while (j < rhs.non_zero_terms.size()) {
    //        summed.push_back(rhs.non_zero_terms[j]);
    //        j++;
    //    }

    //    non_zero_terms = summed;
    //    return *this;
    //}




    Polynomial& operator+=(const Polynomial& rhs) { //Not a const function, why not?
        int p1 = 0;
        int p2 = 0;

        std::vector<Term> summed;

        while (p1 < std::ssize(non_zero_terms) && p2 < std::ssize(rhs.non_zero_terms)) {
            if (non_zero_terms[p1].deg < rhs.non_zero_terms[p2].deg) { //Add the term with the smallest degree
                summed.push_back(non_zero_terms[p1]);
                p1++;
            }
            else if (rhs.non_zero_terms[p2].deg < non_zero_terms[p1].deg) {
                summed.push_back(rhs.non_zero_terms[p2]);
                p2++;
            }
            else { //same degree                                                    p1 or p2 does not matter, they are the same here
                Term t = { (non_zero_terms[p1].coeff + rhs.non_zero_terms[p2].coeff) ,non_zero_terms[p1].deg };
                if (t.coeff != 0.0) { //Only store if the coefficient is not 0
                    summed.push_back(t);
                }
                p1++; p2++;
            }
        }

        //Adds rest of coefficients if this, lhs, is of a higher degree
        while (p1 < std::ssize(non_zero_terms)) {
            summed.push_back(non_zero_terms[p1]);
            p1++;
        }

        //Adds rest of coefficients if rhs is of a higher degree
        while (p2 < std::ssize(rhs.non_zero_terms)) {
            summed.push_back(rhs.non_zero_terms[p2]);
            p2++;
        }

        non_zero_terms = summed;
        return *this;
    }

private:

    //Default term is "0 * X^0"
    struct Term {
        double coeff = 0;
        int deg = 0;
    };
    //Vector storing Terms, the Vector i a Polynomial
    std::vector<Term> non_zero_terms;

};





























/*
 * main: to test class Polynomial
 *       deliver unmodified
 */

int main() {
    /*********************************************
     * Test 1: constructors, operator<<          *
     **********************************************/
    std::cout << "\n** Test 1: constructors, operator<<\n\n";

    // Create polynomial p0 = 0
    Polynomial p0{};
    std::cout << "p0 = " << p0 << "\n";

    // Create polynomial p1 = 77
    Polynomial p1{77.0};
    std::cout << "p1 = " << p1 << "\n";

    // Create polynomial p2 = 2X^2 + 4X^10
    Polynomial p2{std::vector{0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0}};
    std::cout << "p2 = " << p2 << "\n";

    // Create polynomial p3 = 3 + 2X^1 - 4X^4
    const Polynomial p3{std::vector{3.0, 2.0, 0.0, 0.0, -4.0}};
    std::cout << "p3 = " << p3 << "\n";

    // Create polynomial p4 = 1 + X^20
    const Polynomial p4{std::vector{1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0}};
    std::cout << "p4 = " << p4 << "\n";

    // Create polynomial p5 = -1 - 4X^1 - X^3
    const Polynomial p5{std::vector{-1.0, -4.0, 0.0, -1.0}};
    std::cout << "p5 = " << p5 << "\n";

    /*********************************************
     * Test 2: operator[]                        *
     **********************************************/
    std::cout << "\n** Test 2: operator[]\n\n";

    std::cout << "p0[5] = " << p0[5] << "\n";    // 0
    std::cout << "p1[0] = " << p1[0] << "\n";    // 77
    std::cout << "p2[10] = " << p2[10] << "\n";  // 4
    std::cout << "p3[10] = " << p3[10] << "\n";  // 0
    std::cout << "p4[6] = " << p4[6] << "\n";    // 0
    std::cout << "p5[3] = " << p5[3] << "\n";    // -1

    // p1[0] = -66; // should not compile

    /*********************************************
     * Test 3: operator+=                        *
     **********************************************/
    std::cout << "\n** Test 3: operator+=\n\n";

    p0 += p3;
    std::cout << "p0 = " << p0 << "\n";  // p0 = 3 + 2X^1 - 4X^4

    p0 += p0;
    std::cout << "p0 = " << p0 << "\n";  // p0 = 6 + 4X^1 - 8X^4

    p2 += p3;
    std::cout << "p2 =" << p2 << "\n";  // p2 = 3 + 2X^1 + 2X^2 - 4X^4 + 4X^10

    /*********************************************
     * Test 4: operator+                         *
     **********************************************/
    std::cout << "\n** Test 4: operator+\n\n";

    std::cout << "p0+p5 = " << p0 + p5 << "\n";  // p0 + p5 = 5 - X^3 - 8X^4

    std::cout << "p2+p4 = " << p2 + p4 << "\n";  // p2 + p4 = 4 + 2X^1 + 2X^2 - 4X^4 + 4X^10 + X^20

    /*********************************************
     * Test 5: mixed mode arithmetic             *
     **********************************************/
    std::cout << "\n** Test 5: mixed mode arithmetic\n\n";

    std::cout << "- 1 + p4 = " << -1 + p4 << "\n";  // -1 + p4 = X^20

    std::vector<double> V{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0};

    std::cout << "V + p0 = " << V + p0 << "\n";  // V + p0 = 6 + 4X^1 - 8X^4 + 2.5X^6 - X^20

    std::cout << "-1 + p4 + V = " << -1 + p4 + V << "\n";  // -1 + p4 + V = 2.5X^6
}

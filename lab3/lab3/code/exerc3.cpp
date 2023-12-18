/*********************************************
 * Lab 3: exercise 3                         *
 * Program to compute an approximation of pi *
 * STL-algorithms should be used             *
 *********************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <format>
#include <vector>
#include <numeric>

double calculate(double k) {
    double const factor{8.0 * k};//8n
    double const init{4.0 / (factor + 1.0) - 1.0 / (factor + 4.0)};//first term and half of the second term

   std::vector<double> other_factors{4.0, 5.0, 6.0};//term constants

   //               1st range               1st range           destination             operation lambda function
   std::transform(other_factors.begin(), other_factors.end(), other_factors.begin(), [factor](double x) {
       return ( - 1.0 / ((factor)+x));
       });

    

    double result{init};

    //               1st range               1st range           destination             operation lambda function
    std::transform(other_factors.begin(), other_factors.end(), other_factors.begin(), [&result](double x) {
        return result += x;
        });

    //lambda function
    //[&result] [] lambda captures result by reference to modify result outside the scope
    //transform is the lambdas scope
    //(double x) is the parameterlist 
    //x element of other facotors
    //returns what should be placed in vector
 
    return result;
}


int main() {
    std::cout << "Enter number of terms: ";
    int n;
    std::cin >> n;

    // ADD CODE

    //making space for n-sized vector
    std::vector<double> terms(n);

    //iota      start          end    starting value(0,1,2...) 
    std::iota(terms.begin(), terms.end(), 0);
    std::vector<double> power_terms{ terms };

    //              begin           end         destination     takes in x
    std::transform(terms.begin(), terms.end(), terms.begin(), [](double x) {
        return calculate(x);
        });


    std::transform(power_terms.begin(), power_terms.end(), power_terms.begin(), [](double x) {
        return std::pow(16.0, -x); //(1/16)^n
        });

    //                                  v1 begin        v1 end      v2 begin            starting value
    double result = std::inner_product(terms.begin(), terms.end(), power_terms.begin(), 0.0);

    //result
    std::cout << std::format("{:.15f}\n", result);
}

/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/

#include <map>

#include <vector>

using term = std::pair<int, int>;


class Polynomial {

private:	
	std::map<int, int> coefficients_table;

public:
	
	//constructor takes in coeff and deg
	Polynomial(const int coeff, const int deg);

	Polynomial(int i);

	Polynomial();

	Polynomial(const std::vector<term>& ppairs);

	operator std::string() const;



protected:

};
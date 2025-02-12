/***************************************************************************
 * TNG033: set of exercises 2                                              *
 * Exercise 5b                                                             *
 * *************************************************************************/

#include <iostream>
#include <vector>

class Integer {
    // ADD the code of exercise 5a
};

class Ten {
public:
    // Conversion from Ten to Integer
    operator Integer() const {
        return Integer{10};
    }
};


int main() {
    Ten ten;
    std::vector<int> V{9, 6, 8, 4, 3, 1, -1, 0, -2, 18, 200, 24, 70};

    int value;
    value = V[ten];  
    
    std::cout << value << '\n';

}

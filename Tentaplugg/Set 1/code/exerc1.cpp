/**********************************************
 * TNG033: Set1, exercise 1                    *
 * *********************************************/

#include <iostream>
#include <vector>

#include <limits>

int main() {
    /* ****************************************** */
    // Exercise a
    // ADD CODE
#if 0

    std::cout << "Excercise 1a\n" << "------------\n";

    std::cout << "Type properties:\t" << "num of bytes\t\t" << "min\t\t\t\t" << "max\n"
        << "char:\t\t\t" 
        << sizeof(char) << "\t\t\t" 
        << std::numeric_limits<char>::min() << "\t\t\t\t" 
        << std::numeric_limits<char>::max() << "\n"

        << "short:\t\t\t"
        << sizeof(short) << "\t\t\t" 
        << std::numeric_limits<short>::min() << "\t\t\t\t" 
        << std::numeric_limits<short>::max() << "\n"

        << "int:\t\t\t"
        << sizeof(int) << "\t\t\t" 
        << std::numeric_limits<int>::min() << "\t\t\t" 
        << std::numeric_limits<int>::max() << "\n"

        << "long:\t\t\t"
        << sizeof(long) << "\t\t\t" 
        << std::numeric_limits<long>::min() << "\t\t\t" 
        << std::numeric_limits<long>::max() << "\n"

        << "long long:\t\t"
        << sizeof(long long) << "\t\t\t" 
        << std::numeric_limits<long long>::min() << "\t\t" 
        << std::numeric_limits<long long>::max() << "\n"

        << "unsigned int:\t\t"
        << sizeof(unsigned int) << "\t\t\t" 
        << std::numeric_limits<unsigned int>::min() << "\t\t\t\t" 
        << std::numeric_limits<unsigned int>::max() << "\n\n"
    ;
 
#endif

    /* ****************************************** */
    // Exercise b
    // ADD CODE
#if 0

    std::cout << "Excercise 1b\n" << "------------\n";

    std::cout << "Type properties:\t" << "num of bytes\t\t" << "min\t\t\t\t" << "max\n"
        << "float:\t\t\t"
        << sizeof(float) << "\t\t\t"
        << std::numeric_limits<float>::min() << "\t\t\t"
        << std::numeric_limits<float>::max() << "\n"

        << "double:\t\t\t"
        << sizeof(double) << "\t\t\t"
        << std::numeric_limits<double>::min() << "\t\t\t"
        << std::numeric_limits<double>::max() << "\n"

        << "long double:\t\t"
        << sizeof(long double) << "\t\t\t"
        << std::numeric_limits<long double>::min() << "\t\t\t"
        << std::numeric_limits<long double>::max() << "\n\n"
    ;

#endif
    /* ****************************************** */
    // Exercise c
#if 0

    std::cout << "Excercise 1c\n" << "------------\n";

    unsigned int u = -8;
    std::cout << "u = " << u << "\n\n";

    std::cout 
        << "An 'unsigned int' cannot store negative numbers.\n" 
        << "They then are handled as unsigned integers.\n" 
        << "Meaning they undergo modular arithmetics,\n" 
        << "wrapping around the max value for an unsigned type.\n" 
        << "In our case that is 4294967288.\n"
    ;

#endif
    /* ****************************************** */
    // Exercise d
#if 0

    unsigned int u = 0;
    int i = -8;

    if (i < u) {
        std::cout << "Smaller!!\n";
    } else {
        std::cout << "Larger!!\n";
    }

    std::cout << "\nu = " << u << "\n";
    std::cout << "i = " << i << "\n";

    std::cout
        << "\nOutputs 'Smaller' even though it logically\n"
        << "should output 'Larger' as '0' is larger than '-8'\n\n"
    ;

    std::cout
        << "Warning issued by compiler: ['<': signed / unsigned mismatch]\n"
        << "A correct comparisson cannot be made on row 162 due to the operands,\n"
        << "u and i, in our case, being of the different data types.\n"
        << "Causing incorrect comparisson.\n\n"
    ;

#endif
    /* ****************************************** */
    // Exercise e
#if 0
    std::vector<int> V;  // empty vector


    for (std::size_t j = 0; j < V.size() - 1; ++j) {
        std::cout << "What is going on here!!\n";
    }

    std::cout << "\n";

    std::cout 
        << "V.size() = 0, the '0' is of type unsigned int.\n"
        << "Then when subtracting 1 it converts like in ex:c\n"
        << "to an huge positive number rather than '-1'\n"
        << "Making the condition in the loop to be true to\n"
        << "next until infinity.\n\n"
    ;

#endif
	 /* ****************************************** */
    // Exercise f
#if 0

    std::vector<int> V;  // empty vector
	
	for (int j = 0; j < std::ssize(V) - 1; ++j) {
        std::cout << "Is this ok?\n";
    }

    std::cout
        << "\nThe content of the loop is never reached,\n"
        << "due to 'std::ssize(V)' returning '0' of type\n"
        << "signed int, which does not wrap around like\n"
        << "unsigned ints does.\n"
        << "The comparisson '0 < -1' is therefore made,\n"
        << "which is false, leading to never entering the loop.\n\n"
    ;
	
#endif
}

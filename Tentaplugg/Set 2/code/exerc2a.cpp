/***************************************************************************
 * TNG033: set of exercises 2                                               *
 * Exercise 2a                                                              *
 * **************************************************************************/

#include <iostream>
#include <string>

std::string* read_word() {
    std::string* p = new std::string;

    std::cout << "Enter a word: ";
    std::cin >> *p;

    return p;  //p points to a string in the heap
}

int main() {
    std::string* ptr = read_word();
    std::cout << *ptr << "\n";

    // Read another word
    ptr = read_word();
    std::cout << *ptr << "\n";

    delete ptr;
}

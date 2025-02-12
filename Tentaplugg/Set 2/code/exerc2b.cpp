/***************************************************************************
 * TNG033: set of exercises 2                                               *
 * Exercise 2b                                                              *
 * **************************************************************************/

#include <iostream>
#include <string>

std::string& read_word() {
    std::string w;

    std::cout << "Enter a word: ";
    std::cin >> w;

    return w; 
}

int main() {
    std::string word = read_word();
    std::cout << word << "\n";
}

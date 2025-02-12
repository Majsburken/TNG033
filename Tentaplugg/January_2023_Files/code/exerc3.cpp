// =======================================================
// Exerc3
// Name:
// LiU-id:
// Personal number:
// =======================================================
// Write your name, LiU-id, and personal number.
// Don't modify the source file's name

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/* ************************************* */

int main() {
    // Files with the nutrition facts for different types of food
    std::ifstream file1{"../code/veg-pizza.txt"};
    std::ifstream file2{"../code/calzone.txt"};
    std::ifstream file3{"../code/ham-pizza.txt"};
    std::ifstream file4{"../code/salad.txt"};

    if (!file1 || !file2 || !file3 || !file4) {
        std::cout << "Input file coun't not be opened!!\n";
        return 0;
    }

    std::vector<const Guest*> guests{new Guest{"Gus"}, new Diabetic{"Sally"},
                                     new Hypertensive{"Peter"}, new Vegetarian{"Velma"}};

    std::vector<const Food*> foods{new Pizza{"Vegetarian Pizza", file1, true},
                                   new Pizza{"Calzone", file2}, new Pizza_Roll{"Ham Pizza", file3},
                                   new Pizza_Roll{"Vegetarian Pizza", file1, true},
                                   new Salad{"Salad", file4}};

    for (auto guest : guests) {
        for (auto food : foods) {
            guest->eat(*food);
        }
        std::cout << '\n';
        delete guest;
    }

    for (auto food : foods) {
        delete food;
    }
}

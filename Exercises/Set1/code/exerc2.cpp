/**************************************************
 * TNG033: Lesson 1                                *
 * Exercise 2                                      *
 * *************************************************/

#include <iostream>

//Add definition of function my_swap

void my_swap(char* ptr1, char* ptr2) {
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}



int main() {
    char* p1 = new char('A');
    char* p2 = new char('B');

    std::cout << "Before my swap: *p1 = " << *p1 << "  *p2 = " << *p2 << "\n";

    my_swap(p1, p2);

    std::cout << "After my swap: *p1 = " << *p1 << "  *p2 = " << *p2 << "\n";

    // free the dynamically allocated memory
    delete p1;
    delete p2;
}

/* Expected output

Before my swap: *p1 = A  *p2 = B
After my swap: *p1 = B  *p2 = A

*/

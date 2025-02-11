/**************************************************
 * TNG033: Lesson 1                                *
 * Exercise 2                                      *
 * *************************************************/

#include <iostream>

//Add definition of function my_swap

static void my_swap(char*& a, char*& b) { //pointers passed by refrence
    char* temp = a;
    a = b;
    b = temp;
}


int main() {
    char* p1 = new char('A');
    char* p2 = new char('B');

    std::cout << "Before my swap: *p1 = " << *p1 << "  *p2 = " << *p2 << "\n";

    my_swap(p1, p2); //of type char*, aka pointers

    std::cout << "After my swap: *p1 = " << *p1 << "  *p2 = " << *p2 << "\n";

    // free the dynamically allocated memory
    delete p1;
    delete p2;

}

/* Expected output

Before my swap: *p1 = A  *p2 = B
After my swap: *p1 = B  *p2 = A

*/

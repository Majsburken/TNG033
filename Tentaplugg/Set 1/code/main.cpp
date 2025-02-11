/**************************************************
 * TNG033: set 1, exercise 4                       *
 * See lecture 3                                   *
 * Test program for  Lists                         *
 * *************************************************/

#include <iostream>

#include "list.h"

int main() {
    List my_list;  // empty list

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);

    std::cout << "\nInserting ..." << '\n';

    insert_first(my_list, 30);
    insert_first(my_list, 20);
    insert_first(my_list, 15);
    insert_first(my_list, 10);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);  // 10->15->20->30

    std::cout << "\nSearching ...\n";

    if (is_member(my_list, 10)) {  // first value
        std::cout << "Found 10\n";
    } else {
        std::cout << "10 not found!!\n";
    }

    if (is_member(my_list, 40)) {  // does not exist
        std::cout << "Found 40\n";
    } else {
        std::cout << "40 not found!!\n";
    }

    /* ******** Test exercise functions ********* */

    std::cout << "\nInsert sorted ...\n";

    insert_sorted(my_list, 23);
    insert_sorted(my_list, 32);
    insert_sorted(my_list, 8);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);  // 8->10->15->20->23->30->32

    std::cout << "\nRemoving 32, 8, 20...\n";

    remove(my_list, 32);
    remove(my_list, 8);
    remove(my_list, 20);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);  // 10->15->23->30

    std::cout << "\nInsert last ...\n";

    insert_last(my_list, 30);
    insert_last(my_list, 23);
    insert_last(my_list, 15);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);  // 10->15->23->30->30->23->15

    std::cout << "\nFree all memory used by my list ...\n";
    make_empty(my_list);

    // Display the list
    std::cout << "My list:  ";
    display_list(my_list);

    // Dealocate the memory for the dummy node
    delete my_list.head;
}

/* Expected output

My list:  empty!!

Inserting ...
My list:  10->15->20->30->

Searching ...
Found 10
40 not found!!

Insert sorted ...
My list:  8->10->15->20->23->30->32->

Removing 32, 8, 20...
My list:  10->15->23->30->

Insert last ...
My list:  10->15->23->30->30->23->15->

Free all memory used by my list ...
My list:  empty!!

*/
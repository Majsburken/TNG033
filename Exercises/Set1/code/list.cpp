/*************************************************
 * TNG033: set 1, exercise 4                      *
 * Review lecture 3                               *
 * Definition of functions declared in node.h     *
 * ************************************************/

#include "list.h"

bool is_empty(const List& L) {
    return (L.number_of_values == 0);
    // return (L.head->next == nullptr);
}

// Return the number of values stored in list L
int size(const List& L) {
    return L.number_of_values;
}

// Remove all values of the list
// All nodes are deleted except the dummy node
void make_empty(List& L) {
    if (is_empty(L)) {  // if list is empty then no nodes need to be deallocated
        return;
    }

    Node* ptr = L.head->next;  // point to the node after the dummy node
    while (ptr != nullptr) {   // while not end of the list
        Node* to_delete = ptr;
        ptr = ptr->next;  // make ptr to point to next node

        delete to_delete;
    }
    L.head->next = nullptr;  // there's no node after the dummy node
    L.number_of_values = 0;
}

// Insert n in the beginning of the list L
void insert_first(List& L, int n) {
    Node* newNode = new Node;

    newNode->value = n;
    newNode->next = L.head->next;  // link the new node to the node after the dummy node

    L.head->next = newNode;  // dummy node should point to new node
    ++L.number_of_values;    // increment the counter of number of nodes in the list
}

void display_list(const List& L) {
    if (is_empty(L)) {
        std::cout << "empty!!\n";
    } else {
        for (Node* ptr = L.head->next; ptr != nullptr; ptr = ptr->next) {
            std::cout << ptr->value << "->";
        }
        std::cout << "\n";
    }
}

/*
 * Exercise 4 / Set1
 */


bool is_member(const List& L, int n) {
    // ADD CODE;
    if (is_empty(L) != true) {
        for (Node* ptr = L.head->next; ptr != nullptr; ptr = ptr->next) {
            if (ptr->value == n) {
                return true;
            }
        }
    }
	return false;
}

// Remove the node storing n from list L
// If n is not in the list L then L is not modified
void remove(List& L, int n) {
   // ADD CODE


 /*   if (is_member(L, n)) {
        for (Node* ptr = L.head->next; ptr != nullptr; ptr = ptr->next) {
            if (ptr->next->value == n && ptr->next != nullptr) {
                Node* ptr1 = ptr;
                Node* ptr2 = ptr1->next;
                ptr1->next = ptr2->next;
                delete ptr2;
            }
        }
    }*/

    if (is_member(L, n)) {
        for (Node* ptr = L.head->next; ptr != nullptr; ptr = ptr->next) {
            if (ptr->next->value == n && ptr->next != nullptr) {
                Node* ptrDelete = ptr->next;
                ptr = ptrDelete->next;
                delete ptrDelete;
            }
        }
    }
}

// Insert n in the end of the list
void insert_last(List& L, int n) {
    // ADD CODE
}

// Insert n in a sorted list L
// After insertion L should remain sorted
void insert_sorted(List& L, int n) {
    // ADD CODE
}

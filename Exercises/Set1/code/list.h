/*****************************************************************************
 * TNG033: set 1, exercise 4                                                  *
 * Review lecture 3                                                           *
 * Header file defining a List of nodes                                       *
 * Each node stores an int and a pointer to the next node                     *
 * Pointers and dynamic memory allocation are used!!                          *
 * ****************************************************************************/

#pragma once

#include <iostream>

/*
 * Dummy nodes are used in the implementation of the lists
 */

struct Node {
    int value = 0;
    Node* next = nullptr;  // points to the next node in the list
};

struct List {
    Node* head = new Node;     // head points to a dummy node
    int number_of_values = 0;  // number of values stored in the list
};

// Test if list L is empty
bool is_empty(const List& L);

int size(const List& L);

// Delete every node of list L
void make_empty(List& L);

// Insert n in the beginning of the list L
void insert_first(List& L, int n);

void display_list(const List& L);

/* *************************************** */

// Search for a value n in the list
// Return true if n is found in the list
// otherwise, return false
bool is_member(const List& L, int n);  // Exerc 4

// Insert n in the end of the list
void insert_last(List& L, int n);  // Exerc 4

// Insert n in a sorted list L
// After insertion, L should remain sorted
void insert_sorted(List& L, int n);  // Exerc 4

// Remove the node storing n from list L
// If n is not in the list L then L is not modified
void remove(List& L, int n);  // Exerc 4

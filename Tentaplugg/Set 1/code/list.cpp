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
    // ADD CODE

    Node* ptr = L.head->next; //ptr points to first Node, not dummy 
    
    //Goes through List L until nullptr (end of list)
    while (ptr != nullptr) { 
        if (ptr->value == n) { //If a match is found, return true
            return true;
        }
        ptr = ptr->next; //else, increment and continue through the list
    }
	return false; //If gone through entire list and found no match, return false
}

// Remove the node storing n from list L
// If n is not in the list L then L is not modified
void remove(List& L, int n) {
   // ADD CODE

    if (is_empty(L)) { //If empty list, do nothing
        return;
    }

    //ptr points to dummy node, ptr-next is first Node, ptr->next->value is first Node's value
    //ptr really is the Node before the "first Node"
    //We want ot see if "first Node" is equal to n and then remove it
    //To do that we need to have access to the Node before (ptr) the Node to be removed ("first Node")
    Node* ptr = L.head; 

    //Moves along List untiln found or at end of List
    while ((ptr->next != nullptr) && (ptr->next->value != n)) {
       ptr = ptr->next;
    }

    if (ptr->next == nullptr) {  //End of List and n not found, do nothing
        return;
    }

    Node* removeNode = ptr->next; //Remove (NodeBefore)->next, aka the Node we want to remove
    ptr->next = removeNode->next; //Changes (NodeBefore):s next to removeNode:s next, aka the Node after the Node we want to remove
    delete removeNode; //Deallocate memory of the Node we delete
    --L.number_of_values; //Decresses number of values by 1 because we removed 1 node, value.

}

// Insert n in the end of the list
void insert_last(List& L, int n) {
    if (is_empty(L)) {
        insert_last(L, n);
    }
    else {
        Node* ptr = L.head->next; //Point to first Node, not dummy Node
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        insert_node(ptr, n);
        L.number_of_values++;
    }
}

// Insert n in a sorted list L
// After insertion L should remain sorted
void insert_sorted(List& L, int n) {

    //ptr point to dummy Node
    Node* ptr = L.head;

    if (is_empty(L) || ptr->next->value >= n) {
        insert_first(L, n);
    }
    else {
        while (ptr->next != nullptr && ptr->next->value < n) {
            ptr = ptr->next;
        }
        insert_node(ptr, n);
        L.number_of_values++;
    }
}


/**************************
 * Auxiliary functions     *
 ***************************/

 // Auxiliary function to add a new node storing value
 // after node pointed by ptr
void insert_node(Node* ptr, int value) {
    Node* newNode = new Node;

    newNode->value = value;
    newNode->next = ptr->next;  // link the newNode to the node after ptr

    ptr->next = newNode;  // link node pointed by ptr to newNode
}


#include "set.hpp"

#include <algorithm>  //std::swap

/*
* std::size_t is defined in the C++ standard library
* std::size_t is an unsigned integer type that can store the maximum size of any possible object
* sizes are non-negative integers -- i.e. unsigned integer type
*/

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ************************************ */

// Default constructor
Set::Set() : head{new Node{}}, counter{0} {  // create the dummy node
}

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {

    Node* s = new Node;
    s->value = x;
    if (get_count_nodes() > 0) {
        s->next = nullptr;
    }
}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() {
    /*
    * Sorting a vector cannot used here
    * std::sort and std::unique cannot be used
    */
   
    for (int x : elements) {
        Node* ptr = head; //pekar p� dummy node
        while (ptr->next != nullptr) {
            if (x < ptr->next->value) {
                Node* n = new Node(x, ptr->next);
                ptr->next = n;
                counter++;
                break;
            }
            else if (x > ptr->next->value) {
                ptr = ptr->next;
            }
            else if (x == ptr->next->value) {
                break;
            }
        }
        if (ptr->next == nullptr) {
            ptr->next = new Node(x, nullptr);
            counter++;
        }
    }
    // ADD CODE
    for (int i : elements) {
        Set(i);
    }
}

// copy constructor
Set::Set(const Set& rhs) : Set() {
    // ADD CODE
    Node* ptr1 = rhs.head->next;
    Node* ptr2 = head;

    while (ptr1 != nullptr) {

        ptr2->next = new Node(ptr1->value, nullptr);
 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    counter = rhs.counter;
}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) {
    // ADD CODE
    std::swap(head, rhs.head);
    std::swap(counter, rhs.counter);

    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    // ADD CODE

    Node* ptr = head; //pekar p� dummy

    while (head!=nullptr) {
        ptr = head->next;
        delete head;
        head = ptr;
    }

}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    // ADD CODE
    return counter;
}

// Test if set is empty
bool Set::empty() const {
    // ADD CODE
    if (get_count_nodes == 0) {
        return true;
    }
    return false;  // delete, if needed

}

// Test if x is an element of the set
bool Set::member(int x) const {
    // ADD CODE

    Node* ptr = head;
    while (ptr->next != nullptr) {
        if (ptr->next->value == x) {
            return true;
        }
        else {
            ptr = ptr->next;
        }
    }

    return false;  // delete, if needed
}

// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const { //b �r S
    // ADD CODE

    Node* ptr = head->next; //f�rsta noden, inte dummy
    Node* ptr2 = b.head->next;
    bool subset = false;

    if (ptr == nullptr) {
        subset = true;
    }

    if (counter > b.counter) {
        return false;
    }

    while (ptr != nullptr) {
        while (ptr2 != nullptr) {
            if (ptr->value == ptr2->value) {
                ptr = ptr->next;
                subset = true;
                break;
            }
            else {
                ptr2 = ptr2->next;
                subset = false;
            }
        }
        return subset;
    }
    return subset;
}

// Return a new Set representing the union of Sets *this and b
// Repeated values are not allowed
// Implement an algorithm similar to the one in exercise 3/Set 1, but don't use vectors
Set Set::set_union(const Set& b) const {
    // ADD CODE

    Node* ptr = head->next; //f�rsta noden, inte dummy
    int count1 = 0;

    Set S3{b};
    ptr = ptr -> next;

    Node* ptr3 = S3.head->next;




    while (ptr!=nullptr) {
        if (ptr->value < ptr3->value) {
            Node* n = new Node(ptr->value, ptr3->next);
            ptr3->next = n;
            S3.counter++;
            break;
        }
        else if (ptr->value > ptr3->value) {
            ptr3 = ptr3->next;
        }
        else if (ptr->value == ptr3->next->value) {
            break;
        }
    }

    if (ptr->next == nullptr) {

    }


    return Set{};  // delete, if needed
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

std::ostream& operator<<(std::ostream& os, const Set& rhs) {
    if (rhs.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* ptr = rhs.head->next;
        os << "{ ";

        while (ptr != nullptr) {
            os << ptr->value << " ";
            ptr = ptr->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/


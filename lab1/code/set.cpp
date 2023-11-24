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
    head->next = new Node(x, nullptr);
    counter++;
}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() {
    /*
    * Sorting a vector cannot used here
    * std::sort and std::unique cannot be used
    */
   
    for (int x : elements) {
        Node* ptr = head; //pekar på dummy node
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
    std::swap(head, rhs.head);
    std::swap(counter, rhs.counter);
    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    Node* ptr = head; //pekar på dummy
    while (head!=nullptr) {
        ptr = head->next;
        delete head;
        head = ptr;
    }
}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    return counter;
}

// Test if set is empty
bool Set::empty() const {
    if (counter == 0) {
        return true;
    }
    return false;
}

// Test if x is an element of the set
bool Set::member(int x) const {
    Node* ptr = head;
    while (ptr->next != nullptr) {
        if (ptr->next->value == x) {
            return true;
        }
        else {
            ptr = ptr->next;
        }
    }
    return false;
}

// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const { //b är S
    Node* ptr = head->next; //första noden, inte dummy
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
    Set S3{};
    Node* ptr = head->next; //första noden, inte dummy
    Node* ptrb = b.head->next; //första noden, inte dummy för b
    Node* ptr3 = S3.head; //pekar på dummy

    while (ptr != nullptr && ptrb != nullptr) {
        if (ptr->value < ptrb->value) {
            S3.insert_last(ptr->value);
            ptr = ptr->next;
        }
        else if (ptr->value > ptrb->value) {
            S3.insert_last(ptrb->value);
            ptrb = ptrb->next;
        }
        else {
            S3.insert_last(ptrb->value);
            ptr = ptr->next;
            ptrb = ptrb->next;
        }
    }

    while (ptr != nullptr) {
        S3.insert_last(ptr->value);
        ptr = ptr->next;
    }

    while (ptrb != nullptr) {
        S3.insert_last(ptrb->value);
        ptrb = ptrb->next;
    }
    return S3;
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    Set S3{};
    Node* ptr = head->next; //första noden, inte dummy
    Node* ptrb = b.head->next; //första noden, inte dummy för b
    Node* ptr3 = S3.head; //pekar på dummy

    while (ptr != nullptr && ptrb != nullptr) {
        if (ptr->value < ptrb->value) {
            ptr = ptr->next;
        }
        else if (ptr->value > ptrb->value) {
            ptrb = ptrb->next;
        }
        else {
            S3.insert_last(ptrb->value);
            ptr = ptr->next;
            ptrb = ptrb->next;
        }
    }

    return S3;
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    Set S3{};
    Node* ptr = head->next; //första noden, inte dummy
    Node* ptrb = b.head->next; //första noden, inte dummy för b
    Node* ptr3 = S3.head; //pekar på dummy

    while (ptr != nullptr && ptrb != nullptr) {
        if (ptr->value < ptrb->value) {
            S3.insert_last(ptr->value);
            ptr = ptr->next;
        }
        else if (ptr->value > ptrb->value) {
            ptrb = ptrb->next;
        }
        else {
            ptr = ptr->next;
            ptrb = ptrb->next;
        }
    }

    while (ptr != nullptr) {
        S3.insert_last(ptr->value);
        ptr = ptr->next;
    }
    S3.display();
    return S3;
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
//queencard 👑🃏
//Inserts a new node with value value after the node pointed by p.
void Set::insert_after(Node* p, int value) {
    Node* ptr = p;
    if (ptr != nullptr) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = ptr->next;
        ptr->next = newNode;
        counter++;
    }
}

void Set::insert_last(int value) {
    Node* ptr = head;

    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    if (ptr->next == nullptr) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = ptr->next;
        ptr->next = newNode;
        counter++;
    }
}

void Set::remove(Node* p) {
    Node* ptr1 = p;
    Node* ptr2 = ptr1->next;
    ptr1->next = ptr2->next;
    delete ptr2;
    counter--;
}

void Set::display() const{
    Node* ptr = head->next;
    std::cout << "Displays set" << ": ";
    while (ptr != nullptr) {
        std::cout << ptr->value << " ";
        ptr = ptr->next;
    }
    std::cout << "\nget count nodes: " << Set::get_count_nodes() << "\ncounter: " << counter << "\n";
}


// =======================================================
// Exerc1
// Name:
// LiU-id:
// Personal number:
// =======================================================
// Write your name, liU-id, and personal number.
// Don't modify the source file's name

#include <iostream>

/********************************
 * Class List definition         *
 *********************************/

class List {
public:
    // Default constructor
    List();

    // Destructor
    ~List();

    // Copy constructor disabled
    List(const List& source) = delete;

    // Assignment operator disabled
    List& operator=(const List& source) = delete;

    //Member function to Class "List"
    //Return reference to List to allow cascading
    List& add_last(int n); 

    //Member function to Class "List"
    void move_to_begin(int n);

    friend std::ostream& operator<<(std::ostream& os, const List& L);

private:
    class Node {
    public:
        // Constructor
        Node(int i, Node* ptr = nullptr) : value{i}, next{ptr} {
        }

        int value;
        Node* next;

        friend std::ostream& operator<<(std::ostream& os, const List& L);
    };

    Node* head;
};

/*****************************************************
 * Class List member functions implementation         *
 ******************************************************/

// Default constructor
List::List()
    : head{new Node{0, nullptr}}  // dummy node
{
}

// Destructor
List::~List() {
    Node* ptr = head->next;

    while (ptr != nullptr) {
        delete head;
        head = ptr;
        ptr = ptr->next;
    }
    delete head;
    // cout << "Destructor called ..." << "\n";
}

List& List::add_last(int n) {
    Node* ptr = this->head; //ptr points to dummy Node

    //has to be ptr->next not just ptr
    while (ptr->next != nullptr) { //Goes through List until end of List
        ptr = ptr->next;
    }
    //Now we are at the end of the List
    //Now ptr->next is pointing to nullptr

    ptr->next = new Node(n, ptr->next);

    return *this; //Return modified List
    //Why "return *this" and not "return &this"?
}

void List::move_to_begin(int n) {
    Node* ptr = head; //ptr points to dummy Node

    //Goes through List until we are at the end of List or n is found
    while (ptr->next != nullptr && ptr->next->value != n) {
        ptr = ptr->next;
    }

    //If n is not found, do nothing
    if (ptr->next == nullptr || head->next->value == n) {
        return;
    }
    //n is found, now we must move it to the beginning of the List
    else if (ptr->next->value == n) { 
    //ptr->next now points to the Node containing value n
        Node* ptr2 = ptr->next; //ptr2 also points to Node containing n
        ptr->next = ptr2->next; //Reroutes so that ptr->next points to 
        //the Node after the Node containing value n. It skips over

        //n in beginning:s next is set to be the previous
        ptr2->next = head->next;
        head->next = ptr2;
    }
}

std::ostream& operator<<(std::ostream& os, const List& L) {
    List::Node* ptr{L.head->next};

    if (ptr == nullptr) {
        return os << "The list is empty!!";
    }
    while (ptr != nullptr) {
        os << ptr->value << " ";
        ptr = ptr->next;
    }
    return os;
}

/**************************************
 * Main function  -- test              *
 * DELIVER UNMODIFIED                  *
 ***************************************/

int main() {
    /*********************************************
     * Test 1: add_last                          *
     **********************************************/
    std::cout << "\n** Test 1: Create some lists with add_last\n\n";

    List L1;
    L1.add_last(2).add_last(4).add_last(6).add_last(-1);
    std::cout << "List L1: " << L1 << '\n';  // List L1: 2 4 6 -1

    List L2;
    L2.add_last(-2).add_last(-4).add_last(-6);
    std::cout << "List L2: " << L2 << '\n';  // List L2: -2 -4 -6

    /*********************************************
     * Test 2: move_to_begin                     *
     **********************************************/
#if 1
    std::cout << "\n** Test 2: move_to_begin\n\n";

    List L0;
    L0.move_to_begin(4);
    std::cout << "List L0: " << L0 << '\n';  // List L0: The list is empty!!

    L1.move_to_begin(6);
    std::cout << "List L1: " << L1 << '\n';  // List L1: 6 2 4 -1

    L1.move_to_begin(-1);
    std::cout << "List L1: " << L1 << '\n';  // List L1: -1 6 2 4

    L2.move_to_begin(-2);
    std::cout << "List L2: " << L2 << '\n';  // List L2: -2 -4 -6

    L2.move_to_begin(10);
    std::cout << "List L2: " << L2 << '\n';  // List L2: -2 -4 -6
#endif
}

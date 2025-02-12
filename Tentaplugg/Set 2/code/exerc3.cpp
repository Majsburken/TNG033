/***************************************************************************
 * TNG033: set of exercises 2                                               *
 * Exercise 3                                                               *
 * **************************************************************************/

#include <iostream>

class AA {
public:
    AA(int n) : i_{n} {
    }

     void foo1(AA* p) {
        std::cout << i_ + p->i_ << '\n';
    }

    AA foo2(AA& a) {
        return AA(i_ + a.i_);
    }

    friend std::ostream& operator<<(std::ostream& os, const AA& a);

private:
    int i_;
};

std::ostream& operator<<(std::ostream& os, const AA& a) {
    os << a.i_;
    return os;
}

int main() {
    AA a1{5};
    AA a2{10};
    const AA a3{66};
    AA a4{16};

    a1.foo1(&a2);
}

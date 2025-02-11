/***************************************************************************
 * TNG033: set of exercises 2                                               *
 * Exercise 1                                                               *
 * **************************************************************************/

#include <iostream>

struct Point {
public:
    Point(int xx, int yy) : x{xx}, y{yy} {
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

private:
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "<" << p.x << "," << p.y << ">";

    return os;
}

int main() {
    long double dd1 = 1.0 / 3;
    double d1 = dd1;

    /*
     long double dd2{1.0 / 3};
     double d2{dd2};
     */

    Point p1(5.5, 7.8);
    std::cout << "p1 = " << p1 << '\n';

    /*
    Point p2{5.5, 7.8};
    std::cout << "p2 = " << p2 << '\n';
    */
}

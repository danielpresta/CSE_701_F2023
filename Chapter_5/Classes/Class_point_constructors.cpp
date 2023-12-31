#include <iostream>
using namespace std;

class point
{
public:
    // Default constructor: coordinates are initialized to their default values as specified below
    point() {}
    
    // Constructor with one argument: assumes the argument is the value of both x and y
    point(const double &_xy)
    {
        x = _xy;
        y = _xy;
    }

    // Constructor with two arguments
    point(const double &_x, const double &_y)
    {
        x = _x;
        y = _y;
    }

    // Prints the coordinates of the point as a tuple
    void print()
    {
        cout << "(" << x << ", " << y << ")\n";
    }

    // Scales both coordinates by the specified amount
    void scale(const double &s)
    {
        x *= s;
        y *= s;
    }

    // The values of the coordinates
    double x = 0, y = 0;
};

int main()
{
    point p1;       // Uses default constructor
    p1.print();     // (0, 0)
    point p2(5);    // Uses constructor with one argument
    p2.print();     // (5, 5)
    point p3(1, 9); // Uses constructor with two arguments
    p3.print();     // (1, 9)
}
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class triangle
{
public:
    // Constructor with no arguments: define a degenerate triangle with all sides equal to zero.
    triangle()
    {
        change_sides(0, 0, 0);
    }

    // Constructor with one argument: define an equilateral triangle with all sides equal to a.
    triangle(const double &_a)
    {
        change_sides(_a, _a, _a);
    }

    // Constructor with two arguments: define a right triangle with sides a and b. The third side will be determined by the Pythagorean theorem.
    triangle(const double &_a, const double &_b)
    {
        change_sides(_a, _b, sqrt(_a * _a + _b * _b));
    }

    // Constructor with three arguments: define an arbitrary triangle with sides a, b, c.
    triangle(const double &_a, const double &_b, const double &_c)
    {
        change_sides(_a, _b, _c);
    }

    // Change (or initialize) the sides of the triangle, after making sure the values are valid.
    void change_sides(const double &_a, const double &_b, const double &_c)
    {
        if ((_a < 0) or (_b < 0) or (_c < 0))
            throw invalid_argument("Sides cannot be negative!");
        if ((_a > _b + _c) or (_b > _a + _c) or (_c > _a + _b))
            throw invalid_argument("Triangle inequality must be satisfied!");

        a = _a;
        b = _b;
        c = _c;
    }

    // Print the sides of the triangle.
    void print()
    {
        cout << "(" << a << ", " << b << ", " << c << ")\n";
    }

private:

    // The lengths of the sides.
    double a = 0, b = 0, c = 0;
};

int main()
{
    try
    {
        triangle degenerate_triangle;
        degenerate_triangle.print();

        triangle equilateral_triangle(3);
        equilateral_triangle.print();

        triangle right_triangle(3, 4);
        right_triangle.print();

        triangle arbitrary_triangle(5, 6, 7);
        arbitrary_triangle.print();
    }
    catch(const invalid_argument &e)
    {
        cout << "Error: " << e.what() << '\n';
    }
    
}
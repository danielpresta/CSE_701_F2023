#include <iostream>
#include <stdexcept>
using namespace std;

class triangle
{
public:
    triangle(const double &_a, const double &_b, const double &_c)
    {
        change_sides(_a, _b, _c);
    }

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

    void print()
    {
        cout << "(" << a << ", " << b << ", " << c << ")\n";
    }

private:
    double a = 0, b = 0, c = 0;
};

int main()
{
    triangle t(4, 2, 5);
    t.print();

    try
    {
        t.change_sides(4, 3, 5);
        t.change_sides(1, 3, 5);
    }
    catch(const invalid_argument &e)
    {
        cout << "Error: " << e.what() << '\n';
    }
    t.print();
}
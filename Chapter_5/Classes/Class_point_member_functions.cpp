#include <iostream>
using namespace std;

class point
{
public:
    void print()
    {
        cout << "(" << x << ", " << y << ")\n";
    }

    void scale(const double &s)
    {
        x *= s;
        y *= s;
    }

    double x = 0, y = 0;
};

int main()
{
    point p1 = {1, 2};
    point p2 = {3, 4};

    p1.print();
    p2.print();

    p1.scale(3);
    p2.scale(2.5);

    p1.print();
    p2.print();
}
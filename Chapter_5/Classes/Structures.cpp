#include <iostream>
using namespace std;

struct point
{
    double x = 0, y = 0;
};

int main()
{
    point p;
    cout << '(' << p.x << ", " << p.y << ")\n";
}
#include <iostream>
#include <cmath>
using namespace std;

double root(const double num, const int32_t rt = 2)
{
    return pow(num, 1.0 / rt);
}

int main()
{
    cout << "Square root of 5: " << root(5) << "\n";
    cout << "Cubic root of 5: " << root(5, 3) << "\n";
}
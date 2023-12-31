#include "vector_overloads.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    try
    {
        vector<double> v = {1, 2, 3};
        vector<double> w = {4, 5, 6};
        vector<double> u = {1, 1, 1};
        cout << v + w << '\n'; // (5, 7, 9)
        cout << v * w << '\n'; // 32
        cout << -v << '\n';    // (-1, -2, -3)
        v += w;                //
        cout << v << '\n';     // (5, 7, 9)
        cout << v - w << '\n'; // (1, 2, 3)
        w -= u;                //
        cout << w << '\n';     // (3, 4, 5)
        cout << 2 * v << '\n'; // (10, 14, 18)
        cout << v * 3 << '\n'; // (15, 21, 27)
    }
    catch (const invalid_argument& e)
    {
        cout << "Error: " << e.what() << '\n';
    }
}
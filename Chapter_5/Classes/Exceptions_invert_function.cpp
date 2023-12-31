#include <iostream>
#include <stdexcept>
using namespace std;

double invert(const double &x)
{
    if (x == 0)
        throw invalid_argument("Division by zero!");
    return 1.0 / x;
}

int main()
{
    try
    {
        cout << invert(10) << "\n";
        cout << invert(0) << "\n";
        cout << invert(100) << "\n";
    }
    catch(const invalid_argument &e)
    {
        cout << "Error: " << e.what() << '\n';
    }    
}
#include "vector_overloads.hpp"

double operator*(const vector<double> &lhs, const vector<double> &rhs)
{
    if (lhs.size() != rhs.size())
        throw invalid_argument("Cannot take the dot product of vectors of different sizes!");
    double result = 0;
    for (size_t i = 0; i < lhs.size(); ++i)
        result += lhs[i] * rhs[i];
    return result;
}

int main()
{
    try
    {
        const vector<double> a = {1, 2, 3};
        const vector<double> b = {4, 5, 6};
        const vector<double> c = {1, 2, 3, 4};
        cout << a * b << "\n";
        cout << b * a << "\n";
        cout << b * vector<double>{7, 8, 9} << "\n";
        cout << (a - b) * a << "\n";
        cout << a * c << "\n";
    }
    catch(const invalid_argument &e)
    {
        cout << "Error: " << e.what() << '\n';
    }
    
}
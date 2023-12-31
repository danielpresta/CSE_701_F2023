#include "vector_overloads.hpp"

vector<double>& operator-=(vector<double>& lhs, const vector<double>& rhs)
{
    if (lhs.size() != rhs.size())
        throw invalid_argument("Cannot subtract vectors of different sizes!");
    for (size_t i = 0; i < lhs.size(); ++i)
        lhs[i] -= rhs[i];
    return lhs;
}

vector<double> operator-(vector<double> lhs, const vector<double>& rhs)
{
    lhs -= rhs;
    return lhs;
}

vector<double> operator-(vector<double> vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        vec[i] = -vec[i];
    return vec;
}

int main()
{
    try
    {
        vector<double> a = {1, 2, 3};
        const vector<double> b = {4, 5, 6};
        const vector<double> c = {7, 8, 9};
        const vector<double> d = {1, 2, 3, 4};
        a -= b;

        cout << a << "\n";
        cout << -a << "\n";
        cout << b - c << "\n";
        cout << a + b - c << "\n";
        cout << a - d << "\n";
    }
    catch(const invalid_argument &e)
    {
        cout << "Error: " << e.what() << '\n';
    }
    
}
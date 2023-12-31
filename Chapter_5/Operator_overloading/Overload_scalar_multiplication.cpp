#include "vector_overloads.hpp"

vector<double>& operator*=(vector<double>& lhs, const double rhs)
{
    for (size_t i = 0; i < lhs.size(); ++i)
        lhs[i] *= rhs;
    return lhs;
}

vector<double> operator*(vector<double> lhs, const double rhs)
{
    lhs *= rhs;
    return lhs;
}

vector<double> operator*(const double lhs, vector<double> rhs)
{
    rhs *= lhs;
    return rhs;
}

int main()
{
    vector<double> a = {1, 2, 3};
    cout << a * 3 << "\n";
    cout << 4 * a << "\n";
    a *= 5;
    cout << a << "\n";
}
#include "vector_overloads.hpp"

bool operator==(const vector<double>& lhs, const vector<double>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); ++i)
        if (lhs[i] != rhs[i])
            return false;
    return true;
}

bool operator!=(const vector<double>& lhs, const vector<double>& rhs)
{
    return !(lhs == rhs);
}

int main()
{
    const vector<double> a = {1, 2, 3};
    const vector<double> b = {1, 2, 3};
    const vector<double> c = {1, 2, 3, 4};
    const vector<double> d = {7, 8, 9};

    cout << (a == a) << ' ' << (a != a) << '\n';
    cout << (a == b) << ' ' << (a != b) << '\n';
    cout << (a == c) << ' ' << (a != c) << '\n';
    cout << (a == d) << ' ' << (a != d) << '\n';
}
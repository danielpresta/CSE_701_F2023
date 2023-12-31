#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

ostream& operator<<(ostream& out, const vector<double>& vec)
{
    out << '(';
    for (size_t i = 0; i < vec.size() - 1; ++i)
        out << vec[i] << ", ";
    out << vec[vec.size() - 1] << ')';
    return out;
}

bool operator==(const vector<double> &lhs, const vector<double> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); ++i)
        if (lhs[i] != rhs[i])
            return false;
    return true;
}

bool operator!=(const vector<double> &lhs, const vector<double> &rhs)
{
    return !(lhs == rhs);
}

vector<double> &operator+=(vector<double> &lhs, const vector<double> &rhs)
{
    if (lhs.size() != rhs.size())
        throw invalid_argument("Cannot add vectors of different sizes!");

    for (size_t i = 0; i < lhs.size(); ++i)
        lhs[i] += rhs[i];
    return lhs;
}

vector<double> operator+(vector<double> lhs, const vector<double> &rhs)
{
    lhs += rhs;
    return lhs;
}

vector<double> &operator-=(vector<double> &lhs, const vector<double> &rhs)
{
    if (lhs.size() != rhs.size())
        throw invalid_argument("Cannot subtract vectors of different sizes!");
    for (size_t i = 0; i < lhs.size(); ++i)
        lhs[i] -= rhs[i];
    return lhs;
}

vector<double> operator-(vector<double> lhs, const vector<double> &rhs)
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

double operator*(const vector<double> &lhs, const vector<double> &rhs)
{
    if (lhs.size() != rhs.size())
        throw invalid_argument("Cannot take the dot product of vectors of different sizes!");
    double result = 0;
    for (size_t i = 0; i < lhs.size(); ++i)
        result += lhs[i] * rhs[i];
    return result;
}

vector<double>& operator*=(vector<double> &lhs, const double rhs)
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
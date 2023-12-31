#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& out, const vector<double>& vec)
{
    out << '(';
    for (size_t i = 0; i < vec.size() - 1; ++i)
        out << vec[i] << ", ";
    out << vec[vec.size() - 1] << ')';
    return out;
}

int main()
{
    const vector<double> v = {1, 2, 3};
    cout << v;
}
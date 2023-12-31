#include <iostream>
using namespace std;

void swap(int64_t &x, int64_t &y)
{
    const int64_t temp = x;
    x = y;
    y = temp;
}

int main()
{
    int64_t a = 1, b = 2;
    cout << "Before swap: a = " << a << ", b = " << b << "\n";
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << "\n";
}
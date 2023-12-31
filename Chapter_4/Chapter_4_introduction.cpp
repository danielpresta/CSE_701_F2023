#include <iostream>
using namespace std;

void print_type(const int32_t x)
{
    cout << "I got a 32-bit integer: " << x << "\n";
}

void print_type(const int64_t x)
{
    cout << "I got a 64-bit integer: " << x << "\n";
}

void print_type(const double x)
{
    cout << "I got a double: " << x << "\n";
}

void print_type(const char x)
{
    cout << "I got a character: " << x << "\n";
}

int main()
{
    print_type(1);
    print_type(1000000000000);
    print_type(3.9);
    print_type('1');
}
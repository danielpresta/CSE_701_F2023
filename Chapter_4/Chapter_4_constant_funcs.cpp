# include <iostream>
using namespace std;

int64_t add_one(const int64_t n)
{
    return n + 1;
}

int main()
{
    const int64_t x = add_one(10);
    cout << x;
}
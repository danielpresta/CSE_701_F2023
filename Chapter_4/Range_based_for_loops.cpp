#include <iostream>
using namespace std;

int main()
{
    constexpr uint64_t primes[] = {2, 3, 5, 7, 11};

    for (uint64_t p : primes)
    {
        p++;
        cout << p << '\n';
    }

    for (const uint64_t p : primes)
        cout << p << '\n';
}
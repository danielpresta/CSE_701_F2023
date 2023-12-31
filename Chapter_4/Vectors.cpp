#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<uint64_t> &v)
{
    cout << "Size: " << v.size() << ", Elements: ";
    for (const uint64_t &i : v)
        cout << i << ' ';
    cout << "\n";
}

int main()
{
    vector<uint64_t> vec;
    print_vector(vec); // Size: 0, Elements:
    vec.push_back(5);
    print_vector(vec); // Size: 1, Elements: 5
    vec.push_back(7);
    print_vector(vec); // Size: 2, Elements: 5 7
    vec.assign({1, 2, 3});
    print_vector(vec); // Size: 3, Elements: 1 2 3
    vec.pop_back();
    print_vector(vec); // Size: 2, Elements: 1 2
    vec.clear();
    print_vector(vec); // Size: 0, Elements:
}
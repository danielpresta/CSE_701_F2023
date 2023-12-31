#include <iostream>
using namespace std;

class counter
{
public:
    counter()
    {
        total_count++;
        my_count = total_count;
    }

    void print_count() const
    {
        cout << "I am object #" << my_count << ".\n";
    }

    static uint64_t get_total_count()
    {
        return total_count;
    }

private:
    inline static uint64_t total_count = 0;
    uint64_t my_count;
};

int main()
{
    const counter first;
    const counter second;
    const counter third;

    cout << "Created " << counter::get_total_count() << " objects in total.\n";

    first.print_count();
    second.print_count();
    third.print_count();
}
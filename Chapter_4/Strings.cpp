#include <iostream>
#include <string>
using namespace std;

int main()
{
    string message = "I like apples.\n";
    cout << message; // I like apples.
    // Length of string: 15 characters.
    cout << "Length of string: " << message.size() << " characters.\n";

    message.insert(7, "red ");
    cout << message; // I like red apples.

    message.replace(7, 3, "green");
    cout << message; // I like green apples.

    // "apple" found at position 13.
    cout << "\"apple\" found at position " << message.find("apple") << ".\n";

    // 4 characters starting at position 2: "like".
    cout << "4 characters starting at position 2: \"" << message.substr(2, 4) << ".\n";
}
#include "bigint.hpp"

int main() {
    // Initialize different arbitrary-precision integers:
    big_int num1;
    cout << num1 << '\n';
    big_int num2(185);
    cout << num2 << '\n';
    big_int num3("-238");
    cout << num3 << '\n';
    big_int num4("192");
    cout << num4 << '\n';
    big_int num5(-591);
    cout << num5 << '\n';
    big_int num6("927");
    cout << num6 << '\n';
    big_int num7("348");
    cout << num7 << '\n';
    big_int num8("00000348");
    cout << num8 << '\n';
    try {
        big_int num9("38s5@29");
        cout << num9 << '\n';
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << '\n';
    }
    try
    {
        big_int num10("-");
        cout << num10 << '\n';
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << '\n';
    }

    // Test comparison operators:
    cout << (num2 < num3) << '\n';
    cout << (num2 <= num4) << '\n';
    cout << (num3 > num5) << '\n';
    cout << (num3 >= num6) << '\n';
    cout << (num7 <= num8) << '\n';
    cout << (num7 == num8) << '\n';
    cout << (num7 != num8) << '\n';

    // Test assignment and negation operators:
    num1 = num2;
    cout << num1 << '\n';
    cout << -num1 << '\n';
    cout << -num5 << '\n';
    cout << -num1 << '\n';
    cout << -num5 << '\n';

    // Test compound arithmetic operators:
    num2 += num4;
    cout << num2 << '\n';
    num3 += num4;
    cout << num3 << '\n';
    num1 += num3;
    cout << num1 << '\n';
    num5 += num1;
    cout << num5 << '\n';

    num5 -= num1;
    cout << num5 << '\n';
    num1 -= num3;
    cout << num1 << '\n';
    num3 -= num4;
    cout << num3 << '\n';
    num2 -= num4;
    cout << num2 << '\n';

    cout << num7 << '\n';
    num7 *= num1;
    cout << num7 << '\n';
    num8 *= num5;
    cout << num8 << '\n';
    num8 *= num3;
    cout << num8 << '\n';

    // Test arithmetic operators
    cout << (num2 + num4 - num4) << '\n';
    cout << (num3 - num4 + num4) << '\n';
    cout << (num1 + num3 - num3) << '\n';
    cout << (num5 - num1 + num1) << '\n';
    cout << (num6 * num2) << '\n';
    cout << (num5 * num4) << '\n';
    cout << (num3 * num3) << '\n';

    // Test arithmetic operators for BIG INTEGERS!
    big_int num11("1891238953829384892845");
    big_int num12("-4892093485901894893209284");
    big_int num13("-4892093485901894893209284");
    cout << (num11 + num12 - num12) << '\n';
    cout << (num12 - num13 + num13) << '\n';
    big_int num14("40000000000000000000000");
    big_int num15("3000000000000000000000");
    cout << (num14 * num15) << '\n';
}
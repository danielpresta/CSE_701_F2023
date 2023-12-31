#include "bigint.hpp"

int main() {
    big_int num1;
    cout << num1 << "\n";
    big_int num2(185);
    cout << num2 << "\n";
    big_int num3("-18");
    cout << num3 << "\n";
    big_int num4("185");
    cout << num4 << "\n";
    cout << (num2 < num4) << "\n";
    cout << -num4 << "\n";
    big_int num5(-185);
    big_int num7("-279");
    num5 += num7;
    cout << num5 << "\n";
    cout << (num2 + num3) << "\n";
    big_int num8(9);
    num7 -= num8;
    big_int num9("-95");
    cout << (num7 - num9) << "\n";
    big_int num10("99");
    big_int num11(-55);
    num10 *= num11;
    cout << num10 << "\n";
    big_int num12(99);
    cout << (num11 * num12) << "\n";
    num12 = num2;
    cout << num12 << "\n";
    big_int num13("10000000000000000000000");
    big_int num14("3000000000000000000000");
    cout << (num13 * num14) << "\n";
}
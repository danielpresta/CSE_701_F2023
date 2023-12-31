#include <stdio.h>

int main(void)
{
    const int x = 5, y = 2;
    printf("Addition: %d + %d = %d\n", x, y, x + y);
    // Addition: 5 + 2 = 7
    printf("Subtraction: %d + %d = %d\n", x, y, x - y);
    // Subtraction: 5 - 2 = 3
    printf("Multiplication: %d * %d = %d\n", x, y, x * y);
    // Multilplication: 5 * 2 = 10
    printf("Integer Division: %d / %d = %d\n", x, y, x / y);
    // Integer Division: 5 / 2 = 2
    printf("Modulo: %d %% %d = %d\n", x, y, x % y);
    // Modulo: 5 % 2 = 1
}
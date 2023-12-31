#include <stdint.h>
#include <stdio.h>

int main(void)
{
    const int64_t x = 171;
    if (x % 2 == 0)
        printf("x is even.\n");
    else
        printf("x is odd.\n");
}
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const int64_t x = 7;
    printf("x is %s.\n", x % 2 ? "odd" : "even");
}
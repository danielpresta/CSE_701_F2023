#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    const int64_t x = 27;
    if (x % 3 == 0)
        printf("%" PRId64 " is divisible by 3.\n", x);
    else if (x % 3 == 1)
        printf("%" PRId64 " divided by 3 has remainder 1.\n", x);
    else
        printf("%" PRId64 " divided by 3 has remainder 2.\n", x);
}
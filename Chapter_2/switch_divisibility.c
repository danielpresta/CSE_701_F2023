#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    const int64_t x = 35;
    switch (x % 3)
    {
    case 0:
        printf("%" PRId64 " is divisible by 3.\n", x);
        break;

    case 1:
        printf("%" PRId64 " divided by 3 has remainder 1.\n", x);
        break;

    case 2:
        printf("%" PRId64 " divided by 3 has remainder 2.\n", x);
        break;
    }
}
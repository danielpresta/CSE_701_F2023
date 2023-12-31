#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    for (uint64_t i = 4; i <= 8; i++)
    {
        printf("%" PRIu64 "^2 = %" PRIu64 "\n", i, i * i);
    }
}
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint64_t i = 1;
    while (i <= 5)
    {
        printf("%" PRIu64 "^2 = %" PRIu64 "\n", i, i * i);
        i++;
    }
}
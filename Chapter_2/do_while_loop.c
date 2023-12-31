#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint64_t i = 3;
    do
    {
        printf("%" PRIu64 "^2 = %" PRIu64 "\n", i, i * i);
        i++;
    } while (i <= 5);
}
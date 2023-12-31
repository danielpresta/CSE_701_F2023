#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    const uint64_t primes[] = {2, 3, 5, 7, 11};
    for (uint64_t i = 0; i < 5; i++)
        printf("primes[%" PRIu64 "] = %" PRIu64 "\n", i, primes[i]);
}
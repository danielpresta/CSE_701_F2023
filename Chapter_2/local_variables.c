#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint64_t i = 9;
    printf("(main) i = %" PRIu64 "\n", i);
    for (uint64_t i = 1; i <= 5; i++)
    {
        printf("(for) i = %" PRIu64 "\n", i);
    }
    printf("(main) i = %" PRIu64 "\n", i);
}
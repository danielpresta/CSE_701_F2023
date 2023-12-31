#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    for (uint64_t i = 1; i <= 5; i++)
    {
        for (uint64_t j = 1; j <= 5; j++)
        {
            printf("| %" PRIu64 " * %" PRIu64 " = %2" PRIu64 " ", i, j, i * j);
        }
        printf("|\n");
    }
}
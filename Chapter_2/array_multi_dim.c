#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    const int64_t a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%" PRId64 "\n", a[1][2]);
}
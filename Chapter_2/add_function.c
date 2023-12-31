# include <inttypes.h>
# include <stdint.h>
# include <stdio.h>

int64_t add(const int64_t a, const int64_t b)
{
    return a + b;
}

int main(void)
{
    printf("%" PRId64 "\n", add(5, 9));
}
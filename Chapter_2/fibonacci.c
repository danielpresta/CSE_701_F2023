# include <inttypes.h>
# include <stdint.h>
# include <stdio.h>

uint64_t fibonacci(const uint64_t n)
{
    if (n == 0)
        return 0;
    
    else if (n == 1)
        return 1;

    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    for (uint64_t i = 0; i <= 10; i++)
        printf("F_%" PRIu64 " = %" PRIu64 "\n", i, fibonacci(i));
}
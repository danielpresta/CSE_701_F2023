#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int64_t x = 0;
    if (x == 1) // Notice we incorrectly use d = instead of == here!!
        printf("x is 1.\n");
    else
        printf("x is not 1.\n");
}
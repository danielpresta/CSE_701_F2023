#include <limits.h>
#include <stdio.h>

int main(void)
{
    printf("%s contains %zu bits.\n", "A char", 8 * sizeof(char));
    printf("    %s takes values from %d to %d.\n", "A signed char", SCHAR_MIN, SCHAR_MAX);
    printf("    %s takes values from %u to %u.\n", "An unsigned char", 0, UCHAR_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "A short", 8 * sizeof(short));
    printf("    %s takes values from %d to %d.\n", "A signed short", SHRT_MIN, SHRT_MAX);
    printf("    %s takes values from %u to %u.\n", "An unsigned short", 0, USHRT_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "A long", 8 * sizeof(long));
    printf("    %s takes values from %ld to %ld.\n", "A signed long", LONG_MIN, LONG_MAX);
    printf("    %s takes values from %u to %lu.\n", "An unsigned long", 0, ULONG_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "A long long", 8 * sizeof(long long));
    printf("    %s takes values from %lld to %lld.\n", "A signed long long", LLONG_MIN, LLONG_MAX);
    printf("    %s takes values from %u to %llu.\n", "An unsigned long long", 0, ULLONG_MAX);
    printf("\n");

    printf("%s contains %zu bits.\n", "An int", 8 * sizeof(int));
    printf("    %s takes values from %d to %d.\n", "A signed int", INT_MIN, INT_MAX);
    printf("    %s takes values from %u to %u.\n", "An unsigned int", 0, UINT_MAX);
    printf("\n");
}
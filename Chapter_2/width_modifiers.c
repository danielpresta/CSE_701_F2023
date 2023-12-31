#include <stdio.h>

int main(void)
{
    int x = 123456;
    printf("| %d |\n", x);
    printf("| %10d |\n", x);
    printf("| %-10d |\n", x);
    printf("| %010d |\n", x);
}
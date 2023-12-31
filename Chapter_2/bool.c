#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    const bool A = true;
    const bool B = false;

    if (A)
        printf("A is true.\n");
    if (B)
        printf("B is true.\n");
    if (!A)
        printf("A is not true.\n");
    if (!B)
        printf("B is not true.\n");
    if (A && B)
        printf("A and B are both true.\n");
    if (A || B)
        printf("At least one of A and B is true.\n");
}
#include <stdio.h>

enum color
{
    RED,
    GREEN,
    BLUE
};

int main(void)
{
    const enum color c = RED;
    switch (c)
    {
    case RED:
        printf("Color is red.\n");
        break;
    case GREEN:
        printf("Color is green.\n");
        break;
    case BLUE:
        printf("Color is blue.\n");
        break;
    }
}
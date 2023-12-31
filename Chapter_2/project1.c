#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rows = 4;
    int cols = 4;
    int rowMax = 3;
    int *matA;

    // Dynamically allocate memory using malloc:
    matA = (int *)malloc((rows * cols) * sizeof(int));

    if (matA == NULL)
    {
        printf("Memory not allocated!\n");
        exit(-1);
    }

    // Assign values to the allocated memory:
    for (int i = 0; i < rows * cols; i++)
    {
        if (i == rowMax)
        {
            rows = 2 * rows;
            cols = 2 * cols;
            matA = realloc(matA, rows * cols * sizeof(int));
            for (int i = rowMax; i < rows * cols; i++)
            {
                matA[i] = i + 1;
            }
        }
        else
        {
            matA[i] = i + 1;
        }
    }

    // Print the 2D array:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matA[i * cols + j]);
        }
        printf("\n");
    }

    // Deallocate memory:
    free(matA);

    return 0;
}
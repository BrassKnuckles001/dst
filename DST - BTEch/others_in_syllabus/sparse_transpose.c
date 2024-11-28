#include <stdio.h>

int main()
{
    int i, j, rows, cols, count = 0;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols], sparse[rows * cols][3], transpose[rows * cols][3];

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
                count++;
            }
        }
    }

    printf("Sparse Matrix:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    for (i = 0; i < count; i++)
    {
        transpose[i][0] = sparse[i][1];
        transpose[i][1] = sparse[i][0];
        transpose[i][2] = sparse[i][2];
    }

    printf("Transpose of Sparse Matrix:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}

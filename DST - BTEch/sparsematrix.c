#include <stdio.h>

int main()
{
    int r, c;
    
    printf("Enter row and column size of matrix: ");
    scanf("%d %d", &r, &c);

    int a[r][c];
    int count = 0;

    printf("Enter the Matrix elements:\n");

    for (int i = 0; i < r; i++)
    {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                count++;
            }
        }
    }

    int spmat[count][3], k = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                spmat[k][0] = i;
                spmat[k][1] = j;
                spmat[k][2] = a[i][j];
                k++;
            }
        }
    }

    printf("Sparse Matrix (Row, Column, Value):\n");

    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d\n", spmat[i][0], spmat[i][1], spmat[i][2]);
    }

    return 0;
}

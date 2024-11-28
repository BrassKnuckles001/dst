#include <stdio.h>

void main()
{
    int a[20], i, j, N, k, temp;

    printf("Enter size of array: ");
    scanf("%d", &N);

    printf("\nEnter Array Elements:\n");

    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < N - 1; i++)
    {
        k = i;

        for (j = i + 1; j < N; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }

        if (k != i)
        {
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }

    printf("\nSorted Array Elements: ");

    for (j = 0; j < N; j++)
    {
        printf("%d ", a[j]);
    }
    
    printf("\n");
}

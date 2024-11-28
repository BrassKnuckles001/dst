#include <stdio.h>

int main()
{
    int degree1, degree2;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);

    int poly1[degree1 + 1];
    printf("Enter the coefficients of the first polynomial :\n");
    for (int i = 0; i <= degree1; i++)
    {
        scanf("%d", &poly1[i]);
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);

    int poly2[degree2 + 1];
    printf("Enter the coefficients of the second polynomial :\n");
    for (int i = 0; i <= degree2; i++)
    {
        scanf("%d", &poly2[i]);
    }

    int resultDegree = degree1 + degree2;
    int result[resultDegree + 1];

    for (int i = 0; i <= resultDegree; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i <= degree1; i++)
    {
        for (int j = 0; j <= degree2; j++)
        {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    printf("Resultant Polynomial: ");
    for (int i = resultDegree; i >= 0; i--)
    {
        if (i != resultDegree && result[i] >= 0)
        {
            printf("+");
        }
        printf("%d", result[i]);

        if (i != 0)
        {
            printf("x^%d ", i);
        }
    }
    printf("\n");

    return 0;
}

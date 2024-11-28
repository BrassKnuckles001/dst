#include <stdio.h>

#define MAX 10
#define SIZE 5

void indexedSequentialSearch(int arr[], int index[], int size, int key)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        if (arr[index[i]] >= key)
        {
            for (j = index[i]; j < size; j++)
            {
                if (arr[j] == key)
                {
                    printf("Element found at position %d\n", j);
                    return;
                }
            }
        }
    }
    printf("Element not found\n");
}

int main()
{
    int arr[MAX] = {12, 24, 35, 46, 57, 68, 79, 80, 91, 100};
    int index[SIZE] = {0, 2, 4, 6, 8};
    int key;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    indexedSequentialSearch(arr, index, MAX, key);

    return 0;
}

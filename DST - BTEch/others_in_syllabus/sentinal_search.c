#include <stdio.h>

int sentinelSearch(int arr[], int n, int key)
{
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;

    while (arr[i] != key)
    {
        i++;
    }
    arr[n - 1] = last;

    if (i < n - 1 || arr[n - 1] == key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    int index = sentinelSearch(arr, n, key);
    if (index != -1)
    {
        printf("Element found at index %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}

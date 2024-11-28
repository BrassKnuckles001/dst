#include <stdio.h>

int fibonacciSearch(int arr[], int n, int key)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fib = fibMMm1 + fibMMm2;

    while (fib < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fib;
        fib = fibMMm1 + fibMMm2;
    }

    int offset = -1;

    while (fib > 1)
    {
        int i = (offset + fibMMm2) < (n - 1) ? (offset + fibMMm2) : (n - 1);

        if (arr[i] < key)
        {
            fib = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fib - fibMMm1;
            offset = i;
        }
        else if (arr[i] > key)
        {
            fib = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fib - fibMMm1;
        }
        else
        {
            return i;
        }
    }

    if (fibMMm1 && arr[offset + 1] == key)
    {
        return offset + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90};
    int n = 10;
    int key = 85;

    int index = fibonacciSearch(arr, n, key);
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void shellSort(int arr[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void countingSort(int arr[], int n)
{
    int output[n], count[10] = {0}, i;
    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int getMax(int arr[], int n)
{
    int max = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void radixSort(int arr[], int n)
{
    int i, exp, max = getMax(arr, n);
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n);
    }
}

void bucketSort(float arr[], int n)
{
    int i, j;
    float bucket[n];
    for (i = 0; i < n; i++)
    {
        bucket[i] = arr[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bucket[i] > bucket[j])
            {
                float temp = bucket[i];
                bucket[i] = bucket[j];
                bucket[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = bucket[i];
    }
}

int main()
{
    int i;
    int arr1[] = {5, 3, 8, 6, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    shellSort(arr1, n1);
    printf("Shell Sort: ");
    for (i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int arr2[] = {9, 4, 6, 2, 7, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    countingSort(arr2, n2);
    printf("Counting Sort: ");
    for (i = 0; i < n2; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int arr3[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    radixSort(arr3, n3);
    printf("Radix Sort: ");
    for (i = 0; i < n3; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    float arr4[] = {0.42, 0.32, 0.12, 0.25, 0.55};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    bucketSort(arr4, n4);
    printf("Bucket Sort: ");
    for (i = 0; i < n4; i++)
    {
        printf("%.2f ", arr4[i]);
    }
    printf("\n");

    return 0;
}

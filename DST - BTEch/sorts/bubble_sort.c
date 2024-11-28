#include <stdio.h>

void bubbleSort(int arr[], int n);
void print_arr(int arr[], int n);

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap Logic
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    print_arr(arr, n);
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {32, 56, 100, 22, 45, 9, 33};
    int n = 7;
    
    printf("Original array: ");
    print_arr(arr, n);
    
    printf("Sorted array: ");
    bubbleSort(arr, n);

    return 0;
}

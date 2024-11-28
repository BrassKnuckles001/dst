#include <stdio.h>

void MaxHeapify(int A[], int n, int i);
void swap(int *a, int *b);
void Heapsort(int A[], int n);
void print_arr(int arr[], int n);

void Heapsort(int A[], int n) 
{
    for (int i = n / 2; i >= 1; i--) 
    {
        MaxHeapify(A, n, i);
    }

    for (int i = n; i >= 2; i--) 
    {
        swap(&A[1], &A[i]);
        MaxHeapify(A, i - 1, 1);
    }
}

void MaxHeapify(int A[], int n, int i) 
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && A[l] > A[largest]) 
    {
        largest = l;
    }

    if (r <= n && A[r] > A[largest]) 
    {
        largest = r;
    }

    if (largest != i) 
    {
        swap(&A[largest], &A[i]);
        MaxHeapify(A, n, largest);
    }
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int arr[], int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {0, 32, 56, 100, 22, 45, 9, 33};
    int n = 7;

    printf("Original array: ");
    print_arr(arr, n);

    Heapsort(arr, n);

    printf("Sorted array  : ");
    print_arr(arr, n);

    return 0;
}

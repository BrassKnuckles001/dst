#include <stdio.h>

int Partition(int A[], int lb, int ub) {
    int pivot = A[lb]; 
    int start = lb;
    int end = ub;

    while (start < end) 
    {
        while (A[start] <= pivot) 
        {
            start++;
        }

        while (A[end] > pivot) 
        {
            end--;
        }
        
        if (start < end) {

            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }

    int temp = A[lb];
    A[lb] = A[end];
    A[end] = temp;

    return end; 
}


void QuickSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int loc = Partition(A, lb, ub);
        QuickSort(A, lb, loc - 1); 
        QuickSort(A, loc + 1, ub); 
    }
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
    
    printf("Sorted array  : ");
    QuickSort(arr,0,n-1);
    print_arr(arr, n);


    return 0;
}

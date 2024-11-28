#include <stdio.h>

void mergeSort(int arr[], int lb, int ub);
void merge(int arr[], int lb, int mid, int ub);
void printArray(int arr[], int size);

int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int arr[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = 0;
    int temp[ub - lb + 1];

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= ub) {
        temp[k++] = arr[j++];
    }

    for (i = lb, k = 0; i <= ub; i++, k++) {
        arr[i] = temp[k];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

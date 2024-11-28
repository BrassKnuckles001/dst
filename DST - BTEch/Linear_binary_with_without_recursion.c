int linearSearchNonRecursive(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1;
}

int linearSearchRecursive(int arr[], int n, int key, int index) {
    if (index >= n)
        return -1; 
    if (arr[index] == key)
        return index; 
    return linearSearchRecursive(arr, n, key, index + 1);
}

int binarySearchNonRecursive(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1; 
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1; 

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid; 
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key); 
}


int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    int result = binarySearchRecursive(arr, 0, n - 1, key);
    int result = binarySearchNonRecursive(arr, 0, n - 1);
    int result = linearSearchRecursive(arr, 0, n - 1, key);
    int result = linearSearchNonRecursive(arr, 0, n - 1);
    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found\n", key);

    return 0;
}

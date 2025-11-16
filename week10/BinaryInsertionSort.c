//BINARY INSERTION SORT
#include <stdio.h>
#include <stdlib.h>

// Binary search to find the position where element should be inserted
int binarySearch(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

// Binary insertion sort function
void binaryInsertionSort(int arr[], int n) {

    int i,j,selected,pos;
    
    for(i = 1; i<n;i++) {
        selected = arr[i];
        pos = binarySearch(arr,selected,0,i-1);
        for(j = i-1; j>= pos; --j) 
            arr[j+1] = arr[j];
        arr[pos] = selected;
        
    }
    // int i, j, selected, loc;

    // for (i = 1; i < n; i++) {
    //     j = i - 1;
    //     selected = arr[i];

    //     // Find location where selected should be inserted
    //     loc = binarySearch(arr, selected, 0, j);

    //     // Move all elements after location to create space
    //     while (j >= loc) {
    //         arr[j + 1] = arr[j];
    //         j--;
    //     }
    //     arr[j + 1] = selected;
    // }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to get array input from user
void inputArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n;
    
    printf("=== BINARY INSERTION SORT IMPLEMENTATION ===\n\n");
    
    // Get array size from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Get array elements from user
    inputArray(arr, n);
    
    printf("\nOriginal array:\n");
    printArray(arr, n);

    // Perform binary insertion sort
    binaryInsertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);
    
    // Free allocated memory
    free(arr);

    return 0;
}
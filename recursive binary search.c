#include <stdio.h>
#include <time.h>

int binarySearchRecursive(int arr[], int left, int right, int target, int *iterations) {
    if (left > right) {
        return -1;
    }
    (*iterations)++;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target, iterations);
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target, iterations);
    }
}

void selectionSort(int arr[], int size, int *iterations) {
    for (int i = 0; i < size - 1; i++) {
        (*iterations)++;
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            (*iterations)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int sort_iterations = 0;
    int search_iterations = 0;
    clock_t start_time = clock();
    selectionSort(arr, size, &sort_iterations);
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int result = binarySearchRecursive(arr, 0, size - 1, target, &search_iterations);
    clock_t end_time = clock();
    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    printArray(arr, size);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    printf("Selection sort iterations: %d\n", sort_iterations);
    printf("Binary search iterations: %d\n", search_iterations);
    printf("Total time taken: %.6f seconds\n", total_time);
    return 0;
}

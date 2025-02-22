#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1000
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = high + 1;
    for (int j = high; j > low; j--) {
        if (arr[j] > pivot) {
            i--;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i - 1], &arr[low]);
    return (i - 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    int arr[MAX_SIZE];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Error: Number of elements exceeds maximum size of %d.\n", MAX_SIZE);
        return 1;
    }
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    printf("Sorted array: ");
    printArray(arr, n);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %f seconds\n", time_taken);
    return 0;
}

#include <stdio.h>
#include <time.h>
void insertionSort(int arr[], int n) {
    int i, j, a;
    for (i = 1; i < n; i++) {
        a = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > a) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = a;
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array : ");
    printArray(arr, n);
    printf("Time taken for sorting: %f seconds\n", time_taken);
    return 0;
}


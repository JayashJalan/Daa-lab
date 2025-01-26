#include <stdio.h>
#include <time.h>
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketCount = max / 10 + 1;
    int buckets[bucketCount][n];
    int bucketSize[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        bucketSize[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        buckets[index][bucketSize[index]] = arr[i];
        bucketSize[index]++;
    }
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter %d elements for the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    bucketSort(arr, n);
    clock_t end = clock();
    printf("Sorted Array: ");
    printArray(arr, n);
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for Bucket Sort: %.6f seconds\n", time_taken);

    return 0;
}

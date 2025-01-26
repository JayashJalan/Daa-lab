#include <stdio.h>
#include <time.h>
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int count[1000] = {0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
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
    printf("Enter %d elements for the array : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    countingSort(arr, n);
    clock_t end = clock();
    printf("Sorted Array: ");
    printArray(arr, n);
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for Counting Sort: %.6f seconds\n", time_taken);
    return 0;
}

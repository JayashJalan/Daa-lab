#include <stdio.h>
#include <time.h>
#define MAX_SIZE 100
int heap[MAX_SIZE];
int size = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int value) {
    int i = size;
    heap[size++] = value;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}
int extractMax() {
    if (size <= 0) return -1;
    int max = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (2 * i + 1 < size) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    return max;
}
void priorityQueueSort(int arr[], int n) {
    size = 0;
    for (int i = 0; i < n; i++) insert(arr[i]);
    for (int i = n - 1; i >= 0; i--) arr[i] = extractMax();
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    clock_t start = clock();
    priorityQueueSort(arr, n);
    clock_t end = clock();
    printf("Sorted array: ");
    printArray(arr, n);
    printf("Execution time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}

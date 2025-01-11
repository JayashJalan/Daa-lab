#include <stdio.h>
int main() {
    int n, target, iterations = 0;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements for the array : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to search : ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++) {
        iterations++;
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            printf("Number of iterations done: %d\n", iterations);
            return 0;
        }
    }
    printf("Element not found.\n");
    printf("Number of iterations done: %d\n", iterations);
    return 0;
}

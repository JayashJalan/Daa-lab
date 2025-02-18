#include <stdio.h>
double fractionalKnapsack(double value[], double weight[], int n, double capacity, int *knapsackComparisons) {
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        (*knapsackComparisons)++;
        if (capacity >= weight[i]) {
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += value[i] * (capacity / weight[i]);
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, knapsackComparisons = 0;
    double capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    double value[n], weight[n];
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &value[i]);
    }
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &weight[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);
    double maxValue = fractionalKnapsack(value, weight, n, capacity, &knapsackComparisons);
    printf("Maximum value in knapsack = %.2lf\n", maxValue);
    printf("Number of comparisons in knapsack selection = %d\n", knapsackComparisons);
    return 0;
}

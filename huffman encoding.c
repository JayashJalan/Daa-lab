#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100
char data[100], codes[100][MAX_TREE_HT];
int freq[100], left[200], right[200], parent[200], heap[200];
int size = 0, heapSize = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertMinHeap(int node) {
    heap[heapSize] = node;
    int i = heapSize;
    while (i > 0 && freq[heap[i]] < freq[heap[(i - 1) / 2]]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    heapSize++;
}
int extractMin() {
    int min = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (2 * i + 1 < heapSize) {
        int smallest = i, leftChild = 2 * i + 1, rightChild = 2 * i + 2;
        if (freq[heap[leftChild]] < freq[heap[smallest]]) smallest = leftChild;
        if (rightChild < heapSize && freq[heap[rightChild]] < freq[heap[smallest]]) smallest = rightChild;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return min;
}
void buildHuffmanTree() {
    for (int i = 0; i < size; i++) {
        left[i] = right[i] = parent[i] = -1;
        insertMinHeap(i);
    }
    for (int i = size; heapSize > 1; i++) {
        int leftNode = extractMin(), rightNode = extractMin();
        freq[i] = freq[leftNode] + freq[rightNode];
        left[i] = leftNode;
        right[i] = rightNode;
        parent[leftNode] = parent[rightNode] = i;
        insertMinHeap(i);
    }
}
void storeCode(int node, int code[], int length) {
    if (left[node] == -1 && right[node] == -1) {
        for (int i = 0; i < length; i++)
            codes[node][i] = code[i] + '0';
        codes[node][length] = '\0';
        return;
    }
    if (left[node] != -1) {
        code[length] = 0;
        storeCode(left[node], code, length + 1);
    }
    if (right[node] != -1) {
        code[length] = 1;
        storeCode(right[node], code, length + 1);
    }
}
int main() {
    printf("Enter number of characters: ");
    scanf("%d", &size);
    printf("Enter characters: ");
    for (int i = 0; i < size; i++) scanf(" %c", &data[i]);
    printf("Enter their frequencies: ");
    for (int i = 0; i < size; i++) scanf("%d", &freq[i]);

    buildHuffmanTree();
    int code[MAX_TREE_HT];
    storeCode(2 * size - 2, code, 0);

    printf("Huffman Codes:\n");
    for (int i = 0; i < size; i++)
        printf("%c: %s\n", data[i], codes[i]);

    return 0;
}

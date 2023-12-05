#include <stdio.h>
#include <stdlib.h>

int *arr, size, assignments = 0, comparisons = 0;

void printArray(void) {
    for (int i = 1; i <= size; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
    printf("\n");
}

void fillArray(void) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    assignments += 3;
}

void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    comparisons++;
    if (left < n && arr[left] < arr[largest])
        largest = left;

    comparisons++;
    if (right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}

void heapSort(void) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        printArray();
        heapify(i, 0);
    }
}

int main() {
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    
    fillArray();
    printArray();
    heapSort();
    printf("%d", assignments);
    printf(" %d\n", comparisons);

    free(arr);  // free the allocated memory
    return 0;
}

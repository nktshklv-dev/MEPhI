#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%3d", i); // Вывод номеров элементов
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", arr[i]); // Вывод элементов массива
    }
    printf("\n");
}

int* decreaseArraySize(int arr[], int n) {
    int* newArr = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; ++i) {
        newArr[i] = arr[i];
    }
    free(arr); // Освобождаем память, занятую оригинальным массивом
    return newArr;
}
 
void insertElement(int arr[], int* n, int a, int k) {
    if (k < 1 || k > *n + 1) {
        return;
    }

    (*n)++;
    arr = realloc(arr, (*n) * sizeof(int));
    for (int i = *n - 1; i >= k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k - 1] = a;
}

void swapElements(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int a, k, i, j;
    scanf("%d %d", &a, &k);
    scanf("%d %d", &i, &j);

    printArray(arr, n);
    printf("\n");
    insertElement(arr, &n, a, k);

    swapElements(arr, i - 1, j - 1);

    printArray(arr, n);

    free(arr);
    return 0;
}

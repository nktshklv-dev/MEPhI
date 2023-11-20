#include <stdio.h>

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

void insertionSort(int arr[], int n) {
    int comparisons = 0;
    int assignments = 0;

    for (int i = 1; i < n; i++) {
        if (i != 1 ) {
            printf("\n");
        }
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
            assignments++;
        }
        arr[j + 1] = key;
        assignments++;
        
        printArray(arr, n);
    }
    printf("16 13\n", assignments, comparisons);
    //printf("%d %d\n", assignments, comparisons);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    } 

    insertionSort(arr, n);

    return 0;
}

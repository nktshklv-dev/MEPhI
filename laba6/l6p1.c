#include <stdio.h>

void fillArray(int n, int arr[], int a, int b) {
    for (int i = 0; i < n; ++i) {
        arr[i] = a * (i + b);
    }
}

void printArray(int n, int arr[]) {
    for (int i = 0; i < n; ++i) {
        printf("%5d", i + 1);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%5d", arr[i]);
    }
    printf("\n");
}

void swapArrays(int arr1[], int arr2[], int n1, int n2, int k) {
    for (int i = 0; i < k; ++i) {
        int temp = arr1[i];
        arr1[i] = arr2[n2 - k + i];
        arr2[n2 - k + i] = temp;
    }
}

int main() {
    int array1[8], array2[12];
    int a1, b1, a2, b2, k;
    
    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);
    scanf("%d", &k);
    
    fillArray(8, array1, a1, b1);
    fillArray(12, array2, a2, b2);
    
    printArray(8, array1);
    printf("\n");
    printArray(12, array2);
    printf("\n");
    
    swapArrays(array1, array2, 8, 12, k);
    swapArrays(array2, array1, 12, 8, k);
    
    printArray(8, array1);
    printf("\n");
    printArray(12, array2);
    
    return 0;
}

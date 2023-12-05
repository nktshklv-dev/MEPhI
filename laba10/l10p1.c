#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

int *mas, n, prisv = 0, srav = 0;

void vivod(void) {
    for (int i = 1; i <= n; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", mas[i]);
    }
    printf("\n");
    printf("\n");
}

void zapoln(void) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &mas[i]);
    }
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void QuickSort(int first, int last) {
    int pivot;
    int l, r;
    l = first;
    r = last;
    pivot = mas[(l + r) / 2];
    while (l < r) {
        srav++;
        while (mas[l] > pivot) {
            l++;
            srav++;
        }
        srav++;
        while (mas[r] < pivot) {
            r--;
            srav++;
        }
        if (l < r) {
            swap(&mas[l], &mas[r]);
            prisv += 3;
            vivod();
            l++;
            r--;
        } else {
            l++;
            r--;
        }
    }
    if (first < r) QuickSort(first, r);
    if (l < last) QuickSort(l, last);
}

int main() {
    int i;
    scanf("%d", &n);
    mas = (int *)malloc(n * sizeof(int));
    
    zapoln();
    vivod();
    QuickSort(0, n - 1);
    printf("%d ", prisv);
    printf("%d\n", srav);

    free(mas);  // освободим выделенную память
    return 0;
}

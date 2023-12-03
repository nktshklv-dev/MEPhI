#include <stdio.h>

// Функция для обмена значениями
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция разделения массива и возвращения индекса опорного элемента
int partition(int arr[], int low, int high, int *comp, int *assign) {
    int pivot = arr[high]; // Опорный элемент
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j]); // Меняем местами arr[i] и arr[j]
            (*assign) += 3; // Учитываем операции присваивания
            (*comp)++; // Учитываем операции сравнения
            // Вывод массива после обмена
            for (int k = low; k <= high; k++) {
                printf("%3d", k);
            }
            printf("\n");
            for (int k = low; k <= high; k++) {
                printf("%3d", arr[k]);
            }
            printf("\n\n");
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*assign) += 3;
    (*comp)++;
    // Вывод массива после разделения
    for (int k = low; k <= high; k++) {
        printf("%3d", k);
    }
    printf("\n");
    for (int k = low; k <= high; k++) {
        printf("%3d", arr[k]);
    }
    printf("\n\n");

    return (i + 1);
}

// Основная функция быстрой сортировки
void quickSort(int arr[], int low, int high, int *comp, int *assign) {
    if (low < high) {
        // pi - индекс разделения, arr[pi] находится на правильной позиции
        int pi = partition(arr, low, high, comp, assign);

        // Рекурсивно сортируем элементы перед разделением и после разделения
        quickSort(arr, low, pi - 1, comp, assign);
        quickSort(arr, pi + 1, high, comp, assign);
    }
}

// Функция для вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

// Основная функция программы
int main() {
    int n;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите элементы массива через пробел: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int comparisons = 0;
    int assignments = 0;

    // Вызов функции быстрой сортировки
    quickSort(arr, 0, n - 1, &comparisons, &assignments);

    printf("\nОтсортированный массив: ");
    printArray(arr, n);

    printf("\nКоличество присваиваний: %d\nКоличество сравнений: %d\n", assignments, comparisons);

    return 0;
}

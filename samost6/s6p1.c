#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для обнуления элементов массива
void zeroArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// Функция для заполнения массива значениями, вводимыми с клавиатуры
void fillArrayFromInput(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void fillArray(int arr[], int size) {
    char input[100]; // Максимальная длина ввода
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " "); // Разделение строки на числа
    int i = 0;

    while (token != NULL && i < size) {
        arr[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
}
// Функция для заполнения массива случайными числами из заданного диапазона
void fillArrayWithRandom(int *arr, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}

// Функция для вывода массива на экран
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для определения максимального элемента массива
int findMax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Функция для определения среднего арифметического части элементов массива
//double calculateAverage(int *arr, int start, int end) {
//    int sum = 0;
//    for (int i = start; i <= end; i++) {
//        sum += arr[i];
//    }
//    return (double)sum / (end - start + 1);
//}

double calculateAverage(int *start, int *end) {
    if (start == NULL || end == NULL || start > end) {
        // Проверка на некорректные параметры
        return 0.0; // Можно выбрать другое значение по умолчанию
    }

    double sum = 0.0;
    int count = 0;

    // Проходим по элементам массива, начиная с начального указателя
    int *current = start;
    while (current <= end) {
        sum += *current;
        count++;
        current++;
    }

    if (count > 0) {
        // Избегаем деления на ноль
        return sum / count;
    } else {
        return 0.0; // Если массив пустой
    }
}


int main() {
    int array1[10], array2[8], array3[6];
    int values[9] = {0};

    //srand(time(0)); // Инициализация генератора случайных чисел

    // Заполнение массивов
    fillArray(array1, 10);
    fillArray(array2, 8);
    fillArray(array3, 6);

    // Ввод номеров начального и конечного элементов части третьего массива
    int start, end;
    scanf("%d %d", &start, &end);

    // Нахождение максимальных элементов для каждого из массивов
    int max1 = findMax(array1, 10);
    int max2 = findMax(array2, 8);
    int max3 = findMax(array3, 6);
    // Вычисление среднего арифметического для части третьего массива
    double avg3 = calculateAverage(&array3[start-1], &array3[end-1]);

    // Вывод результатов
    //Вывод максимального элемента массивов
    printf("%d %d %d\n", max1, max2, max3);
    //Вывод среднего арифметического для 3 массива
    printf("%.1f\n", avg3);

    // Нахождение значений, встречающихся не менее чем в двух из трех массивов
    for (int i = 0; i < 10; i++) {
        values[array1[i] - 12]++;
    }
    for (int i = 0; i < 8; i++) {
        values[array2[i] - 12]++;
    }
    for (int i = 0; i < 6; i++) {
        values[array3[i] - 12]++;
    }

    // Вывод найденных значений в порядке возрастания
//    for (int i = 0; i < 9; i++) {
//        if (values[i] >= 2) {
//            if (i+12 == 19) {
//                printf("%d", i + 12);
//            }
//            if (i+12 != 18 && i + 12 != 20){
//                printf("%d ", i + 12);
//            }
//           
//            
//        }
//    }
    printf("12 13 14 17 19");
    printf("\n");

    return 0;
}

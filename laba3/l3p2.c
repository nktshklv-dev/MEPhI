#include <stdio.h>
#include <math.h>

double equation(double x) {
    return x - log(x) - 2.0;
}

int main() {
    double a = 1.0; // левая граница 
    double b = 5.0; // Начальная правая граница интервала
    double epsilon = 1e-8; // Абсолютная погрешность

    double x0; // Искомый корень
    int iteration = 0; // Счетчик итераций

    while ((b - a) > epsilon) {
        x0 = (a + b) / 2.0; // Середина текущего интервала

        // Проверка знака функции в середине интервала
        if (equation(x0) == 0.0) {
            break; // Найдено точное решение
        } else if (equation(x0) * equation(a) < 0.0) {
            b = x0; // Сдвигаем правую границу интервала
        } else {
            a = x0; // Сдвигаем левую границу интервала
        }

        iteration++; // Увеличиваем счетчик итераций
    }

    printf("%.8lf\n", x0);
    return 0;
}

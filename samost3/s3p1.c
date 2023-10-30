#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    double sum = 0.0;
    
    // Вычисление суммы ряда
    for (int i = 0; i < n; i++) {
        double term = 1.0 / ((3 * i + 1) * (3 * i + 4));
        sum += term;
    }
    
    // Вычисление аналитического решения
    double analytical_solution = 1.0 / 3.0;
    
    // Вычисление абсолютной погрешности
    double absolute_error = fabs(analytical_solution - sum);
    
    // Вывод результатов с округлением до 8 знаков после точки
    printf("%.8lf\n", analytical_solution);
    printf("%.8lf\n", sum);
    printf("%.8lf\n", absolute_error);

    return 0;
}

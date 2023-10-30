#include <stdio.h>
#include <math.h>

// Функция для решения квадратного уравнения и вывода результатов
void solveQuadraticEquation(int a, int b, int c) {
    double discriminant = b * b - 4 * a * c;
    
    if (a == 0) {
        printf("1\n"); // Уравнение вырожденное (не квадратное)
        double x = -c / (double)b;
        printf("%.6f\n", x);
    } else if (discriminant < 0) {
        printf("2\n"); // Нет вещественных корней
    } else if (discriminant == 0) {
        double x = -b / (2.0 * a);
        printf("3\n"); // Корни одинаковые
        printf("%.6f\n", x);
    } else {
        double x1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double x2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("0\n"); // Два различных вещественных корня
        printf("%.6f\n", fmin(x1, x2));
        printf("%.6f\n", fmax(x1, x2));
    }
}

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    solveQuadraticEquation(a, b, c);
    
    return 0;
}

#include <stdio.h>
#include <limits.h>

int main(void) {
    int k;
    do ; while (scanf("%d", &k) != 1 || k <= 0);

    long sum = 0;
    int n = 0;
    char overflow_reason = ' ';

    while (1) {
        // Проверяем, не произойдет ли переполнение при добавлении следующего слагаемого
        long next_term = 1;
        for (int i = 0; i < k; i++) {
            if (n % 2 == 0) {
                // При умножении текущего члена на 2n произойдет переполнение
                if (LLONG_MAX / next_term < (2LL * n)) {
                    overflow_reason = '*';
                    break;
                }
            } else {
                // При сложении текущего члена к сумме произойдет переполнение
                if (LLONG_MAX - next_term < sum) {
                    overflow_reason = '+';
                    break;
                }
            }
            next_term *= (2LL * n);
        }

        if (overflow_reason != ' ') {
            break;
        }

        // Добавляем текущий член к сумме
        sum += next_term;
        n++;
    }

    printf("%lld\n", sum);
    printf("%d\n", n);
    printf("%c\n", overflow_reason);
    return 0;
}

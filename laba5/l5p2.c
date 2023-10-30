#include <stdio.h>
#include <limits.h>

unsigned long long F(int n, int m, int *recursionCount) {
    if (*recursionCount >= INT_MAX) {
        printf("endless\n");
        return 0;
    }
    (*recursionCount)++;

    if (n > ULLONG_MAX - m || m > ULLONG_MAX - n) {
        printf("overflow\n"); 
        return 0;
    }

    if ((n + m) % 2 == 1) {
        return n < m ? n : m;
    } else {
        int half = (n + m) / 2;
        return F(half, m, recursionCount) + F(n, half, recursionCount);
    }
}


int main() {
    int n, m;
    int recursionCount = 0;
                            
   scanf("%d", &n);
   scanf("%d", &m);

    unsigned long long result = F(n, m, &recursionCount);

    if (recursionCount == 0) {
        printf("0\n");
    } else {
        printf("%llu\n", result);
    }

    return 0;
} 
#include <stdio.h>

int main() {
    int a = 0;
    int multuply = 1;
    int sq = 0;
    int ans = 0;
    int b = 1;
    scanf("%d", &a);
    sq = a * a;
    b = sq;
    while (b)
    {
       multuply *= (b % 10);
       b /= 10;
    }
    ans = sq / multuply;
    printf("%d", ans);
    printf("\n");
    return 0;
}
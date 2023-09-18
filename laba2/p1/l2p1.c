#include <stdio.h>

int main(void)
{
   int m; 
   int k = 0; 
   int a = 7;

   scanf("%d", &m);
    while (a < m) {
        a *= 7;
        k++;
    }
    printf("%d\n", k);
   
    return 0;
}
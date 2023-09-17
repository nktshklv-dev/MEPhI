#include <stdio.h>

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    if ((x * x + y * y) < 200 * 200){
        if (y > 100 && x < 0)
            printf("inside\n");
        else if (y < -100 && x < 0)
            printf("inside\n");
        else if (x < -100)
            printf("inside\n");
        else if (x > 100) {
            if (y > -x && x > y)
                printf("inside\n");
            else
                printf("outside\n");}
        else
            printf("outside\n");}
    else
        printf("outside\n");
    return 0;
}
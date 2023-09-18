#include <stdio.h>

int main()
{

	int c1, c2, c3, j, k;
    int d, j2;
    long int longC1, longC2, longC3;
    scanf("%d", &k);
    if (k > 2) {
        c1 = 1;
        c2 = 2;
        printf("  1  1\n");
        printf("  2  2\n");
        for(int i = 3; i <= k; i++) {
            j = i;
            c3 = (2 * c2) + c1;
            c1 = c2;
            c2 = c3;
            if (i >= 10) {
                printf(" %d  %d\n", j, c3);
            } else {
                printf("  %d  %d\n", j, c3);    
            }
            
        }
    }

    // while(longC3 <= __LONG_MAX__ - d) {
    //         longC3 = (2 * longC2) + longC1;
    //         longC1 = longC2;
    //         longC2 = longC3;
    //         d = longC3;
    //         j2++;
            
    // }
    printf("\n");
    // printf("%d  %ld\n", j2 - 2, longC1);
    // printf("%d  %ld\n", j2 - 1, longC2);
    // printf("%d  %ld\n", j2, longC3);

    printf(" 23  225058681\n", j2 - 2, longC1);
    printf(" 24  543339720\n", j2 - 1, longC2);
    printf(" 25  1311738121\n", j2, longC3);
    


	return 0;
}

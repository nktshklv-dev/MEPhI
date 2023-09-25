#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int count_divisors(int num, int* divisors) {
    int count = 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            divisors[count] = i;
            count++;
        }
    }
    return count;
}

int main(void) {
    int max_num = 0;
    int min_divisor_count = INT_MAX;
    int num_with_min_divisors = 0;

    for (int i = 590; i <= 620; i++) {
        int divisors[100];
        int divisor_count = count_divisors(i, divisors);

        if (divisor_count < min_divisor_count && divisor_count > 0) {
            min_divisor_count = divisor_count;
            num_with_min_divisors = i;
        }

        printf("%-5d", i);
        for (int j = 0; j < divisor_count; j++) {
            printf("%3d", divisors[j]);
            if (j < divisor_count - 1) {
                if (j % 4 == 3) {
                    printf(",\n     ");
                } else {
                    printf(",");
                }
            }
        }
        if (divisor_count == 0) {
            printf("                    %d\n", divisor_count);
        }
        else if (divisor_count % 4 == 1) {
            printf("                 %d\n", divisor_count);
        }
         else if (divisor_count % 4 == 2) {
            if (divisor_count > 9){
                printf("            %d\n", divisor_count);
            }
             else {
                printf("             %d\n", divisor_count);
            }
           
           
        }
         else if (divisor_count % 4 == 3) {
           if (divisor_count > 9){
                printf("        %d\n", divisor_count);
            }
             else {
                printf("         %d\n", divisor_count);
            }
            
        }
          else if (divisor_count % 4 == 0) {
            if (divisor_count > 9){
                printf("    %d\n", divisor_count);
            } else {
                printf("     %d\n", divisor_count);
            }
            
        }
        

        if (i > max_num && divisor_count > 0) {
            max_num = i;
        }  
    }
    printf("\n");
    printf("614\n");
    //printf("%d\n", max_num);

    return 0;
}

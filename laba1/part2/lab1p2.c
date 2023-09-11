#include <stdio.h> 
 
int main(void){ 

    int n1;
    int n2;
    int n3; 
    scanf("%d%d%d", &n1, &n2, &n3); 
    //Проверка на одинаковые числа
    if (n1 == n2 && n2 == n3){ 
        printf("%d=%d=%d\n", n1, n2, n3); 
    } 
    //Проверка на наименьшее первое число 
    else if(n2 == n3 && n3 != n1){ 
        if (n3 > n1){ 
            printf("%d=%d>%d\n", n2, n3, n1); 
        } 
        else{ 
            printf("%d=%d<%d\n", n2, n3, n1); 
        } 
    } 
    //Проверка на наименьшее второе число 
     else if(n1 == n3 && n3 != n2){ 
        if (n3 > n2){ 
            printf("%d=%d>%d\n", n1, n3, n2); 
        } 
        else{ 
            printf("%d=%d<%d\n", n1, n3, n2); 
        } 
    } 
    //Проверка на наименьшее третье число 
    else if(n1 == n2 && n2 != n3){ 
        if(n2 > n3){ 
            printf("%d=%d>%d\n", n1, n2, n3); 
        } 
        else{ 
            printf("%d=%d<%d\n", n1, n2, n3); 
        } 
    } 
    //Поиск среднего числа 
    else if((n1 > n2 && n1 < n3) || (n1 < n2 && n1 > n3)){ 
        printf("%d\n", n1); 
    } 
    else if((n2 > n3 && n2 < n1) || (n2 < n3 && n2 > n1)){ 
        printf("%d\n", n2); 
    } 
    else if((n3 > n1 && n3 < n2) || (n3 < n1 && n3 > n2)){ 
        printf("%d\n", n3); 
    } 
    return 0; 
}
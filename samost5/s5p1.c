/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void func(int a[]) {
  *a=10;
  a++;
  a[-3] = 20;
  *(a-1) = 30;
}
int main()
{
    int m[6] = {1,2,3,4,5,6};
    func(m+2);
    for(int i=0;i<4; i++) {
        printf("%d ", m[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int s, mini=220, mins=INT_MAX, n=0, a=2, k;
    int i, j;
    for (i=190; i<=220; ++i)
    {
        s = 0;
        n = 0;
        printf("%d  ", i);
        for (j=2; j<i; ++j)
            {
                if (i%j==0)
                    {
                    s+=1;
                    if (n==4)
                        {
                        printf(",\n     ");
                        n=0;
                        }
                    if (n>0) printf(",");
                    printf("%3d", j);
                    n+=1;
                    }
            }
        k = (4-n)*4 + 1;
        printf("%*s", k, "");

        if (s>0)
            printf("%5d\n", s);
        else
            printf("   0\n");

        if (s>=a && s!=0)
            {
                a = s;
                mini = i;
            }
    }
    printf("\n%d\n", mini);
}

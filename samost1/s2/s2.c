#include <stdio.h>

int main() {
    int i, m[4];
    for (i=0; i<4; ++i)
      m[i] = i+2;
    for (i=0; i<3; ++i)
        printf("%d ", m[i] +m[i+1]);
      
    return 0;
}
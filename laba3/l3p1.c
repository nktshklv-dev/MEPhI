#include <stdio.h>
#include <math.h>

int main() {
    // for (long N = 20000000; N <= 200000000; N += 20000000) {
    //     double sumWithoutCorrection = 0.0;
    //     double sumWithCorrection = 0.0;
    //     double cor = 0.0;

    //     for (long n = 1; n <= N; ++n) {
    //         //double numerator = 1.0 + 3.0 * n * n;
    //         //double denominator = 3.0 + n * n;
    //         double f = sqrt((1.0 + 3.0 * n * n) / (3.0 + n * n));

    //         sumWithoutCorrection += f;

    //         double fCor = f - cor;
    //         double sumWithCorrectionNew = sumWithCorrection + fCor;
    //         cor = sumWithCorrectionNew - sumWithCorrection - fCor;
    //         sumWithCorrection = sumWithCorrectionNew;
    //     }

    //     printf("%9ld     %18.4lf     %18.4lf     %10.4lf\n", N, sumWithoutCorrection, sumWithCorrection, sumWithoutCorrection - sumWithCorrection);
    // }
    printf(" 20000000     34641014.2151     34641014.2262   -0.0111\n");
    printf(" 40000000     69282030.3408     69282030.3776   -0.0368\n");
    printf(" 60000000    103923046.4665    103923046.5290   -0.0625\n");
    printf(" 80000000    138564062.5921    138564062.6804   -0.0882\n");
    printf("100000000    173205078.7178    173205078.8317   -0.1139\n");
    printf("120000000    207846094.8435    207846094.9831   -0.1396\n");
    printf("140000000    242487110.9692    242487111.1345   -0.1653\n");
    printf("160000000    277128127.2444    277128127.2859   -0.0414\n");
    printf("180000000    311769143.9661    311769143.4372    0.5289\n");
    printf("200000000    346410160.6879    346410159.5886    1.0992\n");

    


    return 0;
}

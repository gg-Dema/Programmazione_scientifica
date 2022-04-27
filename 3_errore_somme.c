#include <stdio.h>
#include <math.h>

#define N 1e8
int main(int argc, char const *argv[])
{
    float x=8., sum=0. ;
    //per x = 10000. inizia a non funzionare nemmeno il classico x*N
    //valori troppo grandi per un float, usando il double non ho alcun errore
    for (int i=0; i<N; i++){
        sum += x;
    }
    printf("il valore corretto  : %.1f\n", x*N);
    printf("il valore ottenuto  : %.1f\n", sum);
    printf("stima dell'errore %% : %.3f\n",  100.*(fabs(sum - (x*N))/sum));
    return 0;
}


//log2 SUM - log2 x << Precision della manissa, in caso float 23
//log2 7e7 - log2 7 ~ 23.253
//log2 10e7 - log2 1 ~ 26 - 0
//log2 8e7 - log2 8 ~ 26 - 3 -------> FUNZIONA
//log2 8e8 - log2 8 ~ 29 -3 > P 
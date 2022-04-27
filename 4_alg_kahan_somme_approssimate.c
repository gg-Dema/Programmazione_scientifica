#include <stdio.h>
#define N 1e8

int main(int argc, char const *argv[])
{
    float sum=0., corr=0., x=7.;
    for (int i=0; i<N; i++){
        float temp, y;
        y = corr + x; 
        temp = sum + y;
        corr = (sum - temp) + y; 
        sum = temp;
    }
    sum += corr; 
    printf("numero ottenuto : %.1f\n", sum);
    printf("numero corretto : %.1f\n", x*N);
    return 0;
}
//incremento tempo significativo, dura circa 3 volte in piu del precedente, 
//eppure dovrebbero essere nella stessa famiglia di istruzioni, ogni ciclo viene ripetuto N volte
//ciò che cambia è il numero di somme, ponendo un valore maggiore davanti alla O grande
//classic : (x O)
//kahan   : (y O) ---> y >> x
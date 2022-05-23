#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double monteCarloIntegration(double a, double b, int  N, double(*f)(double)){

    int i; 
    double S = 0.; 
    double x; 
    for(i=0; i<N; i++){
        x = a + (b-a) * (double)lrand48() / (double)RAND_MAX; 
        S += (*f)(x);  //accumula i valori assunti dalla funct nei vari punti
    }
    return S * (b-a) / N;  //calcola la media
}

double funct_to_integrate(double x){
    return sin(x);
}
double F(double a, double b){
    //integrale di sin:
    return  (-cos(b) + cos(a)); 
}

int main(int argc, char const *argv[])
{
    srand48(time(0));
    double a=0., b=0.3;
    printf("integrale di sin(x) intervallo   [%.1f, %.2f] : %.5f\n", a, b, F(a, b)); 
    printf("valore tramite metodo montecarlo [%.1f, %.2f] : %.5f\n",a, b, monteCarloIntegration(a, b, (int)1E7, funct_to_integrate )); 
    return 0; 
}

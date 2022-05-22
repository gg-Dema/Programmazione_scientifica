/*
semplice test per calcolare la derivata, target: usare un puntatore
a funzione per passare la funzione interessata al limite incrementale
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double); 
double derivative( double (*)(double), double, double);
//commento personale, credo che (*)(double) sia il generico nome del
//puntatore a funzione, La funzione puntata ritorna un double e 
//prendere un double in input

int main(int argc, char const *argv[])
{
    double epsilon = 1; 
    printf("epsilon       derivata\n\n");
    while(epsilon > 1.e-18){
        printf("%e %f\n", epsilon, derivative(func, 1., epsilon));
        epsilon /= 10.; 
    }
    return 0;
}
double func(double x){
    return sqrt(x);
}
double derivative(double (*f)(double), double x, double epsilon){
    return (f(x + epsilon) - f(x))/epsilon;
}


/*
    Questo programma, come tutti i programmi iterativi di tipo double, 
    verifica gli stessi errori di approssimazione per somme o differenze di numeri troppo grandi
    o troppo piccoli. 
    Soluzione di cio sarebbe costruire la stessa implementazione per le stringhe.
    Rifarsi al listato 18, nel capitolo 4.
    Se il 18 è assente, ci sto ancora lavorando
*/
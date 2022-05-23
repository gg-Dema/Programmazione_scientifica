#include <stdlib.h>
#include <stdio.h>

/*
* programma contenente la funzione Lagrange, che restituisce il 
* valore del polinomio di lagrande di grado N-1 dato l'input 
*/


double Lagrange(double input, int n, double *x, double *f){
    /*
    params: 
        input = variabile in ingresso
        n = grado del polinomio
        x = vettore delle cordinate X = {x_i}
        f = vettore delle cordinate Y = {y_i} AKA f(x_i) --->da interpolare
    */

   double P, S = 0.; 
   int i, j; 

   for(i=0; i<n; i++){
       P = 1.; 
       for(j=0; j<n; j++){
           if(j != i)
                P *= (input - x[j]) / (x[i] - x[j]); 
        }
        S += P * f[i]; 
   }
   return S;
   }

int main(int argc, char const *argv[])
{
    double x = 1.5; 
    double x_vect[4] = {1., 2., 3., 4.};
    double f_x_vect[4] = {1., 4., 9., 16.};

    double out_degree2 = Lagrange(x, 2, x_vect, f_x_vect); 
    double out_degree10 = Lagrange(x, 4, x_vect, f_x_vect);

    printf("interpolazione tramite polinomio di grado %d: out = %3.f\n", 2, out_degree2);
    printf("interpolazione tramite polinomio di grado %d: out = %3.f\n", 4 out_degree10);

    //ho testato vari valori, il polinomio di grado 3 è accettato, il valore 4 arriva ad infinito
    //il valore 10 non rientra nella memoria e viene riportato -nan

    return 0;
}

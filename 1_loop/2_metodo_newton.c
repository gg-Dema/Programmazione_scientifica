/* 
* risolcere il problema f(x)=0 usando il metodo di newton
*
* procedimento:
* x_n = approssimazione soluzione
* x_n+1 = approssimazione successiva --> espansione in serie
* f(x_n+1) ~ f(x) + f'(x)(x_n+1 - xn) = 0
* soluzione trovata per  |x_n+1 - x_n| < EPSILON
*/


/*ipotesi di utilizzo: 
 funzione continua sull'intervallo, 
 derivabile due volte con continuità
 derivata prima e seconda non si annullino mai sull'intervallo
 la funzione deve avere una sola radice sull'intervallo
*/

#include <stdio.h>
#include <math.h>
#define EPSILON 1.e-5

//funzione test cos(x)
//derivata test sin(x)
int main(int argc, char const *argv[])
{
    //numero limite di stima iniziale: 
    // x_n = 0.3299 ---> diminuendo non converge. 
    // da capire il perchè


    //ipotesi di init della x_n : 
    //limite dell'intervallo se intervallo piccolo
    
    double x_n = 0.3299,  x_ns;
    int iterator=1; 
    double delta = 1.e-5; 


    do{
        printf("iterazione numero: %d\n", iterator++);

        x_ns = x_n - cos(x_n)/-sin(x_n);
        printf("valore x_n: %f\n", x_n); 
        printf("valore x_ns: %f\n", x_ns); 
        delta = fabs(x_ns - x_n); 
        x_n = x_ns;
    }

    while(delta > EPSILON);
    printf("-------------------------\n");
    printf("soluzione = %f\n", x_ns);

    return 0;
}


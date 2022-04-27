/*programma per la risoluzione di f(x)=0 col metodo
 di bisezione*/
//f(x) = cos(x)
/*
* funzionamento: 
* determina il centro dell'intervallo c_i = (a_i -b_i)/2
* valuta prodotto f(a_i)f(c_i) = p_i
* se il prodotto p_i = 0 ---> c_i è soluzione
* se il prodotto è > di 0 ---> intervallo positivo, si ricerca
                               soluzione nel sotto intervallo:
                               (c_i, b_i)
* se il prodotto è < di 0 ---> ricerca soluzione nell intervallo
                               (a_i, c_i)
*/
 #include <stdio.h>
 #include <math.h>

 #define EPSILON 1.e-3
 
 int main(int argc, char const *argv[])
 {
     
     double a=0.3, b=M_PI, c; 
     double delta = fabs(a - b); 
     int iterator = 1;

     while(delta > EPSILON){
         double p; 
         c = 0.5 * (a + b);
         p = cos(a) * cos(c);

         if (p>0.)
             a = c;
         else if (p<0.)
             b = c;
         else 
             a = b = c;
         printf("iterazione n: %d\nx = %f\n",
                iterator++, 0.5*(a+b));
         delta = fabs(a-b); 

     }
     printf("------------------------------\n");
     printf("la soluzione finale :\nx = %f\n", c);
     printf("la soluzione reale : \nx = %f\n", 0.5*M_PI);
     printf("Errore: %f\n", fabs(0.5*M_PI - c)); 
     return 0;
 }
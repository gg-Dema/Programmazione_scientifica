#include <stdio.h>
#include <stdlib.h>

#define LEN 100
int main(int argc, char const *argv[])
{
    FILE *fp; //puntatore di tipo FILE
    int i, k; 
    double x, data[LEN];

    //apertura file, scrittura numeri random 
    if ( (fp = fopen("3_pointer/random.dat", "w+")) == NULL){
        printf("ERROR In f_open\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<=LEN; i++){
        x = (double) rand() / (double) RAND_MAX; //random normalizzato 0 1
        fprintf(fp,   "%d %f\n", i, x); 
    }   
    //la seguente funzione non viene scritta all'interno del file
    //fprintf(fp, "stringa per causare errori"); ---> non sembra causare errore ma viene saltata
    fclose(fp);

    //lettura file, lettura numeri all'interno
    fp = fopen("3_pointer/random.dat", "r+") ; //r+ lettura e scrittura 
    for (i=0; i<=LEN; i++){
        fscanf(fp, "%d %lf", &k, &x); //notare che serve conoscere all'esattezza il formato del file
        *(data + (LEN - k)) = x; 
    }

    fprintf(fp, "\n*** INVERSIONE ***\n"); 
    for(i=0; i<=LEN; i++){
        fprintf(fp, "%d %lf\n", i, *(data +i-1) );
    }
    fclose(fp);

    return 0;
}

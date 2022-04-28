/*concetto base del file: OP su binari seguono sintassi diversa*/
#include <stdlib.h>
#include <stdio.h>

#define LEN 1000

int main(int argc, char const *argv[])
{
    FILE *fp; 
    int num, bytes, i, n;
    double data[LEN];
    fp = fopen("random.bin", "wb"); 
    for(i=0; i<LEN; i++){
        *(data+i) = (double)random() / (double)RAND_MAX;
    }

    bytes = sizeof(double);
    num = 100; 
    /*
    elementi della funzione fwrite:
        data+500 = primo elemento che si vuole scrivere
        bytes    = lunghezza in byte di ogni elemento da scrivere
        num      = numero di elementi da scrivere
        fp       = puntatore a file
    la fwrite scrive in binario blocchi di dati, per l'esattezza num*bytes
    n = output = numero di elementi correttemente scritti
    */
    n = fwrite(data+500; bytes, num, fp); 
    fclose(fp); 
    return 0;
}

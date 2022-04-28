#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 1000
#define MAX_FNAME 100

int main(int argc, char const *argv[])
{
    char outputFile[MAX_FNAME + 1], c; 
    FILE *fp;

    int i=0, j, n; 
    double data[MAX_NUM], temp, *lastpd, *pd, *qd; 
    //inserisco un input char by char
    printf("Inserire nome del file di output:\n"); 
    while( (c = getchar()) != '\n' && i < MAX_FNAME){
        outputFile[i++] = c; 
        //usinf getchar instead of scanf allow us to ignore the format of the input
    }
    outputFile[i++] = '\0';

    if ( (fp = fopen(outputFile, "w+")) == NULL){
        printf("Errore nell'apertura del file %s\n", outputFile);
        exit(EXIT_FAILURE); 
    }
    fprintf(fp, "**** SEQUENZA DATI ORIGINALI ****\n"); 
    for(i=0; i<MAX_NUM; i++){
        *(data + i) = (double)random() / (double)RAND_MAX; 
        fprintf(fp, "%d, %f\n", i, *(data+i)); 
    }
    fprintf(fp, "**** TERMINE DATI ORIGINALI ****\n"); 

    lastpd = data + MAX_NUM -1; //puntatore a ultimo elemento
    for (pd= data; pd < lastpd; pd++){
        for(qd=lastpd; qd>pd; qd--){
            if( *(qd-1) > *qd){
                temp = *(qd-1);
                *(qd-1) = *(qd);
                *(qd) = temp; 
            }
        }
    }
    fprintf(fp, "**** SEQUENZA DATI ORDINATi *****\n");
    for(i=0; i<MAX_NUM; i++){
        fprintf(fp, "%d, %lf\n", i, *(data+i));
        //non puoi usare pd perche ormai punta al penultimo elemento 
        //( ciclo for precedente)
    }  
    fclose(fp);
    fflush(0); //chiude tutti i file aperti, causa 0
    //alternative fflush(fp); chiude solo il file indicato da fp
    //la scrittura su file avviene solo post chiusura file

    return 0;
}

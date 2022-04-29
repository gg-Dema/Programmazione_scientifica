/*
progamma per la stampa di istogrammi in carattere ASCII
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMB 10000
#define MAX_BINS 100

int defineInput(double buf[], int max);
//-------------------------------------------------
void fillDist(double *data,  //puntatore data, array (primo elem)
              int *bin,      //array di {0} ???????????
              double min,    //min range assi isto
              double max,    //max range assi isto
              int numero_intervalli, 
              int nData);    //lunghezza array
//-------------------------------------------------
void printHisto(int *bin,    //
                int n);      // numero intervalli


int main(int argc, char const *argv[])
{
    int k, bins, entries, content[MAX_BINS] = {0};
    int seed; 
    double xmin, xmax; 
    double data[MAX_NUMB]; 
    seed = time(0); 
    srand48(seed); 

    entries = defineInput(data, MAX_NUMB); //ritorna dati in data, lunghezza in entries

    printf("dare limiti all'istogramma: \nx_min = ");
    scanf("%lf", &xmin); 
    printf("x_max = "); 
    scanf("%lf", &xmax);

    do{
        printf("Dare un numero di intervalli bins = ");
        scanf("%d", &bins);
    }while(bins <=0 || bins > MAX_BINS);

    fillDist(data, content, xmin, xmax, bins, entries);
    printHisto(content, bins);
    exit(EXIT_SUCCESS); 
}


int defineInput(double buf[], int max){
    int k, N; 
    do{
        printf("numero di eventi: ");
        scanf("%d", &N); 
    } while (N<=0 || N > max); 

    for(k=0; k<N; k++){
        buf[k] = (double)lrand48() / (RAND_MAX + 1.); 
    }
    return N;
    //il buffer si riempie in automatico (riferimento)
}


void fillDist(double *data, int *bin, double min, double max, int num_intervalli, int nData){
    int i, j; 
    double inv_ampiezza = (double) num_intervalli/ (max-min); 
    for( i=0; i<nData; i++){
        j = (( *(data+i) - min ) * inv_ampiezza); 
        if (j<num_intervalli && j >= 0) (*(bin+j))++; 
    }
    //la variabile bin diventa un contatore del numero di elementi presenti nell'intervallo
}


void printHisto(int *bin, int n){

    int i, j, bigger_interval; 
    int max_cols;
    int maxChar=100;
    char c = '*';
    char empty = ' '; 
    char hist[n+2][maxChar +1];
    //riempie la matrice di valori char empty ' '
    for(i=0; i<n; i++){
        for(j=0; j<maxChar; j++){
            hist[i][j] = empty; 
        }
    }
    //----------------------------------------------------------------
    //in questa sezione del codice si ricerca il massimo nell'array bin
    //praticamente normalizzo il tutto
    max_cols = bin[0]; 
    for(i=1; i<n; i++){
        if(bin[i] > max_cols){
            max_cols = bin[i];
            bigger_interval = i; 
        }
    }
    if (max_cols>maxChar){
        max_cols = maxChar;
    } //stampo massimo MaxChar di valori sulle y 
    //----------------------------------------------------------------
    
    for(j=0; j<=max; j++){
        hist[0][j] = '|'; 
    }

    hist[0][0] = hist[1][0] = '_'; 
    for(i=2; i<n+2; i++){
        hist[i][0] = '_';
        for(j=0; j<*(bin+i-2); j++){
            hist[i][j+1] = c;
        }
    }
    
    for(j=max; j >= 0; j--){
        for(i=0; i<n+2; i++){
            printf("%c", hist[i][j]); 
        }
        printf("\n");
    }
}
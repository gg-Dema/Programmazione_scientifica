/*
********* INTRO METODO CHI SQUARE *********
dato dataset ---> divido in K intervalli
    per ogni intervallo k_i appartenente a K --->
        cadono O_grande(k) dati
Confrontiamo distribuzione in k intervalli con quella attesa
E_k = distribuzione attesa = N*P_k 
    N = numero totale di dati
    P_k = prob dato(x) di cadere in k-esimo intervallo


DEFINISCO CHI_SQUARE
chisquare = sum( (Ogrande_k  - E_K)^2  /  E_k)
---
TUTTO SARA' SPIEGATO NEL DETTAGLIO NEL CAPITOLO VARIABILI_ALEATORIE
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 10000
#define MAX_BINS 100

int defineInput(double buf[], int max);
void fillDist(double* data, int* bin, double min, double max, int n, int nData);
double chiSquare(int *obs, double *exp, int n); 

int main(int argc, char const *argv[])
{
    int k, bins, entries, content[MAX_BINS]={0};
    int seed; 
    double xmin, xmax;
    double average = 0., chi2, data[MAX_NUM]; 
    double expected[MAX_BINS] = {0.}; 

    seed = time(0);
    srand48(seed);

    entries = defineInput(data, MAX_NUM); 
    printf("dare limiti della distribuzione\n xmin="); 
    scanf("%lf", &xmin);
    printf("xmax=");
    scanf("%lf", &xmax);

    do{
        printf("Dare numero di intervalli\n bins="); 
        scanf("%d", &bins);
    }while (bins < 0 || bins > MAX_BINS);
    
    fillDist(data, content, xmin, xmax, bins, entries);
    for(k=0; k<bins; k++){
        average += (double) content[k]; 
    }
    average /= (double)bins; 

    for(k=0; k<bins; k++){
        expected[k] = average;
    }
    chi2 = chiSquare(content, expected, bins); 
    printf("Chi2 = %f\n", chi2); 
    exit(EXIT_SUCCESS);

    return 0;
}

double chiSquare(int *obs, double *exp, int n){
    double S = 0., t1, t2; 
    int k;
    for(k=0; k<n; k++){
        t1 = (double) *(obs+k); 
        t2 = *(exp + k);
        S += (t1 - t2) * (t1 - t2) / t2; 
    }
return S; 
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


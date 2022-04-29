/*
    ritrutturazione del programma cap 2_array, numero 9
    risoluzione di un sistema lineare tramite metodo di gauss
*/

#include <stdio.h>
#include <math.h>

#define N 100

void triangle(int, double[N][N], double*); 
void solve(int, double[N][N], double*, double*);

int main(int argc, char const *argv[])
{
    double A[N][N], b[N], x[N]; 
    int n, i, j; 

    //inserimento dati manuale
    printf("inserisci il numero di equazioni (< 100) :\t"); 
    scanf("%d", &n);
    printf("\ninserire i coefficenti del sistema e i termini noti\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("A[%d, %d] : ", i, j);
            scanf("%lf", &A[i][j]); 
        }
        printf("b[%d] : ", i);
        scanf("%lf", &b[i]);
    }

    //solve the system: 
    triangle(n, A, b); 
    solve(n, A, b, x); 

    //stampa risultato: 
    for(i=0; i<n; i++){
        printf("x[%d] : %lf\n", i, x[i]); 
    }
    return 0;
}


void triangle(int n, double a[N][N], double *b){

    int i, j, k; 
    double c; //fattore di supporto

    for(i=0; i<n; i++){
        //divido i-esima equazione per primo termine (diagonale)
        c = a[i][i]; 
        //opero sulla matrice:
        for(j=i; j<n; j++){
            a[i][j] /= c; 
        }
        //opero sul vettore b
        *(b + j) /= c; 

        //sottraggo l'eq normalizzata dalle altre: 
        for (k=i+1; k<n; k++){
            c = a[k][i];
            //matrice
            for(j=i; j<n; j++){
                a[k][j] -= a[i][j]*c; 
            }
            //vettore
            *(b+k) -= c * (*(b+i)); 
        }

    }
}

void solve(int n, double a[N][N], double *b, double *x){
    int i, k; 
    double s; 
    x[n] = b[n] / a[n][n]; 
    for (k = n-1; k>=0; k--){
        s = 0.; 
        for(i=k+1; i<n; i++){
            s += a[k][i] * x[i];
        }
        x[k] = b[k] -s;
    }

}
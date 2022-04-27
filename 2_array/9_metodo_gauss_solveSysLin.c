#include <stdio.h>
#include <math.h>

#define N 100

int main(int argc, char const *argv[])
{
    double A[N][N], b[N], x[N];
    double C, S; //C elemento diagonale S solution?
    int n, i, j, k;
    //inserimento dati

    printf("inserire numero equazioni (<100)\n");
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

    //triangolazione della matrice
    for (i=0; i<n; i++){
        //divido l'iesima eq per elemento della diag C
        C = A[i][i];
        for(j=i; j<n; j++){ //j=1 aka diagonale in poi
            A[i][j] /= C; 
        } 
        b[i] /= C; 
    
    //sottrae l'eq normalizzata dalle altre
        for (k=i+1; k<n; k++){
            C = A[k][i];  //fattore da sottrarre (primo elemento)
            for (j=i; j<n; j++){
                //          riga precedente * fattore
                A[k][j] -= A[i][j] * C;
            }
            b[k] -= C * b[i];
        }
    //fine op sulla matrice A: salire i risultati in modo ricorsivo
    }
    //risolve
    for(k=n-1; k>=0; k--){
        S = 0.; 
        for(i=k+1; i<n; i++){
            S += A[k][i] * x[i];
        }
        x[k] = b[k] - S; 
    }

    //stampa risultato
    for(i=0; i<n; i++){
        printf("x[%d] = %.3lf\n", i, x[i]);
    }
    return 0;
}

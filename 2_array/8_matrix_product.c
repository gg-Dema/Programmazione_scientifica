#define ROW1 5
#define COL1 7
#define ROw2 COL1
#define COL2 4


//manca la definizione delle matrici
int main(int argc, char const *argv[])
{
    int a[ROW1][COL1], b[ROw2][COL2];
    int c[ROW1][COL2];

    int i, j, k; 
    for(i=0; i<ROW1; ++i){
        for(j=0; j<COL2, j++){
            c[i][j]=0; 
            for (k=0; k<COL1; k++){
                c += a[i][k] * b[k][j];
            }
        }
    }

    return 0;
}
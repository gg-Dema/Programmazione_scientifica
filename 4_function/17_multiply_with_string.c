#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_0 48
#define N 20


void multiply(char a[], char b[], char result[]); 

void main(){

    char a[] = {'1', '1', '\0'};
    char b[] = {'5', '2', '1', '\0'};
    char res[N] = {0}; 

    multiply(a, b, res); 
    printf("result: %s\n", res);
}


void multiply(char a[], char b[], char result[]){

    int lb = strlen(b);
    int la = strlen(a);
    int partial[N] = {0};
    int i=0, j=0, carry=0;
    int m = 1; 
    int k = N - m;

    for(i=lb-1; i>=0; i--){
        j=la-1;
        while(j>=0){

            int d1 = b[i] - ASCII_0;
            int d2 = a[j--] - ASCII_0; 
            int r = d1*d2; 
            partial[k]      += r%10; 
            partial[k-1]    += r/10; 
            k--; 
        }
        k = N - ++m; 
    }

    i=0; 
    j=0; 
    while( partial[++i] == 0){}
    for(; i<N; i++){
        result[j++] = partial[i] + ASCII_0; 
    }
    result[j] = 0; 
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 20
#define ASCII_0 48
//porgramma per il calcolo del fattoriale che tiene conto degli errori di
//rappresentazione, codificando i numeri come stringhe

void multiply(char a[], char b[], char result[]);
void factorial(char n[], char result[]);
char* intToChar(int n); 

void main(){
    char n[N/2], result[N], support_char;
    int i=0; 
    printf("inserire il numero n del fact:\t");
    while( (support_char = getchar()) != '\n' && i < N/2){
        n[i++] = support_char; 
    }
    n[i] = '\0'
    factorial(n, result);

    printf("result:\t");
    len_result = strlen(result);
    for(i=0; i<len_result; i++ ){
        printf("%c", n[i]);
    }
    
}

void mulitply(char a[], char b[], char result[]){
   
    int partial[N] = {0}; //deve essere della misura doppia di len_a + len_b +1  7
    int len_a = strlen(a);
    int len_b = strlen(b);

    char carry; 

    int i, j;
    int m = 1;
    int k = N-m; 
    for(i=len_b-1; i>=0; i--){
        j = len_a -1; 
        while( j >= 0){
            int d1 = b[i] - ASCII_0;
            int d2 = a[j--] - ASCII_0;
            int r = d1 * d2; 
            partial[k] += r%10; 
            if (partial[k] > 9){
                carry = partial[k]/10; 
                partial[k] %= 10;
            }
            partial[k-1] += r/10 + carry; 
            k--; 
        }
        k = N - ++m;
    }

    //retur to string style:
    i = j = 0; 
    //formato partial = [ 0 0 0 0 0 0 0 0 0 0 s o m e _ N u m b]
    while(partial[++i] == 0){ 
        //non fa nulla, serve solo a trovare la fine della parte pari a 0
    }
    for(; i<N; i++){//restanti i = char dei numeri utili
        result[j++]=partial[i] + ASCII_0; 
    }
    result[j] = 0; //fine stringa 
}

char* intToChar(int n){
    int len_n = log10(n) + 1; 
    char* c = malloc( (sizeof(char) * len_n) );  
    while(n!=0){
        *(c + len_n--) = n%10 + '0';
        n /= 10;
    }
    return c; 
}

int factorial(int n){
    

    char *char_n = intToChar(n);
    char *result_copy = intoToChar(n--);
    char *result;
    multiply(char_n, result_copy, result);

    for( ; n>=0; n--){
        char_n = intToChar(n); 
        //deep copy
        for(int i=0; i<N; i++){
            result_copy[i] = result[i];
        }
        multiply(char_n, result_copy, result);
    }
}

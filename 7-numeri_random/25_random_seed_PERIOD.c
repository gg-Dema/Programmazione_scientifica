#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_M 1024
typedef long int RANDOM_TYPE; 

int main(void)
{
    long int i, j, successFlag; 
    RANDOM_TYPE a, b, m, seed, randomNumber, randomStore[MAX_M+1]; 
    a = 6;
    b = 6;
    m = 10; 
    seed = 2; 


    seed %= m;
    printf("a=%ld\nb=%ld\nm=%ld\nI_0=%ld\n", a, b, m, seed);
    randomNumber=seed; 
    randomStore[0] = randomNumber; 

    if(m>MAX_M) {
        printf("ERROR: m too big\n"); 
        exit(EXIT_FAILURE);
    } 
    i = 1; 
    successFlag = 0; 
    while( (i<=m) && (successFlag==0) ){
        randomNumber = (a * randomNumber + b) % m; 
        randomStore[i] = randomNumber; 
        j = 0; 
        do {
            if(randomStore[j] == randomNumber){
                successFlag = 1; 
                printf("Done: T=%ld\n", i-j); 
            }
            j++;
        }
        while( ( i < j) && (randomStore[j -1] != randomNumber));
        i++;
    }

    if(successFlag == 1){
        exit(EXIT_SUCCESS);
    }
    else if(successFlag == 0){
        printf("ERROR: (danger) : T not found");
        exit(EXIT_FAILURE);
    }
}

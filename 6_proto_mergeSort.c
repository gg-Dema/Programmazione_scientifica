/*
* scrivere un programma che ordini due array, 
*infine li unisca in un terzo array ordinato
*/

#include <stdio.h>
#define len 3


int main(int argc, char const *argv[])
{
    int data_1[len] = {2, 5, 0};
    int data_2[len] = {3, 1, 6};
    int data_3[len*2]; 
    int temp; 

    //ordina primo array: 
    for(int i=0; i<len-1; i++){
        int change = 0;
        for(int j=len-1; j>i; j--){
            if (data_1[j-1]>data_1[j]){
                temp = data_1[j-1];
                data_1[j-1] = data_1[j];
                data_1[j] = temp;
                change = 1;
            }
        }
        if (!change)
            break;
    }
    for(int i=0; i<len; i++){
        printf("data_1[%d]: %d\n", i, data_1[i] );
    }
    printf("_____________________\n");

    //ordino secondo array
        for(int i=0; i<len-1; i++){
        int change = 0;
        for(int j=len-1; j>i; j--){
            if (data_2[j-1]>data_2[j]){
                temp = data_2[j-1];
                data_2[j-1] = data_2[j];
                data_2[j] = temp;
                change = 1;
            }
        }
        if (!change)
            break;
    }

    for(int i=0; i<len; i++){
        printf("data_2[%d]: %d\n", i, data_2[i] );
    }
    printf("_____________________\n");


    //merge
    int min_index_1 = 0;
    int min_index_2 = 0;

    for(int i=0; i<len*2; i++){
        //problema: i dati sono dichiarati contigui, se accedo a data_1[3] ottengo data_1[4] ---> il confronto sforta quando un index è esaurito
        printf("confronto tra (data1 e data2): %d e %d\n", data_1[min_index_1], data_2[min_index_2]);
        if(data_1[min_index_1] > data_2[min_index_2]){
            data_3[i] = data_2[min_index_2];
            if (min_index_2 < len-1) //evita lo sforo
                min_index_2++;
        }
        else{
            data_3[i] = data_1[min_index_1];
            if(min_index_1 < len-1) //evita lo sforo
                min_index_1++;
        }
              
    }
    printf("add last elem\n");//not the minor
    data_3[(len*2)-1] = (data_1[len-1]>data_2[len-1]) ? data_1[len]: data_2[len-1];
        
    for(int i=0; i<len*2; i++){
        printf("data_3[%d]: %d\n", i, data_3[i] );
    }
    return 0;
}

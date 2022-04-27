#include <stdio.h>
#define LEN 10

int main(int argc, char const *argv[])
{
    int end=LEN-1, start=0, middle;
    int target= 2, found=0;

    int data[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    do{
        middle = (int) (end+start)/2;
        if (data[middle]==target){
            found=1; 
        }
        else if(data[middle] < target){
            start = middle+1;
        }
        else{
            end = middle-1;
        }
    }while(!found && end >= start); //notare !found messo prima di end. 
    // Questo permette di verificare
    // sempre prima se la ricerca ha avuto fine
    // al contrario (end>=start && !found) è vera si dovrà comunque fare il
    // confronto sul found. é solo un confronto ma nell'ottica della memoria è utile

    if (found==1)
        printf("trovato il numero cercato alla posizione %d\n", middle+1); 
    else{
        printf("non l'ho trovato\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
    int data[] = {1, 5, 2, 3, 4, 6, 7};
    int temp; 
    int size = sizeof(data)/sizeof(data[0]);
    
    int num_op = 0; 
    printf("size: %d\n",size);
    for (int i=0; i<size-1; i++){
        // by book  (decrescente)
        //for(int j=size-1; j>i; j--){
        // by my    (crescente)
        for(int j=1; j<size-i; j++){    //se metto j< size ottengo un paio di run extra
            num_op++;
            if (data[j-1] > data[j]){
                temp = data[j-1];
                data[j-1] = data[j];
                data[j] = temp;   
            }
        }

    }

    for (int k=0; k<size; k++)  
        printf("data[%d]: %d\n", k, data[k] );
    printf("\n");            
    printf("check nump_op: %d\n", num_op);

}


 
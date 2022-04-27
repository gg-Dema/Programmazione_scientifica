#include <stdio.h>
#define len 6

void print_array(int a[]);

int main(int argc, char const *argv[])
{
    int data[len]={3, 4, 2, 0, 5, 1};
    printf("original array:\n");
    print_array(data);
    int temp; 

    for(int i=0; i<len-1; i++){
        for(int j=len-1; j>i; j--){
            printf("j=%d\nj-1=%d\ni=%d\nsto confrontando j(%d) con j-1(%d):\n", j, j-1, i, j, j-1);
            printf("valori interessati = %d (-1) é maggiore di %d?\n", data[j-1], data[j]);
            if(data[j-1] > data[j]){
                temp = data[j-1];
                data[j-1] = data[j];
                data[j] = temp;

            }
            printf("array attuale:\n");
            print_array(data);
            printf("....................\n");
        }
        break;
    }


    return 0;
}


void print_array(int a[]){
    for(int i=0; i<len; i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

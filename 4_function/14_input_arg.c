/*test for argc argv */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    //argc = intero, numero di stringe di caratteri trasmesse al programma +1
    //                AKA numero di argomenti e parametri ( flag e valori contano)
    //argv contiene array di *pointer a stringhe: 1 valore per ogni input
    printf("argc: %d\n", argc);
    printf("nome file: %s\n", argv[0]);
    printf("primo parametro: %s, primo valore %s\n", argv[1], argv[2]); 
    return 0;
}

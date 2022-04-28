/* modificare file 11 in modo che sia possibile conservare passi intermedi dell'algoritmo. 
*  utilizzare un file d'appoggio in cui ogni numero venga sostituito con il corrispettivo simbolo.
*  Usare range per definire simboli : 
*   x < 0.25            = -
*   0.25 <= x < 0.5     = + 
*   0.5 <= x < 0.75     = *
*   0.75 <= x           = /
*  Salvare lo stato dell'array ogni K passi
*/


 #include <stdio.h>
 #include <stdlib.h>

int main(int argc, char const *argv[])
{
    const int log_step = 100; 
    const int MAX_FILE_NAME =  100;
    const int MAX_NUM = 1000;

    char output_file[MAX_FILE_NAME +1], support_file[MAX_FILE_NAME+1];
    FILE *output_fp, *support_fp; 

    double data[MAX_NUM];
    double *data_p, *last_elem_p, *sort_p; 

    //apertura file base
    
    printf("inserire nome del file di output: \n");
    char c; 
    int i = 0; 
    while( (c = getchar()) != '\n' && i < MAX_FILE_NAME){
        output_file[i++] = c; 
    }
    output_file[i++] = '\0';
    
    printf("Apertura file: "); 
    if( (output_fp = fopen(output_file, "w+")) == NULL){
        printf("ERROR file not found\n");
        exit(EXIT_FAILURE);
        }
    else{
        printf("file  %s aperto correttamente\n", output_file);
        }
    
    //scrittura dati originali:
    fprintf(output_fp, "**** SEQUENZA DATI ORIGINALI ****\n"); 
    for(i=0; i<MAX_NUM; i++){
        *(data + i) = (double)random() / (double)RAND_MAX; 
        fprintf(output_fp, "%d, %f\n", i, *(data+i)); 
    }
    fprintf(output_fp, "**** TERMINE DATI ORIGINALI ****\n"); 
    
    //apertura file di supporto
    printf("inserire nome del file di supporto: \n"); 
    i=0;//restart counter (con la scrittura di prima accedevo ad aree di memoria a me non concesse)
    while( (c = getchar()) != '\n' && i < MAX_FILE_NAME){
        support_file[i++] = c; 
    }
    support_file[i++] = '\0';

    printf("Apertura file: "); 
    if( (support_fp = fopen(support_file, "w+")) == NULL){
        printf("ERROR file not found\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("file aperto correttamente\n");
    }

    printf("inizio ordinamento\n");
    int log_counter = 0;
    float temp;
    last_elem_p = data + MAX_NUM -1; 
    for (data_p=data; data_p < last_elem_p; data_p++){
        for(sort_p=last_elem_p; sort_p>data_p; sort_p--){
            if( *(sort_p-1) > *sort_p){
                temp = *(sort_p-1);
                *(sort_p-1) = *(sort_p);
                *(sort_p) = temp; 
            }
        }
        if ((++log_counter % log_step) == 0){
            printf("LOG_SAVE ITER %d\n", log_counter);
            fprintf(support_fp, "*** save numb %d ***\n", log_counter/100);
            char support_symbol; 
           
            for(i=0; i<MAX_NUM; i++){
                if( *(data+i) > 0.75 ){
                    support_symbol = '/';
                }
                else if( *(data+i) <= 0.75 && *(data+i) > 0.50){
                    support_symbol = '*';
                }
                else if ( *(data+i) <= 0.50 && *(data+i) > 0.25){
                    support_symbol = '-';
                }
                else if ( *(data+i) <= 0.25){
                    support_symbol = '+';
                }
                else{
                    support_symbol = 'E'; 
                }
                fprintf(support_fp, "%d %c\n", i, support_symbol); 
            }
        }
    
    }
    printf("ordinamento concluso\n"); 
    printf("chiusura file di supporto\n");
    fclose(support_fp);

    printf("scrittura dati ordinati\n");
    fprintf(output_fp, "****DATI ORDINATI****\n"); 
    for(i=0; i<MAX_NUM; i++){
        fprintf(output_fp, "%d, %f\n", i, *(data+i)); 
    }

    printf("dati scritti con successo, chiusura file e terminazione\n");
    fflush(0);




    return 0;
}


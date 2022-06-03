#include <stdio.h>


double myReadDouble(char *printMessage); 
int myReadInt(char *printMessage); 


double myReadDouble(char *printMessage){
    double d; 
    printf("%s\n", printMessage);
    fflush(stdout);
    scanf("%lf", &d);
    return d; 
}
double myReadInt(char *printMessage){
    int x;
    printf("%s\n", printMessage);
    fflush(stdout);
    scanf("%d", &x);
    return x; 
}
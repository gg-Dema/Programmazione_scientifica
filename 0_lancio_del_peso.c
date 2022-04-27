#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define G 9.82

int main(int argc, char const *argv[])
{
    double t = 0;           //time
    double theta;           // angolo di lancio
    double v0, v0x, v0y;    //velocità iniziale
    double xt, yt, vx, vy;  //cordinate finali, velocità finale
    
    printf("angolo lancio in radianti: ");
    scanf("%lf", &theta); 
    printf("velocità iniziale: "); 
    scanf("%lf", &v0); 
    printf("tempo t: ");
    scanf("%lf", &t);

    /*calc componenti v0*/
    v0x = v0*cos(theta);
    v0y = v0*sin(theta);
    
    /*calc velocità post t sec*/
    vx = v0x;
    vy = v0y - G*t;


    /*calc cordinante*/
    xt = vx * t; 
    yt = v0y * t - 0.5 * G * pow(t, 2.0);
    printf("cordinate:\nx: %lf, y:%lf \n", xt, yt);

    exit(0);
}

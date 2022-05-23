#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#define L_volume_cube 2
#define R_volume_sphere 1
#define NUM_SAMPLE 1e7
#define PI 3.14

double volume_sphere(double radius); 

int main(int argc, char const *argv[])
{
    srand48(5);

    double x, y, z, result; 
    int i = 0, k = 0; 
    for(; i<NUM_SAMPLE; i++){

        //genera numeri casuali
        x = L_volume_cube * (double)lrand48() / RAND_MAX;
        y = L_volume_cube * (double)lrand48() / RAND_MAX;
        z = L_volume_cube * (double)lrand48() / RAND_MAX;

        //controlla area e somma i casi
        if( (x*x + y*y + z*z) < (R_volume_sphere*R_volume_sphere) ){
            k++;
        }
    }
    double volume_cube = (L_volume_cube*L_volume_cube*L_volume_cube);
    result = volume_cube * (double) k / NUM_SAMPLE;
    printf("il volume della sfera che interseca il cubo è pari a %.3f\n", result); 
    //calc originale: 1/8 * 4/3 PI R_sphere^3; 
}

double volume_sphere(double radius) {
    double r_3 = radius*radius*radius;
    return (4*PI*r_3)/3;

}
#include <stdio.h>
#include <stdlib.h> //EXIT_F/S
#include "24_integration_method.c"
#include "24_harmonic_oscillator.c"
#include "24_utils.c"

#define EULER 0 
#define EULER_CROMER 1


int main(void){
    
    double x0, v0, dt, omega_square, totalTime; 
    double energy0, energy_new_step; 
    int steps, algorithm, i; 
    phaseSpace xAndV;

    printf("integrazione dell'oscillatore armonico\n"); 
    totalTime = myReadDouble("Inserire il tempo totale di integrazione\n");
    algorithm = myReadInt("inserire 1 per metodo euler_cromer\n0 per classic euler\n");
    dt = myReadDouble("inserire intervallo dt\n");
    x0 = myReadDouble("inserire posizione iniziale x0\n");
    v0 = myReadDouble("inserire velocita iniziale v0\n");
    omega_square = myReadDouble("inserire omega -square (K/m)\n");
    steps = (int) (totalTime / dt + 0.5); 
    printf("dt = %g tempo tolate = %g\n", dt, totalTime); 
    printf("omega_square = %f numero passi = %d\n", omega_square, steps);

    xAndV = initXandV(x0, v0); 
    printf("condizioni iniziali: \n"); 
    energy0 = energy(omega_square, xAndV);


    if(algorithm == EULER){
        printf("metodo eulero classic\n");
        printf("time, x, v, deltaEnergy");
        for(i=1; i<=steps; ++i){
            xAndV = euler(dt, omega_square, xAndV, forceHarmonicOscillator);
            energy_new_step = energy(omega_square, xAndV);
            printf("%.3lf %.3lf %.3lf %.3lf\n", 
                    (double) i*dt, xAndV.x, xAndV.v, energy_new_step - energy0 ); 
        }
    }
    else if (algorithm == EULER_CROMER){
        printf("metodo euler-cromer\n");
        printf("time, x, v, deltaEnergy");
        for(i=1; i<=steps; ++i){
            xAndV = *eulerCromer(dt, omega_square, xAndV, forceHarmonicOscillator);
            energy_new_step = energy(omega_square, xAndV);
            printf("%.3lf %.3lf %.3lf %.3lf\n", 
                    (double) i*dt, xAndV.x, xAndV.v, energy_new_step - energy0 ); 
        }
    }
    else{
        printf("algoritmo numero %d non ancora impelementato, sorry\n", algorithm); 
        exit(EXIT_FAILURE); 
    }
    
    printf("integrazione finita\ntime T || energy(T)\n");
    printf("%.3lf, %.3lf", (double)i*dt, energy(omega_square, xAndV));
    exit(EXIT_SUCCESS);
}

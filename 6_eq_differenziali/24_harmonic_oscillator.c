#include "24_harmonic_oscillator.h"


double energy(double omega_square, phaseSpace xAndV){
    double localEnergy; 
    localEnergy = 0.5 * xAndV.v *xAndV.v +\
                    potentialHarmonicOscillator(omega_square, xAndV.x);
    return localEnergy;

}
double forceHarmonicOscillator(double omega_square, double x){
    return -omega_square * x;
}
double potentialHarmonicOscillator(double omega_square, double x){
    return 0.5 * omega_square * x * x; 
}

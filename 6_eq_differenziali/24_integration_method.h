#pragma once

typedef struct phaseSpace{
    double x; 
    double v; 
} phaseSpace;

phaseSpace initXandV(double x0, double v0); 
phaseSpace euler(double dt, double omega_square, phaseSpace xAndv, double (*forceOfSystem)(double, double)); 
phaseSpace* eulerCromer(double dt, double omega_square, phaseSpace xAndv,  double (*forceOfSystem)(double, double));

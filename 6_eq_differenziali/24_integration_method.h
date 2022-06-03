#pragma once

typedef struct phaseSpace{
    double x; 
    double v; 
};

phaseSpace initXandV(double x0, double v0); 
phaseSpace euler(double dt, double omega_square, phaseSpace xAndv); 
phaseSpace* eulerCromer(double dt, double omega_square, phaseSpace xAndv);

#include <stdlib.h>
#include "24_integration_method.h"


phaseSpace initXandV(double x0, double v0){
     phaseSpace xAndV  = {.x=x0, .v=v0};
    return xAndV;
}

phaseSpace euler(double dt,
                 double omega_square,
                 phaseSpace xAndV_old,
                 double (*forceOfSystem)(double, double)){
    phaseSpace xAndV_new; 
    xAndV_new.v = xAndV_old.v + forceOfSystem(omega_square, XandV_old.x) * dt;
    xAndV_new.x = xAndV_old.x + xAndV_old.v * dt; 
    return xAndV_new; 
}


phaseSpace* eulerCromer(double dt,
                        double omega_square,
                        phaseSpace xAndV_old,
                        double (*forceOfSystem)(double, double)){
    static phaseSpace xAndV_new; 
    xAndV_new.v = xAndV_old.v + forceOfSystem(omega_square, xAndV_old.x)*dt; 
    xAndV_new.x = xAndV_old.x + xAndV_new.v * dt; 
    return &xAndV_new;
}

#ifndef simpi
#define simpi

#include "mt19937ar.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double sim_pi(unsigned long n);
double moyenne_sim_pi(unsigned long n, int nb_exp);
double moyenne_sim_pi_conf(unsigned long n, int nb_exp, float alpha);



#endif